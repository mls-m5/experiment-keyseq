//============================================================================
// Name        : keyseq.cpp
// Author      : Mattias Larsson Sköld
// Version     :
// Copyright   : Copyright
// Description : Hello World in C, Ansi-style
//============================================================================

#include <SDL/SDL.h>
#include <GL/gl.h>
#include "Sequencer.h"
#include "KeyMap.h"
#include "visualkeyboard.h"

SDL_Surface *screen;
Sequencer* sequencer;
KeyMap keymap("map.txt");

void PollEvents();

bool Running = 0;
VisualKeyboard vkeyboard;

void Render(){
	glClear(GL_COLOR_BUFFER_BIT);
	vkeyboard.draw();
	SDL_GL_SwapBuffers();
}

int main(void){


	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(100,25,0,
			SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);
	SDL_WM_SetCaption("keyseq", 0);

	Running = true;
	sequencer = new Sequencer;

	Render();

	while(Running) {
		SDL_Delay(10);
		PollEvents();
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}

void PollEvents() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT){
			Running = 0;
		}
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE){
				Running = 0;
			}
			else
			{
				printf("%d\n", event.key.keysym.sym);
				int key = keymap.Translate(event.key.keysym.sym);
				sequencer->NoteOn(key, 100);
				vkeyboard.sendNote(key, 1);
				Render();
			}


		}
		else if (event.type == SDL_KEYUP){
			auto key = keymap.Translate(event.key.keysym.sym);
			sequencer->NoteOff(key, 100);
			vkeyboard.sendNote(key, 0);
			Render();
		}
	}

}

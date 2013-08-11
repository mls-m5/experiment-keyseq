//============================================================================
// Name        : keyseq.cpp
// Author      : Mattias Larsson Sköld
// Version     :
// Copyright   : Copyright
// Description : Hello World in C, Ansi-style
//============================================================================

#include <SDL/SDL.h>
#include "Sequencer.h"
#include "KeyMap.h"

SDL_Surface *screen;
Sequencer* sequencer;
KeyMap keymap("map.txt");

void PollEvents();

bool Running = 0;

int main(void){


	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(200,200,0,
			SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);
	SDL_WM_SetCaption("keyseq", 0);

	Running = true;
	sequencer = new Sequencer;

	while(Running) {

//		for (int i = 0; i < 2; ++i){
//			Update();
//		}
//		Render();


		//Backend::Wait(TICK_INTERVAL);

		SDL_Delay(10);
		PollEvents();
	}

	//Cleanup();
	SDL_Quit();

	return EXIT_SUCCESS;
}

void PollEvents() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT){
//			app->Cleanup();
			Running = 0;
		}
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE){
//				app->Cleanup();
				Running = 0;
			}
//			else if(event.key.keysym.sym == SDLK_F5){
//				SDL_WM_ToggleFullScreen(screen);
//			}
			else
			{
				printf("%d\n", event.key.keysym.sym);
//				app->OnKeyEvent(getHardwareToControlNumber(&event.key), 1);
				sequencer->NoteOn(keymap.Translate(event.key.keysym.sym), 100);
			}


		}
		else if (event.type == SDL_KEYUP){
//			app->OnKeyEvent(getHardwareToControlNumber(&event.key), -1);
			sequencer->NoteOff(keymap.Translate(event.key.keysym.sym), 100);
		}
	}

}

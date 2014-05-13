/*
 * visualkeyboard.cpp
 *
 *  Created on: 13 maj 2014
 *      Author: mattias
 */

#include "visualkeyboard.h"
#include <GL/gl.h>

VisualKeyboard::VisualKeyboard() {
	for (int i = 0; i < 12; ++i){
		notes[i] = 0;
	}
}

VisualKeyboard::~VisualKeyboard() {
}

void VisualKeyboard::draw() {
	glPushMatrix();
	glTranslatef(-1, 0,0);
	glScalef(1. / 12. * 2, 2. * 2./3, .1);
	for (int i = 0; i < 12; ++i){
		glPushMatrix();
		glTranslated(i, 0,0);

		auto c = 1. - notes[i] * .7;
		switch (i){
		case 1:
		case 3:
		case 6:
		case 8:
		case 10:
			glColor3f(c, c / 2, c / 2);
			break;
		default:
			glColor3f(c, c, c);
		}
		glBegin(GL_QUADS);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glVertex2f(1,1);
		glVertex2f(1,0);
		glEnd();


		glColor3f(0, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex2d(0,0);
		glVertex2d(0,1);
		glEnd();

		glPopMatrix();
	}
	glPopMatrix();
}

void VisualKeyboard::sendNote(int note, double value) {
	notes[note % 12] = value;
}

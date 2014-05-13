/*
 * visualkeyboard.h
 *
 *  Created on: 13 maj 2014
 *      Author: mattias
 */

#ifndef VISUALKEYBOARD_H_
#define VISUALKEYBOARD_H_

class VisualKeyboard {
public:
	VisualKeyboard();
	virtual ~VisualKeyboard();

	void draw();
	void sendNote(int note, double value);


	double notes[12];
};

#endif /* VISUALKEYBOARD_H_ */

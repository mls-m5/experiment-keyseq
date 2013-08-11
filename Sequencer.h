/*
 * Sequencer.h
 *
 *  Created on: 29 apr 2013
 *      Author: mattias
 */

#ifndef SEQUENCER_H_
#define SEQUENCER_H_

#define MAX_MIDI_PORTS 1

#include <alsa/asoundlib.h>

class Sequencer {
public:
	Sequencer();
	virtual ~Sequencer();
	void SendEvent(snd_seq_event_t *ev);
	void NoteOn(int note, int vel);
	void NoteOff(int note, int vel);

private:
	snd_seq_t *seq_handle;
	int out_ports[MAX_MIDI_PORTS];
	bool open = false;
};

#endif /* SEQUENCER_H_ */

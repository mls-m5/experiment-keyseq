/*
 * Sequencer.cpp
 *
 *  Created on: 29 apr 2013
 *      Author: mattias
 */

#include "Sequencer.h"

Sequencer::Sequencer() {
	open = false;

	  int l1;
	  char portname[64];

//	  if (snd_seq_open(&seq_handle, "default", SND_SEQ_OPEN_DUPLEX, 0) < 0) {
	 if (snd_seq_open(&seq_handle, "default", SND_SEQ_OPEN_OUTPUT, 0) < 0) {
	    fprintf(stderr, "Error opening ALSA sequencer.\n");
	    return;
	  }
	  snd_seq_set_client_name(seq_handle, "keyseqapa");
//	  for (l1 = 0; l1 < num_in; l1++) {
//	    sprintf(portname, "MIDI Router IN %d", l1);
//	    if ((in_ports[l1] = snd_seq_create_simple_port(*seq_handle, portname,
//	              SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE,
//	              SND_SEQ_PORT_TYPE_APPLICATION)) < 0) {
//	      fprintf(stderr, "Error creating sequencer port.\n");
//	      return;
//	    }
//	  }
	  for (l1 = 0; l1 < MAX_MIDI_PORTS; l1++) {
	    sprintf(portname, "MIDI Router OUT %d", l1);
	    if ((out_ports[l1] = snd_seq_create_simple_port(seq_handle, portname,
	              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
	              SND_SEQ_PORT_TYPE_APPLICATION)) < 0) {
	      fprintf(stderr, "Error creating sequencer port.\n");
	      return;
	    }
	  }

	  open = true;
}

Sequencer::~Sequencer() {
}

void Sequencer::SendEvent(snd_seq_event_t *ev)
{
	snd_seq_ev_set_direct(ev);
    snd_seq_ev_set_subs(ev);
    snd_seq_ev_set_source(ev, out_ports[0]);
    snd_seq_event_output(seq_handle, ev);
    snd_seq_drain_output(seq_handle);

    snd_seq_ev_clear(ev);
//    printf("sendevent");
}

void Sequencer::NoteOn(int note, int vel) {
	snd_seq_event_t ev;
	snd_seq_ev_clear(&ev);
	snd_seq_ev_set_noteon(&ev, 0, note, vel);
	SendEvent(&ev);

	snd_seq_free_event(&ev);

	printf("noteon %d\n", note);
}

void Sequencer::NoteOff(int note, int vel) {
	snd_seq_event_t ev;
	snd_seq_ev_clear(&ev);
	snd_seq_ev_set_noteoff(&ev, 0, note, vel);
	SendEvent(&ev);

	snd_seq_free_event(&ev);

//	printf("noteoff\n");
}



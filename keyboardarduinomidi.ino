#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define CLOCK 6
#define DATA 7

uint16_t prev = 0xF0;
uint16_t lastplayed = 0xF0;
int octave = 1;

void setup()
{
	MIDI.begin(MIDI_CHANNEL_OFF);
	pinMode(CLOCK, INPUT);
	pinMode(DATA, INPUT);
}

void doh(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(12 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(12 + 12 * mult, 0, 1);
	}
}

void reb(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(13 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(13 + 12 * mult, 0, 1);
	}
}

void re(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(14 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(14 + 12 * mult, 0, 1);
	}
}

void mib(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(15 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(15 + 12 * mult, 0, 1);
	}
}

void mi(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(16 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(16 + 12 * mult, 0, 1);
	}
}

void fa(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(17 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(17 + 12 * mult, 0, 1);
	}
}

void solb(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(18 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(18 + 12 * mult, 0, 1);
	}
}

void sol(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(19 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(19 + 12 * mult, 0, 1);
	}
}

void lab(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(20 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(20 + 12 * mult, 0, 1);
	}
}

void la(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(21 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(21 + 12 * mult, 0, 1);
	}
}

void sib(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(22 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(22 + 12 * mult, 0, 1);
	}
}

void si(bool onoff, int mult)
{
	if (onoff == true)
	{
		MIDI.sendNoteOn(23 + 12 * mult, 127, 1);
	}
	else if (onoff == false)
	{
		MIDI.sendNoteOff(23 + 12 * mult, 0, 1);
	}
}

void loop()
{
	uint16_t curr = 0x0;
	for (int i = 0; i < 11; i++)
	{
		while (digitalRead(CLOCK))
			;
		curr |= digitalRead(DATA) << i;
		while (!digitalRead(CLOCK))
			;
	}
	curr >>= 1;
	curr &= 0xFF;

	if (curr != 0xF0 && prev != 0xF0 && curr != lastplayed)
	{

		switch (curr)
		{
		case 0x70:
			octave = 0;
			break;
		case 0x69:
			octave = 1;
			break;
		case 0x72:
			octave = 2;
			break;
		case 0x7A:
			octave = 3;
			break;
		case 0x6B:
			octave = 4;
			break;
		case 0x73:
			octave = 5;
			break;
		case 0x74:
			octave = 6;
			break;
		case 0x6C:
			octave = 7;
			break;
		case 0x75:
			octave = 8;
			break;
		case 0x1A:
			doh(true, octave);
			break;
		case 0x1B:
			reb(true, octave);
			break;
		case 0x22:
			re(true, octave);
			break;
		case 0x23:
			mib(true, octave);
			break;
		case 0x21:
			mi(true, octave);
			break;
		case 0x2A:
			fa(true, octave);
			break;
		case 0x34:
			solb(true, octave);
			break;
		case 0x32:
			sol(true, octave);
			break;
		case 0x33:
			lab(true, octave);
			break;
		case 0x31:
			la(true, octave);
			break;
		case 0x3B:
			sib(true, octave);
			break;
		case 0x3A:
			si(true, octave);
			break;
		}
		lastplayed = curr;
	}
	if (prev == 0xF0)
	{
		switch (curr)
		{
		case 0x1A:
			doh(false, octave);
			break;
		case 0x1B:
			reb(false, octave);
			break;
		case 0x22:
			re(false, octave);
			break;
		case 0x23:
			mib(false, octave);
			break;
		case 0x21:
			mi(false, octave);
			break;
		case 0x2A:
			fa(false, octave);
			break;
		case 0x34:
			solb(false, octave);
			break;
		case 0x32:
			sol(false, octave);
			break;
		case 0x33:
			lab(false, octave);
			break;
		case 0x31:
			la(false, octave);
			break;
		case 0x3B:
			sib(false, octave);
			break;
		case 0x3A:
			si(false, octave);
			break;
		}
		lastplayed = 0x0;
		prev = 0x0;
	}
	prev = curr;
}

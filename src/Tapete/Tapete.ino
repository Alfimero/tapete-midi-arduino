#define BT 9
#include "MIDIUSB.h"

int Botones[BT];
int BotonesA[BT];
int Vel = 0;

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < BT; i++) {
    pinMode(i + 2, INPUT);
  }
}

void loop() {
  for (int i = 0; i < BT; i++) {
    Botones[i] = digitalRead(i + 2);

    if (Botones[i] != BotonesA[i]) {
      if (Botones[i] == 1) {
        // channel 5 is zero-based here, which most DAWs display as MIDI channel 6
        noteOn(5, i + 4, 120);
        MidiUSB.flush();
        delay(5);
      } else {
        noteOff(5, i + 4, 0);
        MidiUSB.flush();
        delay(5);
      }
    }

    BotonesA[i] = Botones[i];
  }
}

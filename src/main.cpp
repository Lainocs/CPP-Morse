#include <Arduino.h>
#include <PikBtLib.h>
#include <TextToMorse.h>
#include <MorseToText.h>

PikBt Bt = PikBt();

String message;

void setup() {
  digitalWrite(BUZZER, HIGH);
  Serial.begin(9600);
  Bt.Init("Morze");
  printf("Bluetooth initialized\n");
  pinMode(BUZZER, OUTPUT);
  point();
  pinMode(write_button,INPUT_PULLUP);
  pinMode(next_button,INPUT_PULLUP);
  morse_result = "";
}

void loop() {
  if(Bt.Available()){
    String msg = Bt.ReadCommand();
    Serial.println(msg);
    translateToMorse(msg);
  }

  next_buttonState = digitalRead(next_button);
  write_buttonState = digitalRead(write_button);

  if (next_buttonState != next_lastButtonState) {
     next_updateState();
  }

  if (write_buttonState != write_lastButtonState) {
     write_updateState();
  }

  next_lastButtonState = next_buttonState;
  write_lastButtonState = write_buttonState;
}

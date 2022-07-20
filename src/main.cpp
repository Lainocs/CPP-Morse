#include <Arduino.h>
#include <PikBtLib.h>
#include <TextToMorse.h>

PikBt Bt = PikBt();

String message;

void setup() {
  Serial.begin(9600);
  Bt.Init("Morse");
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if(Bt.Available()){
    String msg = Bt.ReadCommand();
    Serial.println(msg);
    translate(msg);
  }
  delay(100);
}
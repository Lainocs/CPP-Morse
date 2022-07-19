#include <Arduino.h>
#include <PikBtLib.h>

PikBt Bt = PikBt();
#include <PikControlMatrixLib.h>

PikControlMatrix8x8 matrix(21);

int BUZZER = 22;
int display_info = 21;
String message;
int freq = 250;
const int temps = 250;


void tiret(){
  digitalWrite(BUZZER, HIGH);
  matrix.GenerateSquarre(4,2,1,250,130,10);
  matrix.GenerateSquarre(4,3,1,250,130,10);
  matrix.GenerateSquarre(4,4,1,250,130,10);
  matrix.GenerateSquarre(4,5,1,250,130,10);
  matrix.GenerateSquarre(4,6,1,250,130,10);
  matrix.GenerateSquarre(4,7,1,250,130,10);
  matrix.GenerateSquarre(3,2,1,250,130,10);
  matrix.GenerateSquarre(3,3,1,250,130,10);
  matrix.GenerateSquarre(3,4,1,250,130,10);
  matrix.GenerateSquarre(3,5,1,250,130,10);
  matrix.GenerateSquarre(3,6,1,250,130,10);
  matrix.GenerateSquarre(3,7,1,250,130,10);
  delay(3*temps);
  matrix.Clear();
  digitalWrite(BUZZER, LOW);
  delay(temps);
}

void askName() {
  // prompt user for message and set it to message
}


void point(){
  digitalWrite(BUZZER, HIGH);
  matrix.GenerateSquarre(2,3,1,250,130,10);
  matrix.GenerateSquarre(2,3,2,250,130,10);
  matrix.GenerateSquarre(2,3,3,250,130,10);
  matrix.GenerateSquarre(2,3,4,250,130,10);
  delay(temps);
  matrix.Clear();
  digitalWrite(BUZZER, LOW);
  delay(temps);
}

void morse(String msg) {
  //Serial.println(msg);
  //Serial.print(String(msg.length()));
  for(int i = 0; i<msg.length(); i++) {
    if (msg.substring(i, i+1) == "-") {
      Serial.print("-");
      tiret();
    }
    else if (msg.substring(i, i+1) == ".") {
      Serial.print(".");
      point();
    }
    else if (msg.substring(i, i+1) == ";") {
      Serial.print(" ");
      delay(3*temps);
    }
    else if (msg.substring(i, i+1) == "|") {
      Serial.print("   ");
      delay(7*temps);
    }
  }
}

void setup() {
  Serial.begin(9600);
  Bt.Init("Morse");
  pinMode(BUZZER, OUTPUT);
}

void translate(String message) {
  digitalWrite(display_info, HIGH);

  message.toUpperCase();

  int word_size = message.length();

  message.replace(".",".-.-.-;");
  message.replace("-","-....-;");
  message.replace("A",".-;");
  message.replace("B","-...;");
  message.replace("C","-.-.;");
  message.replace("D","-..;");
  message.replace("E",".;");
  message.replace("F","..-.;");
  message.replace("G","--.;");
  message.replace("H","....;");
  message.replace("I","..;");
  message.replace("J",".---;");
  message.replace("K","-.-;");
  message.replace("L",".-..;");
  message.replace("M","--;");
  message.replace("N","-.;");
  message.replace("O","---;");
  message.replace("P",".--.;");
  message.replace("Q","--.-;");
  message.replace("R",".-.;");
  message.replace("S","...;");
  message.replace("T","-;");
  message.replace("U","..-;");
  message.replace("V","...-;");
  message.replace("W",".--;");
  message.replace("X","-..-;");
  message.replace("Y","-.--;");
  message.replace("Z","--..;");
  message.replace("1",".----;");
  message.replace("2","..---;");
  message.replace("3","...--;");
  message.replace("4","....-;");
  message.replace("5",".....;");
  message.replace("6","-....;");
  message.replace("7","--...;");
  message.replace("8","---..;");
  message.replace("9","----.;");
  message.replace("0","-----;");
  message.replace(" ","|");
  message.replace(":","---...;");
  message.replace(",","--..--;");
  message.replace("?","..--..;");
  message.replace("'",".----.;");
  message.replace("!","-.-.--;");
  message.replace("@",".--.-.;");

  message = message + "|";
  message.replace(";|","|");

  morse(message);
}

void loop() {
  if(Bt.Available()){
    String msg = Bt.ReadCommand();
    Serial.println(msg);
    translate(msg);
  }
  delay(100);
}
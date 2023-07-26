#include <PikControlMatrixLib.h>

PikControlMatrix8x8 matrix(21);

int BUZZER = 22;
int POINT = 300;
int TIRET = 500;
int display_info = 21;
const int temps = 250;

void tiret(){
  analogWrite(BUZZER, TIRET);
  matrix.GenerateSquarre(1,4,1,250,130,10);
  matrix.GenerateSquarre(2,4,1,250,130,10);
  matrix.GenerateSquarre(3,4,1,250,130,10);
  matrix.GenerateSquarre(4,4,1,250,130,10);
  matrix.GenerateSquarre(5,4,1,250,130,10);
  matrix.GenerateSquarre(6,4,1,250,130,10);
  //matrix.GenerateSquarre(7,4,1,250,130,10);
  matrix.GenerateSquarre(1,3,1,250,130,10);
  matrix.GenerateSquarre(2,3,1,250,130,10);
  matrix.GenerateSquarre(3,3,1,250,130,10);
  matrix.GenerateSquarre(4,3,1,250,130,10);
  matrix.GenerateSquarre(5,3,1,250,130,10);
  matrix.GenerateSquarre(6,3,1,250,130,10);
  //matrix.GenerateSquarre(7,3,1,250,130,10);
  delay(3*temps);
  matrix.Clear();
  analogWrite(BUZZER, LOW);
  delay(temps);
}

void point(){
  analogWrite(BUZZER, POINT);
  matrix.GenerateSquarre(2,2,1,250,130,10);
  matrix.GenerateSquarre(2,2,2,250,130,10);
  matrix.GenerateSquarre(2,2,3,250,130,10);
  matrix.GenerateSquarre(2,2,4,250,130,10);
  delay(temps);
  matrix.Clear();
  analogWrite(BUZZER, LOW);
  delay(temps);
}

void morse(String msg) {
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

void translateToMorse(String message) {
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
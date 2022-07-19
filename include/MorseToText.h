int next_button = 18;
int next_buttonState = 0;     // current state of the button
int next_lastButtonState = 0; // previous state of the button
int next_startPressed = 0;    // the moment the button was pressed
int next_endPressed = 0;      // the moment the button was released
int next_holdTime = 0;        // how long the button was hold
int next_idleTime = 0;        // how long the button was idle

int write_button = 5;
int write_buttonState = 0;     // current state of the button
int write_lastButtonState = 0; // previous state of the button
int write_startPressed = 0;    // the moment the button was pressed
int write_endPressed = 0;      // the moment the button was released
int write_holdTime = 0;        // how long the button was hold
int write_idleTime = 0;        // how long the button was idle

String prev_input;

String result;


const int buttonPin = 2;  

void listen_button() {
  if (digitalRead(next_button) == LOW) {
    Serial.println("enter");

    if (prev_input == "enter") {
        morse(result);
        Serial.println(result);
        result = "";
    } else {
        result += ";";
        Serial.println(";");
    }

    prev_input = "enter";
  } else if (digitalRead(write_button) == LOW) {
    Serial.print("write :");

    if (prev_input == "write") {
        result += "-";
        Serial.println("-");
    } else {
        result += ".";
        Serial.println(".");
    }

    prev_input = "write";
  } else {
    prev_input = "empty";
  }
}

void write_updateState() {
    
  // the button has been just pressed
  if (write_buttonState == LOW) {
    write_startPressed = millis();
  // the button has been just released
  } else {
    write_endPressed = millis();
    write_holdTime = write_endPressed - write_startPressed;

    if (write_holdTime < 500) {
        Serial.println(".");
        result += "."; 
    }

    if (write_holdTime >= 500) {
        Serial.println("-"); 
        result += "-"; 
    }

    Serial.println(write_holdTime);
  }
}

void next_updateState() {
    
  // the button has been just pressed
  if (next_buttonState == LOW) {
    next_startPressed = millis();
  // the button has been just released
  } else {
    next_endPressed = millis();
    next_holdTime = next_endPressed - next_startPressed;

    if (next_holdTime < 500) {
        Serial.println(";");
        result += ";";
    }

    if (next_holdTime >= 500) {
        morse(result);
        Serial.println(result);
        result = "";    }

    Serial.println(next_holdTime);
  }
}
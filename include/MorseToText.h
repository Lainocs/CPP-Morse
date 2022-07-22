#include <TransToAlph.h>
#include <displayLetter.h>

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

String morse_result;

String alph_result;

void write_updateState() 
{
  if (write_buttonState == LOW) {
    write_startPressed = millis();
  } else {
    write_endPressed = millis();
    write_holdTime = write_endPressed - write_startPressed;

    if (write_holdTime < 500) {
        morse_result += "."; 
    }

    if (write_holdTime >= 500) {
        morse_result += "-"; 
    }

    Serial.println(morse_result);
  }
}

void next_updateState() 
{    
  if (next_buttonState == LOW) {
    next_startPressed = millis();
  } else {
    next_endPressed = millis();
    next_holdTime = next_endPressed - next_startPressed;

    if (next_holdTime < 500) {
        alph_result += translateToLetter(morse_result);

        morse_result = "";   
    }

    if (next_holdTime >= 500) {
      
      for (size_t i = 0; i < alph_result.length(); i++)
      {
        for (size_t j = 0; j < 8; j++)
        {
          //displayLetter(alph_result[i], j);
          PrintMSG(alph_result[i], j);
          matrix.pixels->show();
          Serial.print(alph_result[i]);
          Serial.println(j);
          delay(100);
          matrix.Clear();
        }
      }


      morse_result = "";   
      alph_result = "";
    }

    Serial.println(alph_result);
  }
}
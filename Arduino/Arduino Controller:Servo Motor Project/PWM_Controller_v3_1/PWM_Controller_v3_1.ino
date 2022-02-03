// include the library code:
#include "Arduino.h"
#include <SoftwareSerial.h>
//#include <Servo.h>
#include <PWMServo.h>
#include "globals.h"
#include "interrupts.h"
#include "utility_LCD.h"
#include "select_functions.h"
#include "LCD_messages.h"
#include "motor_controllers.h"
#include "servo_controllers.h"

void setup() {
  // Set up LCD
  ConfigureLCDScreen();
  
  // Set up interrupts for rotary encoder
  pinMode(rotaryButton,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rotaryButton),RotaryButtonPush,FALLING);
  
  pinMode(rotaryEncoderA,INPUT_PULLUP);
  pinMode(rotaryEncoderB,INPUT_PULLUP);  
  attachInterrupt(digitalPinToInterrupt(rotaryEncoderA),RotaryKnob,FALLING);

  // Set up button for input
  pinMode(Button, INPUT_PULLUP);
 
} // End of Setup


void loop(){
  // Select Controller Type
  int controllerType = selectControllerType();
  //LCD_controllerChoice(controllerType);
  //delay(2000);

  // Run the code for the selected controller type
  switch(controllerType){
    case 1:
      motor_FwdRev();
      break;
    case 2:
      motor_Fwd();
      break;
     case 3:
      motor_Rev();
      break;
     case 4:
      servo_Abs();
  }
} // End of Loop

// Ashma Koirala
// UIC - CS 362 [Spring 2021]
// UIN - 659533981
// Title - Lab 4 [More complicated Input]
// References: https://playground.arduino.cc/Learning/PhotoResistor/, https://learn.adafruit.com/photocells
// Link to the youtube video: https://www.youtube.com/watch?v=1njE73rPVs4

// Description : 
/* This lab utilizes the arduino, breadboard, LCD display, sopme jumping wires, potentiometer and a photoresistor. I included the header Liquidcrystal.h
 to control the LCD display. Potentiometer is to adjust the brightness and photoresistor is to read the brightness. The readings 
 are compared in the algorithm to display the output in the desired brightness. A message is also displyed on the LCD which are 
 'Fully Lit, Partially Lit, Medium, Partially Dark and Dark' according to the readings of the light. */

// Assumptions :
/* The connection setup should connect the power and the allocated pins to the LCD screen, photoresistor and potentiometer
 which should read the brightness from photoresistor and display the message in the lcd accordingly. This all should
 work within the given algorithm.*/

// this header allows an arduino board with interact and function to LCD connected to it
#include <LiquidCrystal.h>

// pins on the arduino board for the LCD
LiquidCrystal LCD_Screen (12, 11, 5, 4, 3, 2);

// setting lcd width and height
int lcdScreenWidth = 16;
int lcdScreenHeight = 2;

// setting the string with the message
String displayString = "Initializing...";

// declaring the start and end of the string and the scrolling which happens along with the width of the screen.
int lcdPin = A0;
int lightStatus = 0; // initializing the status of the light's brightness

// setting the LCD starting loop with its width and height
void setup() {
 LCD_Screen.begin(lcdScreenWidth,lcdScreenHeight);
 Serial.begin(9600);  //Begin serial communcation
}

void loop() {   
   //reading current light status
   lightStatus = analogRead(lcdPin);
   
   Serial.println(lightStatus); //send the photoresisto's value to serial monitor
   delay(100);
   // algorithm starts
   if(lightStatus > 750)
     displayString = "Fully Lit";
   else if(lightStatus <= 750 && lightStatus > 450)
     displayString = "Partially Lit";
   else if(lightStatus <= 450 && lightStatus > 300)
     displayString = "Medium";
   else if(lightStatus <= 300 && lightStatus > 150)
     displayString = "Partially Dark";
   else
     displayString = "Fully Dark";
   
  //lcd's text will be set to static which doesn't scroll
  LCD_Screen.setCursor(0, 0);
  LCD_Screen.print(displayString);
  delay(500);
  LCD_Screen.clear();
}

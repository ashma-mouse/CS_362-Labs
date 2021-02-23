// Ashma Koirala
// UIC - CS 362 [Spring 2021]
// UIN - 659533981
// Title - Lab 3 [LCD Display with Name and Quote]
// References: https://www.arduino.cc/en/Tutorial/LibraryExamples/LiquidCrystalScroll, https://create.arduino.cc/projecthub/microBob/lcd-liquid-crystal-display-e72c74
// Link to the youtube video:  https://www.youtube.com/watch?v=uCB8KdH5F0I 

// Description : 
/* This lab utilizes the arduino, breadboard, LCD display, sopme jumping wires and a potentiometer. I included the header Liquidcrystal.h
 to control the LCD display. This code basically displays my name on the top which is static and doesnot scroll annd on the bottom, 
 the favorite quote of mine is diplayed along with the author of the quote. First, I will assign the pins to where the LCD is connected
 and setup the LCD with the screensize and declare the string of what I want to display on the screen. Finally, I start the loop to display 
 the strings which goes on and on.*/


// this header allows an arduino board with interact and function to LCD connected to it
#include <LiquidCrystal.h>

// pins on the arduino board for the LCD
LiquidCrystal LCD_Screen (12, 11, 5, 4, 3, 2);

// LCD size
int lcdScreenWidth = 16;
int lcdScreenHeight = 2;

// This is the static line which comes first
String myName = "Ashma Koirala";
// This is the second line which scrolls until the end of the string
String favQuote = "Never regret anything that made you smile. - Mark Twain";

// declaring the start and end of the string and the scrolling which happens along with the width of the screen.
int start_String = 0;
int stop_String = 0;
int scrollCursor = lcdScreenWidth;

// setting the LCD starting loop with its width and height
void setup() {
  
 LCD_Screen.begin(lcdScreenWidth,lcdScreenHeight);
  
}

// loop to actually display the strings according to the condition. 
void loop() {
  LCD_Screen.setCursor(scrollCursor, 0);
  LCD_Screen.print(myName);
  LCD_Screen.setCursor(0, 1);
  LCD_Screen.print(favQuote.substring(start_String,stop_String));
  delay(300);
  LCD_Screen.clear();
  
  if(start_String == 0 && scrollCursor > 0){
    
    scrollCursor--;
    stop_String++;
    
  }
  else if (start_String == stop_String){
    
    start_String = stop_String = 0;
    scrollCursor = lcdScreenWidth;
    
  }
  else if (stop_String == favQuote.length() && scrollCursor == 0) {
    
    start_String++;
    
  }
  else {
    
    start_String++;
    stop_String++;
  }
  
}

// Maxmatrix library:
// https://brainy-bits.com/tutorials/scroll-text-using-the-max7219-led-dot-matrix/
// https://code.google.com/p/arudino-maxmatrix-library/
// niq_ro from
// http://arduinotehniq.blogspot.com
// http://nicuflorica.blogspot.ro/
// original sketch - ver.1.1, 31.7.2015 - Craiova, Romania

#include <MaxMatrix.h>
#include <avr/pgmspace.h>
  
PROGMEM prog_uchar CH[] = {
3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
//3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
4, 8, B01000100, B01000010, B01111111, B01000000, B00000000, // 1
4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
//2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
//3, 8, B00010100, B00000000, B00000000, B00000000, B00000000, // :
3, 8, B00110110, B00110110, B00000000, B00000000, B00000000, // :
2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
//4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
3, 8, B00000110, B00001001, B00000110, B00000000, B00000000, // ~
};
 
int data = 12;    // DIN pin of MAX7219 module
int load = 10;    // CS pin of MAX7219 module
int clock = 11;  // CLK pin of MAX7219 module
 
int maxInUse = 4;  //how many MAX7219 are connected
 
MaxMatrix m(data, load, clock, maxInUse); // define Library
 
byte buffer[10];
 
// char string1[] = " niq_ro test sketch from https://brainy-bits.com/tutorials/scroll-text-using-the-max7219-led-dot-matrix/        ";  // Scrolling Text
 char string4[] = "    temperature:        "; // Fixxed text
 char string5[] = "    relative humidity:        "; // Fixxed text
 char string6[] = "    clock:        "; // Fixxed text


// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
#include "DHT.h"
#define DHTPIN A2     // what pin we're connected to A2
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// if is just sensor:
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);


#include <Wire.h>
#include "RTClib.h" // from https://github.com/adafruit/RTClib
//#include <Encoder.h> // from http://www.pjrc.com/teensy/td_libs_Encoder.html

RTC_DS1307 RTC; // Tells the RTC library that we're using a DS1307 RTC

byte spid = 25; 

void setup(){
  m.init(); // module MAX7219
  m.setIntensity(1); // LED Intensity 0-15
  byte c;
  delay(100);
  m.shiftLeft(false, true);

// Initialize DHT sensor
  dht.begin();

    Wire.begin();
    RTC.begin();
  if (! RTC.isrunning()) {
    //Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }


}
 
void loop(){

// Reading temperature or humidity 
 int has = dht.readHumidity();

 float te = dht.readTemperature(); 
// int te = dht.readTemperature(); 
 delay(250);
 int t2 = 10*te; 

 printStringWithShift(string5, spid);  // Send scrolling Text
//printString(string4);
// delay(2000);

// http://www.arduino-hacks.com/converting-integer-to-character-vice-versa/
char b[3];
String str;
str=String(has);
str.toCharArray(b,3);
// printString(b);
 printString1(b, 3);
// delay(1000);
 printString1("%rh", 13);
 delay(2000);


// http://www.arduino-hacks.com/converting-integer-to-character-vice-versa/
char c[3], d[2]; 
String str1, str2;
int t2z = t2/10;
int t2u = t2 - t2z*10;
str1=String(t2z);
str1.toCharArray(c,3);
str2=String(t2u);
str2.toCharArray(d,2);

/*
// clear the screen
printString1("         ", 0);
*/

 printStringWithShift(string4, spid);  // Send scrolling Text
//printString(string4);
// delay(2000);


printString1("+", 0);
printString1(c, 5);
// delay(1000);
printString1(",", 15);
printString1(d, 19);
printString1("~C", 24);
 delay(2000);


DateTime now = RTC.now();
int ora = now.hour();
int minut = now.minute();
//int second0 = now.second();

 printStringWithShift(string6, spid);  // Send scrolling Text

// clear the screen
//printString1("         ", 0);

// http://www.arduino-hacks.com/converting-integer-to-character-vice-versa/
char e[3], f[3]; 
String str3, str4;
str3=String(ora);
str3.toCharArray(e,3);
str4=String(minut);
str4.toCharArray(f,3);

if (ora > 10) printString1(e, 5);
else
{
  printString1(" ", 5);
  printString1(e, 9);
}

if (minut > 10) printString1(f, 19);
else
{
  printString1("0", 19);
  printString1(f, 24);
}
for(int j=0; j<5; j++)
{
//printString1(e, 5);
printString1(":", 15);
//printString1(f, 19);
delay(500);
printString1(" ", 15);
delay(400);
}
//delay(3000);
  
  

 
}
 
// Put extracted character on Display
void printCharWithShift(char c, int shift_speed){
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(maxInUse*8, 0, buffer);
  m.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i=0; i<buffer[0]+1; i++) 
//    for (int i=0; i<buffer[0]+1; i++) 
  {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}
 
// Extract characters from Scrolling text
void printStringWithShift(char* s, int shift_speed){
/*    printCharWithShift(48, shift_speed);
delay(5000);
    printCharWithShift(49, shift_speed);
delay(5000);
*/    
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
}

void printString(char* s)
{
  int col = 0;
  while (*s != 0)
  {
    if (*s < 32) continue;
    char c = *s - 32;
    memcpy_P(buffer, CH + 7*c, 7);
    m.writeSprite(col, 0, buffer);
    m.setColumn(col + buffer[0], 0);
    col += buffer[0] + 1;
    s++;
  }
}

void printString1(char* s, int col)
{
  int col1 = col;
  while (*s != 0)
  {
    if (*s < 32) continue;
    char c = *s - 32;
    memcpy_P(buffer, CH + 7*c, 7);
    m.writeSprite(col, 0, buffer);
    m.setColumn(col + buffer[0], 0);
    col += buffer[0] + 1;
    s++;
  }
}

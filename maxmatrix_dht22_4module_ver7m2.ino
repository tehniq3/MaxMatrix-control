// Maxmatrix library:
// https://brainy-bits.com/tutorials/scroll-text-using-the-max7219-led-dot-matrix/
// https://code.google.com/p/arudino-maxmatrix-library/
// niq_ro from
// http://arduinotehniq.blogspot.com
// http://nicuflorica.blogspot.ro/
// original sketch - ver.7.2, Craiova, Romania, 03.11.2015
// clear i2c bus: http://www.forward.com.au/pfod/ArduinoProgramming/I2C_ClearBus/index.html
/**
 * I2C_ClearBus
 * ( http://www.forward.com.au/pfod/ArduinoProgramming/I2C_ClearBus/index.html )
 * (c)2014 Forward Computing and Control Pty. Ltd.
 * NSW Australia, www.forward.com.au
 * This code may be freely used for both private and commerical use
 */

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
/*
// english language
 char string4[] = "    temperature:        "; // Fixxed text
 char string5[] = "    relative humidity:        "; // Fixxed text
 char string6[] = "    clock:        "; // Fixxed text
 char string7[] = "    date:        "; // Fixxed text
*/
/*
// roumanian language (in romana)
 char string4[] = "    temperatura:        "; // Fixxed text
 char string5[] = "    umiditate relativa:        "; // Fixxed text
 char string6[] = "    ceas:        "; // Fixxed text
 char string7[] = "    data:        "; // Fixxed text
*/

// no subtitles (fara comentarii)
 char string4[] = "            "; // Fixxed text
 char string5[] = "            "; // Fixxed text
 char string6[] = "            "; // Fixxed text
// char string7[] = "    data:        "; // Fixxed text


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

int photocellPin = A1;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider

/**
 * This routine turns off the I2C bus and clears it
 * on return SCA and SCL pins are tri-state inputs.
 * You need to call Wire.begin() after this to re-enable I2C
 * This routine does NOT use the Wire library at all.
 *
 * returns 0 if bus cleared
 *         1 if SCL held low.
 *         2 if SDA held low by slave clock stretch for > 2sec
 *         3 if SDA held low after 20 clocks.
 */
int I2C_ClearBus() {
  TWCR &= ~(_BV(TWEN)); //Disable the Atmel 2-Wire interface so we can control the SDA and SCL pins directly

  pinMode(SDA, INPUT_PULLUP); // Make SDA (data) and SCL (clock) pins Inputs with pullup.
  pinMode(SCL, INPUT_PULLUP);

  delay(2500);  // Wait 2.5 secs. This is strictly only necessary on the first power
  // up of the DS3231 module to allow it to initialize properly,
  // but is also assists in reliable programming of FioV3 boards as it gives the
  // IDE a chance to start uploaded the program
  // before existing sketch confuses the IDE by sending Serial data.

  boolean SCL_LOW = (digitalRead(SCL) == LOW); // Check is SCL is Low.
  if (SCL_LOW) { //If it is held low Arduno cannot become the I2C master. 
    return 1; //I2C bus error. Could not clear SCL clock line held low
  }

  boolean SDA_LOW = (digitalRead(SDA) == LOW);  // vi. Check SDA input.
  int clockCount = 20; // > 2x9 clock

  while (SDA_LOW && (clockCount > 0)) { //  vii. If SDA is Low,
    clockCount--;
  // Note: I2C bus is open collector so do NOT drive SCL or SDA high.
    pinMode(SCL, INPUT); // release SCL pullup so that when made output it will be LOW
    pinMode(SCL, OUTPUT); // then clock SCL Low
    delayMicroseconds(10); //  for >5uS
    pinMode(SCL, INPUT); // release SCL LOW
    pinMode(SCL, INPUT_PULLUP); // turn on pullup resistors again
    // do not force high as slave may be holding it low for clock stretching.
    delayMicroseconds(10); //  for >5uS
    // The >5uS is so that even the slowest I2C devices are handled.
    SCL_LOW = (digitalRead(SCL) == LOW); // Check if SCL is Low.
    int counter = 20;
    while (SCL_LOW && (counter > 0)) {  //  loop waiting for SCL to become High only wait 2sec.
      counter--;
      delay(100);
      SCL_LOW = (digitalRead(SCL) == LOW);
    }
    if (SCL_LOW) { // still low after 2 sec error
      return 2; // I2C bus error. Could not clear. SCL clock line held low by slave clock stretch for >2sec
    }
    SDA_LOW = (digitalRead(SDA) == LOW); //   and check SDA input again and loop
  }
  if (SDA_LOW) { // still low
    return 3; // I2C bus error. Could not clear. SDA data line held low
  }

  // else pull SDA line low for Start or Repeated Start
  pinMode(SDA, INPUT); // remove pullup.
  pinMode(SDA, OUTPUT);  // and then make it LOW i.e. send an I2C Start or Repeated start control.
  // When there is only one I2C master a Start or Repeat Start has the same function as a Stop and clears the bus.
  /// A Repeat Start is a Start occurring after a Start with no intervening Stop.
  delayMicroseconds(10); // wait >5uS
  pinMode(SDA, INPUT); // remove output low
  pinMode(SDA, INPUT_PULLUP); // and make SDA high i.e. send I2C STOP control.
  delayMicroseconds(10); // x. wait >5uS
  pinMode(SDA, INPUT); // and reset pins as tri-state inputs which is the default state on reset
  pinMode(SCL, INPUT);
  return 0; // all ok
}
// end part for clear i2c bus


void setup(){
  m.init(); // module MAX7219
  m.setIntensity(1); // LED Intensity 0-15
  byte c;
  delay(100);
  m.shiftLeft(false, true);

// Initialize DHT sensor
  dht.begin();

   // put your setup code here, to run once:
  Serial.begin(9600);

  int rtn = I2C_ClearBus(); // clear the I2C bus first before calling Wire.begin()
  if (rtn != 0) {
    Serial.println(F("I2C bus error. Could not clear"));
    if (rtn == 1) {
      Serial.println(F("SCL clock line held low"));
    } else if (rtn == 2) {
      Serial.println(F("SCL clock line held low by slave clock stretch"));
    } else if (rtn == 3) {
      Serial.println(F("SDA data line held low"));
    }
  } else { // bus clear
    // re-enable Wire
    // now can start Wire Arduino master
    Wire.begin();
  }
  Serial.println("setup finished");
 
//    Wire.begin();

    RTC.begin();
  if (! RTC.isrunning()) {
    //Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
}

// Serial.begin(9600); 

}
 
void loop(){
 lumina();

  // Reading temperature or humidity 
 int has = dht.readHumidity();

float te = dht.readTemperature(); 
// int te = dht.readTemperature(); 

 delay(250);

 int t2 = 10*te; 
// value for test display:
// t2 = 297;
//t2 = 14;
// t2 = 0;
// t2 = -15;
// t2 = -123;

 /*
// clear the screen
printString1("         ", 0);
*/
 lumina();
 printStringWithShift(string4, spid);  // Send scrolling Text
//printString(string4);
// delay(2000);
 lumina();

if (t2 >= 0)
{
  if (t2 >=100) printString1("+", 0);
  else printString1("+", 4);
 }
else
{
  if (t2 <=-100) printString1("-", 0);
  else printString1("-", 4);
  }
if (t2 < 0) t2 = -t2;  

// http://www.arduino-hacks.com/converting-integer-to-character-vice-versa/
char c[3], d[2]; 
String str1, str2;
int t2z = t2/10;
int t2u = t2 - t2z*10;
str1=String(t2z);
str1.toCharArray(c,3);
str2=String(t2u);
str2.toCharArray(d,2);


if (t2 >= 100) 
{
printString1(c, 5);
}
else
{
printString1(c, 9);
}
// delay(1000);
printString1(",", 15);
printString1(d, 19);
printString1("~C", 24);
  lumina();
 delay(5000);

 lumina();
 

 lumina();
DateTime now = RTC.now();
int ora = now.hour();
int minut = now.minute();
int anul=now.year();
int luna=now.month();
int ziua=now.day();
 lumina();
 
// https://www.arduino.cc/en/Reference/StringToCharArray
String data;
//data = "       date:  ";
//data = "       data:  ";
data = "         ";  // no subtitle
if (ziua >= 10) data = data + ziua;
else data = data + "0" + ziua;
data = data + ".";
//String data = ziua + ".";
if (luna >= 10) data = data + luna;
else 
{
  data = data + "0";
 data = data + luna;
}
data = data + ".";
data = data + anul;
//String data[20] = ziua + "." + luna + "." + anul;
char data1[20];
//data1=String(data);
data.toCharArray(data1,30);

 lumina();
// printStringWithShift(string7, spid);  // Send scrolling Text
printStringWithShift(data1, spid);  // Send scrolling Text
 lumina();
//int second0 = now.second();
//delay(500);

 printStringWithShift(string6, spid);  // Send scrolling Text
 lumina();
// clear the screen
//printString1("         ", 0);

// http://www.arduino-hacks.com/converting-integer-to-character-vice-versa/
char e[3], f[3]; 
String str3, str4;
str3=String(ora);
str3.toCharArray(e,3);
str4=String(minut);
str4.toCharArray(f,3);

 lumina();
if (ora >= 10) printString1(e, 5);
else
{
  printString1(" ", 5);
  printString1(e, 9);
}

if (minut >= 10) printString1(f, 19);
else
{
  printString1("0", 19);
  printString1(f, 24);
}
for(int j=0; j<7; j++)   // time in seconds (j<7) for display hour
{
//printString1(e, 5);
printString1(":", 15);
//printString1(f, 19);
delay(700);
printString1(" ", 15);
delay(300);
}

 printStringWithShift(string5, spid);  // Send scrolling Text
//printString(string4);
// delay(2000);

 lumina();
// http://www.arduino-hacks.com/converting-integer-to-character-vice-versa/
char b[3];
String str;
str=String(has);
str.toCharArray(b,3);
// printString(b);
 printString1(b, 3);
// delay(1000);
 printString1("%rh", 13);
 delay(3000);   // time for display hunmidity (in ms)

//delay(3000); 
}   // end main loop
 
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

void lumina()
{

  // read photocel
 photocellReading = analogRead(photocellPin);  
 
 m.setIntensity(photocellReading/150); // LED Intensity 0-15

  Serial.print(photocellReading);     // the raw analog reading
  Serial.print(" lux -> ");
  Serial.println(photocellReading/150);
}

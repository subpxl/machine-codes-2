#include <Bounce2.h>

#define encoder0PinA  14
#define encoder0PinB  15
Bounce debouncer = Bounce(); 
Bounce debouncer2 = Bounce();
volatile unsigned int encoder0Pos = 0;

void setup() { 


  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk

 debouncer.attach(encoder0PinA);
  debouncer.interval(500);

 debouncer2.attach(encoder0PinB);
  debouncer2.interval(500);
} 


void loop(){

      doEncoder();
      
// do some stuff here - the joy of interrupts is that they take care of themselves
}

void doEncoder() 
{    debouncer.update();
delay(1000);
      debouncer2.update();
      delay(1000);
  /* If pinA and pinB are both high or both low, it is spinning
   * forward. If they're different, it's going backward.
   *
   * For more information on speeding up this process, see
   * [Reference/PortManipulation], specifically the PIND register.
   */
   
     int value = debouncer.read();
       int value2 = debouncer2.read();
       
  if (value == value2) 
  {
    encoder0Pos++ ;
  } 

  Serial.println (encoder0Pos, DEC);
}

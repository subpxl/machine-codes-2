 
#include <Bounce2.h>

#define encoder0PinA  14
#define encoder0PinB  15
Bounce debouncer = Bounce(); 
Bounce debouncer2 = Bounce();
volatile unsigned int enc1 = 0; 
void setup() { 
  Serial.begin(9600);
  { 


  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
 
                 // a personal quirk

 debouncer.attach(encoder0PinA);
  debouncer.interval(100);

 debouncer2.attach(encoder0PinB);
  debouncer2.interval(100);
} 

}
 
void loop() {
  
  Serial.println("clockwise");
  
   
 }

void doEncoder() 
{
debouncer.update();
delay(100);
      debouncer2.update();
      delay(100);

     int value = debouncer.read();
       int value2 = debouncer2.read();
       
    
  
   
  Serial.print(enc1, DEC);
  Serial.print ("\t"); 
 
    
    
}

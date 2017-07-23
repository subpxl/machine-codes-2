 #include <Servo.h>
#include <Stepper.h>
#include <Bounce2.h>

#define encoder0PinA  2
#define encoder0PinB  3

#define encoder1PinA  2
#define encoder1PinB  3

#define triggerPin 4
#define echoPin 5
int a = 30;
int b = 30;
Bounce debouncer = Bounce(); 
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce(); 
Bounce debouncer4 = Bounce(); 
volatile unsigned int enc1 = 0;
volatile unsigned int enc2 = 0;

const int stepsPerRevolution = 80;  // change this to fit the number of steps per revolution
 

   long duration, cm;
 

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

Servo servo1,servo2;  // create servo object to control a servo 
//Servo servo2;                // twelve servo objects can be created on most boards
 
int pos1 = 0; 
int pos2 = 0; 
void setup() {

 
   pinMode(triggerPin,OUTPUT);
    pinMode(echoPin,INPUT);; // Start serial communications
 
  myStepper.setSpeed(60);
  servo1.attach(6);
    servo2.attach(7);
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
  
   debouncer3.attach(encoder1PinA);
  debouncer3.interval(100);

 debouncer4.attach(encoder1PinB);
  debouncer4.interval(100);
} 

}

void ultra ()
{
    digitalWrite(triggerPin,LOW);
     delayMicroseconds(2);
     digitalWrite(triggerPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(triggerPin, LOW);
     delayMicroseconds(2);
     duration =  pulseIn(echoPin,HIGH);
     
     cm= distance(duration);
     Serial.print("cm= ");
     Serial.print(cm);
     delay(500);
     
    

}
void loop() {
  
 
  myStepper.step(stepsPerRevolution);
   
 }

void doEncoder() 
{
debouncer.update();
delay(100);
      debouncer2.update();
      delay(100);

debouncer3.update();
delay(100);

debouncer4.update();
delay(100);

     int value1 = debouncer.read();
       int value2 = debouncer2.read();
     int value3 = debouncer.read();
   int value4 = debouncer.read();    
    
  if (value1 == value2) 
  {
    enc1++ ;

} 
  if (enc1 >150)
  {enc1 = enc1-150;
  pos1 = pos1 +a;
     if (pos1 == 180 || pos1 == 0)
      { a = -a ;
      }
      
  }

  if (value3 == value4) 
  {
    enc2++ ;

} 
  if (enc2 >150)
  {enc2 = enc2-150;
  pos2 = pos2 +a;
     if (pos2 == 180 || pos2 == 0)
      { b = -b ;
      }
      
  }    
  servo1.write(pos1);
  servo2.write(pos1); 
  Serial.print(enc1, DEC);
  Serial.print(enc2, DEC);
   Serial.println(pos1);
  Serial.print ("\t"); 
 
  Serial.println(pos2);
  Serial.print ("\t"); 
    
    
}

     long distance(long microseconds)
{
  return microseconds /29/2; 
}

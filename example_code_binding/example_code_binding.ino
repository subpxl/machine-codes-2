 #include <Servo.h>
#include <Stepper.h>
#include <Bounce2.h>

#define encoder0PinA  2
#define encoder0PinB  3
Bounce debouncer = Bounce(); 
Bounce debouncer2 = Bounce();
volatile unsigned int enc1 = 0;
int a = 30;
const int stepsPerRevolution = 80;  // change this to fit the number of steps per revolution
   
unsigned long pulse_width;

Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0; 
void setup() {
   Serial.begin(9600); // Start serial communications
  pinMode(4, OUTPUT); // Set pin 4 as trigger pin
  pinMode(5, INPUT); // Set pin 5 as monitor pin
  //Turn sensor on
  digitalWrite(4, LOW);
  myStepper.setSpeed(60);
  myservo.attach(6);
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

void lidar ()
{  pulse_width = pulseIn(5, HIGH); // Count how long the pulse is high in microseconds
  if(pulse_width != 0){ // If we get a reading that isn't zero, let's print it
        pulse_width = pulse_width/10; // 10usec = 1 cm of distance for LIDAR-Lite
  // Print the distance
 
  delay(1); //Delay so we don't overload the serial port
 
}

}
void loop() {
  
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
   
 }

void doEncoder() 
{
debouncer.update();
delay(100);
      debouncer2.update();
      delay(100);

     int value = debouncer.read();
       int value2 = debouncer2.read();
       
    
  if (value == value2) 
  {
    enc1++ ;

} 
  if (enc1 >150)
  {enc1 = enc1-150;
  pos = pos +a;
     if (pos == 180 || pos == 0)
      { a = -a ;
      }
      
  }
    
  myservo.write(pos); 
  Serial.print(enc1, DEC);
  Serial.print ("\t"); 
  Serial.println(pos);
  Serial.print ("\t"); 
    Serial.println(pulse_width);   
    
}

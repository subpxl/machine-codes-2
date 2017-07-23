  #include <Servo.h>
int count;
volatile int rpmcount =0;
 
#include <NewPing.h>

#define TRIGGER_PIN  16 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
Servo myservo; 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int a = 30; 
 
int pos = 0; 
 #define A 10            // the pin connected to the wire A of the coil A (or to the H-bridge pin controlling the same wire) 
#define A_bar  11                    // the pin connected to the wire A- of the coil A (or to the H-bridge pin controlling the same wire)
#define B       12               // the pin connected to the wire B of the coil A (or to the H-bridge pin controlling the same wire)
#define B_bar   13                    // the pin connected to the wire B- of the coil A (or to the H-bridge pin controlling the same wire)
#define x     800                // smaller values may make the motor produce more speed and less torque
#define stepsPerRevolution 150
void setup()
{ pinMode(A, OUTPUT);
  pinMode(A_bar, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(B_bar, OUTPUT);
  Serial.begin(9600); // start serial communication at 9600bps
attachInterrupt(1, rpm_fan, FALLING); //pin 4 on 328 
  myservo.attach(5);
   
 }

void stepper1()
{ //print the word "Hz".
 for (int i = 0; i < (stepsPerRevolution/8) ; i++) {
 //doEncoder();  
  digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);
    
    digitalWrite(A, LOW);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);

    digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);
  } 
}
 
void loop()
{  stepper1(); 
  
 
  if(rpmcount>150)
      {
       pos = pos + a;                               
       myservo.write(pos);  
       delay(15);
       rpmcount = rpmcount - 150; 
      
   if (pos == 90 || pos == 0)
          { a = -a ;
          }
       }
       myservo.write(pos);
    data();
    
}
void data()
{ Serial.print(rpmcount);
attachInterrupt(1, rpm_fan, FALLING);
Serial.print("\t");
Serial.print(sonar.ping_cm());
  Serial.print ("\t"); 
      Serial.print(pos);      
Serial.println("\t");
delay(50); 
  }
 
 
 void rpm_fan()
     { 
      rpmcount++;
      }
    


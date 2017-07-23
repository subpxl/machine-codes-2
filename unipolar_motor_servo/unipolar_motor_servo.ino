#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
  #include <Servo.h>
int count;
volatile int rpmcount =0;
int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time1;
unsigned long currentMillis ;
int steps_left=4095;
long time1;
Servo myservo; 
int a = 30; 
 
int pos = 0; 
void setup()
{
Serial.begin(115200);
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT); 
pinMode(IN3, OUTPUT); 
pinMode(IN4, OUTPUT); 
// delay(1000);
attachInterrupt(1, rpm_fan, FALLING); //pin 4 on 328 
  myservo.attach(5);
}
void loop()
{
  while(steps_left>0){
  currentMillis = micros();
  if(currentMillis-last_time1>=1000){
  stepper(1); 
  time1=time1+micros()-last_time1;
  last_time1=micros();
  steps_left--;
  }
  }
   Serial.println(time1 );
  Serial.println("Wait...!");
  delay(1000);
  Direction=!Direction;
  steps_left=4095;

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
          Serial.print(rpmcount);
attachInterrupt(1, rpm_fan, FALLING);
Serial.print("\t");
 
  Serial.print ("\t"); 
      Serial.print(pos);      
Serial.println("\t");
delay(50); 
}

void stepper(int xw){
  for (int x=0;x<xw;x++){
switch(Steps){
   case 0:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   case 1:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, HIGH);
   break; 
   case 2:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 3:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 4:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 5:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
     case 6:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 7:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   default:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
}
SetDirection();
}
} 
void SetDirection(){
if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }
}

 void rpm_fan()
     { 
      rpmcount++;
      }
    

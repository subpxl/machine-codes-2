 
int count;

 
volatile int rpmcount =0;
int rpm =0;
int v;// Register to get both High and Low bytes in 1 call.

int reading = 0;

void setup()
{
 
 
  Serial.begin(9600); // start serial communication at 9600bps
   Serial.println ("acd");
   
   attachInterrupt(1, rpm_fan, FALLING); //pin 4 on 328 
}

void enc()
{ //print the word "Hz".
     Serial.println(rpmcount);
 
 
    attachInterrupt(1, rpm_fan, FALLING);
    
  }

void loop()
{ 
  enc();
  
    
}
 void rpm_fan()
     { 
      rpmcount++;
      }
    


int triggerPin = 16;
int echoPin = 17;
long duration, cm;
 

void setup()
{




  
   pinMode(triggerPin,OUTPUT);
    pinMode(echoPin,INPUT);
    Serial.begin(9600);
     delay(2000);
}    
  
void ultra()
{ digitalWrite(triggerPin,LOW);
     delayMicroseconds(6);
     digitalWrite(triggerPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(triggerPin, LOW);
     delayMicroseconds(6);
     duration =  pulseIn(echoPin,HIGH);
     
     cm= distance(duration);
     Serial.println(cm);
     delay(50);}
void loop()
{  
  ultra();
    }

      long distance(long microseconds)
   {
      return microseconds /29/2; 
    }

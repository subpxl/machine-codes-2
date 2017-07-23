 
 
#define A        10       // the pin connected to the wire A of the coil A (or to the H-bridge pin controlling the same wire) 
#define A_bar    11                    // the pin connected to the wire A- of the coil A (or to the H-bridge pin controlling the same wire)
#define B        12                // the pin connected to the wire B of the coil A (or to the H-bridge pin controlling the same wire)
#define B_bar    13                     // the pin connected to the wire B- of the coil A (or to the H-bridge pin controlling the same wire)
#define x     5000                // smaller values may make the motor produce more speed and less torque
#define stepsPerRevolution 400        // you can the number of steps required to make a complete revolution in the data sheet of your motor

 
void setup() {
  pinMode(A, OUTPUT);
  pinMode(A_bar, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(B_bar, OUTPUT);
 }

void stepper()
{for (int i = 0; i < (stepsPerRevolution/8) ; i++) {
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

void loop() {  
  stepper();
   }  // the motor will complete a full revolution then waits for a second
  
  
   /*   // Counter Direction 
  for (int i = 0; i < (stepsPerRevolution/8); i++) {
    digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);
    
    digitalWrite(A, LOW);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);
    
    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, HIGH);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, LOW);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);

    digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x); 

    digitalWrite(A, HIGH);
    digitalWrite(A_bar, LOW);
    digitalWrite(B, LOW);
    digitalWrite(B_bar, LOW);
    delayMicroseconds (x);  
  }
  delay(1000);*/

  


/* Code Written by Roy Pe'er. I've explained all the code in the grey comments.
I recommend you to go over the code, examine it, play with it, improve it and modify it according to your needs. 
For more awesome videos, subsrice to my channel:
http://www.youtube.com/subscription_center?add_user=Roypeer1
*/
#include <AFMotor.h> //import your motor shield library
// define pin numbers
#define trigPin 12 // define the pins of your sensor
#define echoPin 13 

AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_8KHZ);

//define variables
long duration, distance

void setup() {
pinMode(trigPin, OUTPUT);// sets trigPin to output (Send sound waves)
   
pinMode(echoPin, INPUT);// set the echoPin to input (Recieves sound waves)

Serial.begin(9600); // begin serial communitication  
  
Serial.println("Motor test!");
  
motor1.setSpeed(105); //set the speed of the motors, between 0-255
motor2.setSpeed (105);  
}
 
void loop() {
//Clears the trigPin
digitalWrite(trigPin, LOW);  
delayMicroseconds(2); // delays are required for a successful sensor operation.
  
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin, LOW);
//Reads the echoPin, returns the sound wave travel time in microsends
  duration = pulseIn(echoPin, HIGH);

//Calculating the distance
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  
  if (distance < 25)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
   Serial.println ("Close Obstacle detected!" );
Serial.println ("Obstacle Details:");
Serial.print ("Distance From Robot is " );
Serial.print ( distance);
Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println (" The obstacle is declared a threat due to close distance. ");
Serial.println (" Turning !");
    motor1.run(FORWARD);  // Turn as long as there's an obstacle ahead.
    motor2.run (BACKWARD);

}
  else {
   Serial.println ("No obstacle detected. going forward");
   delay (15);
   motor1.run(FORWARD); //if there's no obstacle ahead, Go Forward! 
    motor2.run(FORWARD);  
  }  
  
  

  
  
  
 
}

#include <Servo.h>
 
const int servoPin = 9;

const int trigPin = 11;    // Trigger
const int echoPin = 12;    // Echo
unsigned long duration, cm, inches;
boolean obstacle, leftError, rightError;
 
Servo servo;  
 
int servoAngle = 0;

void setup()
{
  Serial.begin(9600);  

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servo.attach(servoPin);
}

void loop() {
  calcDistance();
  obstacleCheck();
  readOut();
  delay(2500); 
}
 
void calcDistance()
{
  //randomnerdtutorials.com code begins here
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  //randomnerdtutorials.com code ends here
  //https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
}

void obstacleCheck()
{
  if (cm < 20)
  {
    Serial.println("Obstacle in the way!");
    obstacle = true;
    turnCheck();
    if (servoAngle == 0)
    {
      servoWrite(90);
    }
    else if (servoAngle == 90)
    {
      servoWrite(180);
    }
    else
    {
      servoWrite(0);
    }
  }
}

void turnCheck()
{
  // This code will eventually make use of two additional ultrasonic distance sensors to see which direction it would be better to turn in. For now, the outputs will be manually input.
  // For the purpose of demonstrating that we can control the servo motor using our one ultrasonic distance sensor, this code will be ignoring the more complex turning mechanism and will just cause the servo to rotate counterclockwise until further notice. 
  return;
  /*
  int leftDist = 50;
  int rightDist = 100;
  if (leftDist > rightDist)
  {
    if (leftDist > 800)
    {
      leftError = true;
    }
    else
    {
      leftError = false;
      turnLeft();
      return;
    } 
  }
  if (rightDist > leftDist)
  {
    if (rightDist > 800)
    {
      rightError = true;
    }
    else
    {
      rightError = false;
      turnRight();
      return;
    }
  }
  if (true)
  {
    if ((rightError == true) || (leftError == true))
    {
      Serial.println("An error has occured with the turn direction choice mechanism. An arbitrary direction will be selected.");
    }
    else
    {
      Serial.println("Either both the left and right ultrasonic distance sensors gave the same readout, or something weird is going on. An arbitrary directions will be selected.");
    }
    turnRight();
  }*/
}

void turnLeft()
{
  // This function will eventually cause the hovercraft to turn left.
  Serial.println("Turning left!");
}

void turnRight()
{
  // This function will eventually cause the hovercraft to turn right.
  Serial.println("Turning right!");
}

void readOut()
{
  Serial.print("Distance in inches: ");
  Serial.println(inches);
  Serial.print("Distance in centimeters: ");
  Serial.println(cm);
}

void servoWrite(int angle)
{
  servo.write(angle);
  servoAngle = angle;
  Serial.print("Rotating to ");
  Serial.print(angle);
  Serial.println(" degrees.");
}

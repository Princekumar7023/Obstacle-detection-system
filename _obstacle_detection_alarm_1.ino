// Define pins for ultrasonic and buzzer
// include the library code:
// initialize the library with the numbers of the interface pins
// The circuit:
// 10K resistor:
// ends to +5V and ground
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;
void setup()
{
Serial.begin(9600);
lcd.begin(16,2);
lcd.print("ObstacleDetector");
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}
void loop()
{
// Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
int duration, distance;
// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration divided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;
lcd.clear();
lcd.print("ObstacleDistance");
lcd.setCursor(0,1);
lcd.print(distance);
lcd.setCursor(4,1);
lcd.print("cm");
Serial.print( "obstacle Distance in cm is " );
Serial.print(distance);
Serial.println();
// if distance less than 1 meter and more than 0 (0 or less means over range)
if (distance <= 100 && distance >= 0) {
// Buzz
digitalWrite(buzzPin, HIGH);
} else {
// Don't buzz
digitalWrite(buzzPin, LOW);
}
// Waiting 60 ms won't hurt any one
delay(100);
}
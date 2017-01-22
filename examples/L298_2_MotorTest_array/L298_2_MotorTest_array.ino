/*
 * This is an example sketch to test a DC motor using the custom L298 Motor Library with the Uno
 * 
 * This does not work with he more complicated motor shields, this is for an Uno connectd directly to an L298 chip or module.
 * 
 * Connect as follows:
 * 
 * Motor 1 enable - pin 9
 * Motor 1 IN0 - pin 2
 * Motor 1 IN1 - pin 3
 * 
 * Motor 2 enable - pin 10
 * Motor 2 IN0 - pin 4
 * Motor 2 IN1 - pin 5
 */
#include <L298Nbridge.h>


//initialise a motor object (1 or 2)
DCMotor motors[] = {
    DCMotor(1), // left is Motor #1 
    DCMotor(2)  // right is Motor #2
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Motor test!");

  //turn on motor using pwm speed 0 - 255
  motors[0].setSpeed(200);
  motors[1].setSpeed(200);

  motors[0].run(RELEASE);
  motors[1].run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t i;

  Serial.println("forward");

  motors[0].run(FORWARD);
  motors[1].run(FORWARD);
  for (i=0; i<255; i++) {
    motors[0].setSpeed(i);
    motors[1].setSpeed(i);
    delay(10);
  }

  for (i=255; i!=0; i--) {
    motors[0].setSpeed(i);
    motors[1].setSpeed(i);
    delay(10);
  }

  Serial.println("backwards");
  motors[0].run(BACKWARD);
  motors[1].run(BACKWARD);
  for (i=0; i<255; i++) {
    motors[0].setSpeed(i);
    motors[1].setSpeed(i);
    delay(10);
  }

  for (i=255; i!=0; i--) {
    motors[0].setSpeed(i);
    motors[1].setSpeed(i);
    delay(10);
  }
  Serial.println("aaaaaaannnd stop.");
  motors[0].run(RELEASE);
  motors[1].run(RELEASE);
  delay(1000);
}

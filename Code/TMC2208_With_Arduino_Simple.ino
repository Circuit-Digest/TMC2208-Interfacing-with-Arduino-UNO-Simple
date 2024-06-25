// This code controls a stepper motor using the TMC2208 stepper driver.
// Features:
// - Defines pins for enabling the driver, stepping, and setting direction.
// - Sets up pin modes and initial states in the setup function.
// - In the loop function, alternates the stepping direction after a specified number of steps.
// - Utilizes delay for controlling the speed of the stepper motor.


// Pin Definitions
#define EN_PIN 8    // LOW: Driver enabled. HIGH: Driver disabled
#define STEP_PIN 9  // Step on rising edge
#define DIR_PIN 10  // Set stepping direction

int noOfSteps = 250;
int microSecondsDelay = 1000;

void setup() {
  // Pin Declarations
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Initial Pin Configuration
  digitalWrite(DIR_PIN, LOW);  // Setting a Direction
  digitalWrite(EN_PIN, LOW);   // Driver Enabled
}

void loop() {

  digitalWrite(DIR_PIN, LOW);  // Switching Direction
  for (int i = 0; i < noOfSteps * 2; i++) {
    digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
    delayMicroseconds(microSecondsDelay);
  }

  digitalWrite(DIR_PIN, HIGH);  // Switching Direction
  for (int i = 0; i < noOfSteps * 2; i++) {
    digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
    delayMicroseconds(microSecondsDelay);
  }
}

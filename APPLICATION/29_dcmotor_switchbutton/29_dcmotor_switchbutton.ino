

const int forwardButtonPin = 13; // for motor controller
const int backwardButtonPin = 12; // for motor controller
const int motorForward = 11;  //attach to one of the pin of the motor
const int motorBackward = 10;  //attach to another pin of the the motor
const int increseSpeeddButtonPin = 9; // for motor speed increment
const int decreseSpeeddButtonPin = 8; // for motor speed decrement
const int stopButtonPin = 7; // for motor stop

int dcMotorSpeed = 128;
int buttonValue = 0;
int state = 0;            //Record the motor state. 0:STOP  1:forward  2:reverse
const int minMoterSpeed = 128;
const int maxMoterSpeed = 255;

void setup() {
  Serial.begin(9600);
  pinMode(motorForward, OUTPUT);    //initialize the motorIn1 pin as output
  pinMode(motorBackward, OUTPUT);  //initialize the motorIn2 pin as output

  pinMode(forwardButtonPin, INPUT_PULLUP);
  pinMode(backwardButtonPin, INPUT_PULLUP);
  pinMode(increseSpeeddButtonPin, INPUT_PULLUP);
  pinMode(decreseSpeeddButtonPin, INPUT_PULLUP);
  pinMode(stopButtonPin, INPUT_PULLUP);
}

void loop() {

  delay(1000);

  state = calculateDirection();

  Serial.println(state);
  Serial.println(dcMotorSpeed);
  switch (state) {
    case 0:  stopMoter();                  //motor stop
      break;
    case 1:  forwardMoter(dcMotorSpeed);   //rotate forward
      break;
    case 2:  backwardMoter(dcMotorSpeed);  //rotate backward
      break;
    default: stopMoter();                  //motor stop
      break;
  }

}


int calculateDirection() {

  buttonValue = digitalRead(forwardButtonPin);
  if (buttonValue == LOW) {
    stopMoter();
    state = 1;
    dcMotorSpeed = 148;
    buttonValue = HIGH;
  }

  buttonValue = digitalRead(backwardButtonPin);
  if (buttonValue == LOW) {
    stopMoter();
    state = 2;
    dcMotorSpeed = 148;
    buttonValue = HIGH;
  }

  buttonValue = digitalRead(stopButtonPin);
  if (buttonValue == LOW) {
    stopMoter();
    state = 0;
    dcMotorSpeed = 128;
    buttonValue = HIGH;
  }
  return state;
}


int calculateSpeed(int xpinValue) {


  buttonValue = digitalRead(increseSpeeddButtonPin);

  if (buttonValue == LOW) {
    if (dcMotorSpeed <= maxMoterSpeed) {
      dcMotorSpeed = + 10;;
    }
    buttonValue = HIGH;
  }

  buttonValue = digitalRead(decreseSpeeddButtonPin);
  if (buttonValue == LOW) {

    if (dcMotorSpeed >= minMoterSpeed) {
      dcMotorSpeed =- 10;;
    }
    buttonValue = HIGH;
  }

  return dcMotorSpeed;
}


//The function to drive motor rotate clockwise
void stopMoter() {
  state = 0 ;
  analogWrite(motorBackward, 0); //set the speed of motor
  analogWrite(motorForward, 0); //set the speed of motor
}

//The function to drive motor rotate forward
void forwardMoter(int dcMotorSpeed) {
  Serial.println(state);
  Serial.println(dcMotorSpeed);
  analogWrite(motorBackward, 0);
  analogWrite(motorForward, dcMotorSpeed);
}

//The function to drive motor rotate backward
void backwardMoter(int dcMotorSpeed) {
  Serial.println(state);
  Serial.println(dcMotorSpeed);
  analogWrite(motorForward, 0);
  analogWrite(motorBackward, dcMotorSpeed);
}

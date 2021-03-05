
/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#include <Arduino.h>
#include "Pca9685.h"


void Pca9685::initPca9685() {
  //_pwm.begin();
  if (_totalPins == -1) {
    _totalPins = 16;
  }
  for (int i = 0; i < _totalPins; i++) {
    _pca9685PinList[i]._openState = 1000;
    _pca9685PinList[i]._closeState = 2000;
    _pca9685PinList[i]._isOpen = false;
  }
}

bool Pca9685::throwSwitchPca9685Pin(int pinNo) {
  _pca9685PinList[pinNo]._isOpen = true;
  Pca9685Pin pin = _pca9685PinList[pinNo];
  refreshPin(pinNo, pin);
  return true;
}

bool Pca9685::closeSwitchPca9685Pin(int pinNo) {
  _pca9685PinList[pinNo]._isOpen = false;
  Pca9685Pin pin = _pca9685PinList[pinNo];
  refreshPin(pinNo, pin);
  return true;
}

void Pca9685::resetPca9685Board() {
  for (int i = 0; i < _totalPins; i++) {
    Pca9685Pin pca9685Pin = _pca9685PinList[i];
    pca9685Pin._isOpen = false;
  }
  refreshPca9685Board();
}

void Pca9685::refreshPca9685Board() {
  for (int i = 0; i < _totalPins; i++) {
    Pca9685Pin pca9685Pin = _pca9685PinList[i];
    if (pca9685Pin._isOpen) {
      //_pwm.setPWM(pinNo, 0, pca9685Pin._openState );
    } else {
      //_pwm.setPWM(pinNo, 0, pca9685Pin._closeState );
    }
  }
  //displayPinState(pca9685Pin);
}

void Pca9685::refreshPin(int pinNo, Pca9685Pin pca9685Pin) {
  //todo with adafruit lib implementation
  if (pca9685Pin._isOpen) {
    //_pwm.setPWM(pinNo, 0, pca9685Pin._openState );
  } else {
    //_pwm.setPWM(pinNo, 0, pca9685Pin._closeState );
  }
  //displayPinState(pca9685Pin);
}

void Pca9685::displayPinState(Pca9685Pin pin) {
  Serial.println();
  Serial.print(" openState ");
  Serial.println(pin._openState);
  Serial.print(" closeState ");
  Serial.println(pin._closeState);
  Serial.print(" isOpen ");
  Serial.println(pin._isOpen);
  Serial.println();
}

void Pca9685::displayPca9685PinState() {
  Serial.print("Board No ");
  Serial.print(_boardsAddress);
  Serial.print(" total pins ");
  Serial.println(_totalPins);
  for (int i = 0; i < _totalPins; i++) {
    Pca9685Pin pin = _pca9685PinList[i];
    Serial.println();
    Serial.print(" Pin ");
    Serial.print(i);
    Serial.print(" openState ");
    Serial.print(pin._openState);
    Serial.print(" closeState ");
    Serial.print(pin._closeState);
    Serial.print(" isOpen ");
    Serial.print(pin._isOpen);
    Serial.println();
  }
}
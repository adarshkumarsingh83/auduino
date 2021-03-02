
#include "CircularQueue.h"
#include "Arduino.h"

template <class T>
boolean CircularQueue<T>::push(const T &value) {
  int pos = (_endIndex + 1) % _queueSize;
  if (_data[pos] == T() && _itemCount < _queueSize) {
    _data[pos] = value;
    _endIndex = pos;
    _itemCount++;
    Serial.print(_queueName + " DATA INSERTED ");
    Serial.println(value);
    return true;
  }
  return false;
}

template <class T>
inline T CircularQueue<T>::pop() {
  int pos = (_startIndex + 1) % _queueSize;
  if (_data[pos] != T() && _itemCount != 0 ) {
    T value = _data[pos];
    _data[pos] = T();
    _startIndex = pos;
    --_itemCount;
    return value;
  }
  return T();
}

template <class T>
boolean CircularQueue<T>::isEmpty() {
  if (_startIndex == _endIndex) {
    return true;
  } else {
    return false;
  }
}

template <class T>
void CircularQueue<T>::resetQueue() {
  Serial.print(_queueName + " RESETTING QUEUE ");
  Serial.println();
  _startIndex = -1;
  _endIndex = -1;
  _itemCount = 0;
  for (int i = 0; i < _queueSize; i++) {
    _data[i] = T();
  }
}

template <class T>
void CircularQueue<T>::displayQueue() {
  Serial.print(_queueName + " DATA => ");
  int st = 0;
  int ed = 0;
  st = (_startIndex + 1) % _queueSize;
  ed = st;
  while (true)
  {
    Serial.print(_data[st]);
    Serial.print("  ");
    st = (st + 1) % _queueSize;
    if (st == ed)
    {
      break;
    }
    if (_data[st] == -1)
    {
      break;
    }
  }
  Serial.println();
}
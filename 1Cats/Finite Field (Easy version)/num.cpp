//
// Created by tihon on 17.11.2020.
//

#include "num.h"

Num::Num(int value, int modulo) {
  if (modulo != 0) {
    this->value = value % modulo;
  } else {
    this->value = value;
  }
  this->modulo = modulo;
}
Num::Num(const Num& other) {
  value = other.value;
  modulo = 0;
}


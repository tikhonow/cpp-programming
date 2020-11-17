//
// Created by tihon on 17.11.2020.
//

#include "num.h"
#include <cstdint>
Num::Num(int value, int modulo) : value(value % modulo), modulo(modulo) {}

Num &Num::operator=(const Num &other) {
  value = other.value;
  modulo = other.modulo;
  return *this;
}

Num Num::operator+(const Num &other) {
  return Num(static_cast<int>(((int64_t)value + (int64_t)other.value) % modulo),
             modulo);
}

Num Num::operator-(const Num &other) {
  return Num((value - other.value) < 0 ? modulo + (value - other.value)
                                       : value - other.value,
             modulo);
}

Num Num::operator*(const Num &other) {
  return Num(static_cast<int>(((int64_t)value * (int64_t)other.value) % modulo),
             modulo);
}

Num Num::operator+(int num) {
  return Num(static_cast<int>(((int64_t)value + (int64_t)num) % modulo),
             modulo);
}

Num Num::operator-(int num) {
  return Num((value - num) < 0 ? modulo + (value - num) : value - num, modulo);
}

Num Num::operator*(int num) {
  return Num(static_cast<int>(((int64_t)value * (int64_t)num) % modulo),
             modulo);
}

Num &Num::operator+=(const Num &other) { return *this = *this + other; }

Num &Num::operator-=(const Num &other) { return *this = *this - other; }

Num &Num::operator*=(const Num &other) { return *this = *this * other; }

Num &Num::operator+=(int num) { return *this = *this + num; }

Num &Num::operator-=(int num) { return *this = *this - num; }

Num &Num::operator*=(int num) { return *this = *this * num; }

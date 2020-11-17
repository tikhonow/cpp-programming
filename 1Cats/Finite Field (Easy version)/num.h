//
// Created by tihon on 17.11.2020.
//

#ifndef CPP_PROGRAMMING_1CATS_FINITE_FIELD_EASY_VERSION_NUM_H_
#define CPP_PROGRAMMING_1CATS_FINITE_FIELD_EASY_VERSION_NUM_H_

#include <iostream>

class Num {
 public:
  Num(int value=0, int modulo=0);
  Num(const Num& other);

  int value;
  int modulo;
};

#endif //CPP_PROGRAMMING_1CATS_FINITE_FIELD_EASY_VERSION_NUM_H_

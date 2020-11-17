//
// Created by tihon on 17.11.2020.
//

#ifndef CPP_PROGRAMMING_1CATS_FINITE_FIELD_HARD_VERSION_NUM_H_
#define CPP_PROGRAMMING_1CATS_FINITE_FIELD_HARD_VERSION_NUM_H_

class Num {
 public:
  Num(int value, int modulo);

  Num& operator=(const Num& other);

  Num operator+(const Num& other);
  Num operator-(const Num& other);
  Num operator*(const Num& other);
  Num operator+(int num);
  Num operator-(int num);
  Num operator*(int num);

  Num& operator+=(const Num& other);
  Num& operator-=(const Num& other);
  Num& operator*=(const Num& other);
  Num& operator+=(int num);
  Num& operator-=(int num);
  Num& operator*=(int num);

  int value;
  int modulo;
};

#endif //CPP_PROGRAMMING_1CATS_FINITE_FIELD_HARD_VERSION_NUM_H_

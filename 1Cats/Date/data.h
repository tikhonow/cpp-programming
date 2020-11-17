#include <iostream>
#include <string>

class Date {
 public:
  int year;
  int month;
  int day;

  Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
  }
  bool IsLeap() const {
    if (this->year % 4 != 0) {
      return false;
    } else if (this->year % 100 != 0) {
      return true;
    } else {
      return this->year % 400 == 0;
    }
  }
  std::string ToString() const {
    std::string str_day = std::to_string(this->day);
    if (str_day.length() == 1) {
      str_day = '0' + str_day;
    }
    std::string str_month = std::to_string(this->month);
    if (str_month.length() == 1) {
      str_month = '0' + str_month;
    }
    std::string str_year = std::to_string(this->year);
    while (str_year.length() != 4) {
      str_year = '0' + str_year;
    }
    std::string date = str_day + '.' + str_month + '.' + str_year;
    return date;
  }

  int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leap_months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  Date DaysLater(int days) const {
    int d = this->day;
    int m = this->month;
    int y = this->year;
    Date date(y, m, d);
    bool is_leap = date.IsLeap();
    while (days != 0) {
      date.day++;
      if (is_leap) {
        if (date.day > leap_months[date.month - 1]) {
          date.month++;
          date.day = 1;
        }
      } else {
        if (date.day > months[date.month - 1]) {
          date.month++;
          date.day = 1;
        }
      }
      if (date.month > 12) {
        date.year++;
        date.day = 1;
        date.month = 1;
      }
      days--;
    }
    return date;
  }

  int DaysLeft(const Date &date) const {
    int d = this->day;
    int m = this->month;
    int y = this->year;
    Date date_copy(y, m, d);
    int count = 0;
    bool is_leap = date_copy.IsLeap();
    while (date_copy.ToString() != date.ToString()) {
      count++;
      date_copy.day++;
      if (is_leap) {
        if (date_copy.day > leap_months[date_copy.month - 1]) {
          date_copy.month++;
          date_copy.day = 1;
        }
      } else {
        if (date_copy.day > months[date_copy.month - 1]) {
          date_copy.month++;
          date_copy.day = 1;
        }
      }
      if (date_copy.month > 12) {
        date_copy.year++;
        date_copy.day = 1;
        date_copy.month = 1;
      }
    }
    return count;
  }
};

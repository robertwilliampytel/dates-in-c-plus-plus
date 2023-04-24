#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ios>
#include <limits>

class Date {

private:

  long year;
  int month;
  int day;

  bool isLeapYear(long);
  bool isValidDate(long, int, int);

public:

  Date();
  Date(long, int, int);

  void setYear(void);
  void setMonth(void);
  void setDay(void);
  void print(void);
};

#endif

#include "Date.h"

int main() {

  Date d(2020, 2, 31);
  d.print();

  d.setDay();
  d.print();

  d.setYear();
  d.print();

  d.setMonth();
  d.print();

  return 0;
}

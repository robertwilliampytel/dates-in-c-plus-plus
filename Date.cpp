#include "Date.h"

Date::Date() {
  this->year  = 0L;
  this->month = 1;
  this->day   = 1;
}

Date::Date(long year, int month, int day) {

  if (!this->isValidDate(year, month, day))
  {
    this->year  = 0L;
    this->month = 1;
    this->day   = 1;
  }
  else
  {
    this->year  = year;
    this->month = month;
    this->day   = day;
  }
}

bool Date::isLeapYear(long year) {

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return true;
  }

  return false;
}

bool Date::isValidDate(long year, int month, int day) {

  const bool LEAP = this->isLeapYear(year);
  const int  JANUARY   = 1;
  const int  FEBRUARY  = 2;
  const int  MARCH     = 3;
  const int  APRIL     = 4;
  const int  MAY       = 5;
  const int  JUNE      = 6;
  const int  JULY      = 7;
  const int  AUGUST    = 8;
  const int  SEPTEMBER = 9;
  const int  OCTOBER   = 10;
  const int  NOVEMBER  = 11;
  const int  DECEMBER  = 12;
  const int  JANUARY_END       = 31;
  const int  FEBRUARY_END      = 28;
  const int  FEBRUARY_END_LEAP = 29;
  const int  MARCH_END         = 31;
  const int  APRIL_END         = 30;
  const int  MAY_END           = 31;
  const int  JUNE_END          = 30;
  const int  JULY_END          = 31;
  const int  AUGUST_END        = 31;
  const int  SEPTEMBER_END     = 30;
  const int  OCTOBER_END       = 31;
  const int  NOVEMBER_END      = 30;
  const int  DECEMBER_END      = 31;

  switch(month)
  {
    case JANUARY:
      return true;
      break;
    case FEBRUARY:
      return (((!LEAP) && day <= FEBRUARY_END) ||
              (  LEAP  && day <= FEBRUARY_END_LEAP));
      break;
    case MARCH:
      return day <= MARCH_END;
      break;
    case APRIL:
      return day <= APRIL_END;
      break;
    case MAY:
      return day <= MAY_END;
      break;
    case JUNE:
      return day <= JUNE_END;
      break;
    case JULY:
      return day <= JULY_END;
      break;
    case AUGUST:
      return day <= AUGUST_END;
      break;
    case SEPTEMBER:
      return day <= SEPTEMBER_END;
      break;
    case OCTOBER:
      return day <= OCTOBER_END;
      break;
    case NOVEMBER:
      return day <= NOVEMBER_END;
      break;
    case DECEMBER:
      return day <= DECEMBER_END;
      break;
    default:
      return false;
      break;
  }
}

void Date::print(void) {
  std::cout << "Day:   " << this->day   << std::endl;
  std::cout << "Month: " << this->month << std::endl;
  std::cout << "Year:  " << this->year  << std::endl;
}

// https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
void Date::setYear(void) {

  const long FOUR_BILLION_AGO = -4500000000;
  const long FOUR_BILLION_FUT = +4500000000;

  long n = -10000000000L;

  while (n < FOUR_BILLION_AGO ||
         n > FOUR_BILLION_FUT ||
         (!this->isValidDate(n, this->month, this->day)) ||
         std::cin.fail()) {

    std::cout << "Year (-4.5B to +4.5B, or -4500000000 to +4500000000):" << std::endl;

    std::cin.clear();

    std::cin  >> n;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  this->year = n;
}

// https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
void Date::setMonth(void) {

  int n = 0;

  while (n < 1  ||
         n > 12 ||
         (!this->isValidDate(this->year, n, this->day)) ||
         std::cin.fail()) {

    std::cout << "Month (1 - 12):" << std::endl;

    std::cin.clear();

    std::cin  >> n;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  this->month = n;
}

// https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
void Date::setDay(void) {

  int n = 0;

  while (n < 1  ||
         n > 31 ||
         (!this->isValidDate(this->year, this->month, n)) ||
         std::cin.fail()) {

    std::cout << "Day (1 - 31):" << std::endl;

    std::cin.clear();

    std::cin  >> n;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  this->day = n;
}
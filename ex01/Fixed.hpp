#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
 private:
  int value;
  const int fractionalBits  = 8;

 public:
  Fixed();
  Fixed(Fixed& copy);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  Fixed(const int value);
  Fixed(const float value);

  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
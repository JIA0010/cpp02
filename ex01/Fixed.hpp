#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
 private:
  int value;
  static const int fractionalBits  = 8;

 public:
  Fixed();
  Fixed(const Fixed& copy);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  Fixed(int value);
  Fixed(float value);

  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);  
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
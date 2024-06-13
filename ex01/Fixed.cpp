#include "Fixed.hpp"

/*
浮動小数点→固定小数点にコンストラクタで処理をしている。そして、使用する際には、固定小数点を使う
理由：浮動小数点の場合、小数点の桁が大きいと処理が遅くなり、精度も低くなるから
固定小数点にすることでスコープが決まっているので、精度も高いまま。
*/


Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = other.getRawBits();
     return *this;
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

Fixed::Fixed(const int value)
{

}

float Fixed::toFloat(void) const
{
    roundf(get);
}

int Fixed::toInt(void) const
{
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{}

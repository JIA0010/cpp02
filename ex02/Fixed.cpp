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

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

Fixed::Fixed(int value)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(value << fractionalBits);
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits((int)roundf(value * (1 << this->fractionalBits)));
}

float Fixed::toFloat(void) const
{
    return ((float)this->getRawBits() / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->fractionalBits);
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &rightSide)
{
  out << rightSide.toFloat();
  return out;
}

//The 6 comparison operators: >, <, >=, <=, == and !=.

bool Fixed::operator>(const Fixed& other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool  Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool  Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool  Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool  Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

//The 4 arithmetic operators: +, -, *, and /.

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

//The 4 increment/decrement 

Fixed& Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

//The 2 static functions min and max

Fixed &Fixed::min(Fixed &fixA, Fixed &fixB)
{
    return fixA.getRawBits() > fixB.getRawBits() ? fixB : fixA;
}

const Fixed &Fixed::min(const Fixed &fixA, const Fixed &fixB)
{
    return fixA.getRawBits() > fixB.getRawBits() ? fixB : fixA;
}

Fixed &Fixed::max(Fixed &fixA, Fixed &fixB)
{
    return fixA.getRawBits() > fixB.getRawBits() ? fixA : fixB;
}
const Fixed &Fixed::max(const Fixed &fixA, const Fixed &fixB)
{
    return fixA.getRawBits() > fixB.getRawBits() ? fixA : fixB;
}
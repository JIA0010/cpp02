#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = copy.getRawBits();
}



Fixed& Fixed::operator=(const Fixed &other) {
 std::cout << "Copy assignment operator called" << std::endl;
 this->value = other.getRawBits();
 return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits( int const raw )
{
    this->value  =  raw;
}
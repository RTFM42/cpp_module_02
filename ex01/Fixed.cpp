#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->_raw_ = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float float_number)
{
    std::cout << "Float constructor called" << std::endl;
    this->_raw_ = roundf(float_number * pow(2, this->_fractional_bits_));
}

Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->_raw_ = integer * static_cast<int>(pow(2, this->_fractional_bits_));
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (this->_raw_ / pow(2, this->_fractional_bits_));
}

int Fixed::toInt(void) const
{
    return (this->_raw_ / static_cast<int>(pow(2, this->_fractional_bits_)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_raw_ = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_raw_;
}

void Fixed::setRawBits(int const raw)
{
    this->_raw_ = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fi)
{
    os << fi.toFloat();
    return os;
}

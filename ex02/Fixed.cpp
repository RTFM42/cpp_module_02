#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    this->_raw_ = 0;
}

Fixed::Fixed(const int value)
{
    this->_raw_ = value << this->_fractional_bits_;
}

Fixed::Fixed(const float value)
{
    this->_raw_ = roundf(value * (1 << this->_fractional_bits_));
}

Fixed::Fixed(const Fixed &value)
{
    *this = value;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(const Fixed &value)
{
    this->_raw_ = value.getRawBits();
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

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_raw_) / (1 << this->_fractional_bits_);
}

int Fixed::toInt(void) const
{
    return this->_raw_ >> this->_fractional_bits_;
}

std::ostream &operator<<(std::ostream &os, const Fixed &value)
{
    os << value.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &value) const
{
    return this->_raw_ > value.getRawBits();
}

bool Fixed::operator<(const Fixed &value) const
{
    return this->_raw_ < value.getRawBits();
}

bool Fixed::operator>=(const Fixed &value) const
{
    return this->_raw_ >= value.getRawBits();
}

bool Fixed::operator<=(const Fixed &value) const
{
    return this->_raw_ <= value.getRawBits();
}

bool Fixed::operator==(const Fixed &value) const
{
    return this->_raw_ == value.getRawBits();
}

bool Fixed::operator!=(const Fixed &value) const
{
    return this->_raw_ != value.getRawBits();
}

Fixed Fixed::operator+(const Fixed &value) const
{
    return Fixed(this->toFloat() + value.toFloat());
}

Fixed Fixed::operator-(const Fixed &value) const
{
    return Fixed(this->toFloat() - value.toFloat());
}

Fixed Fixed::operator*(const Fixed &value) const
{
    return Fixed(this->toFloat() * value.toFloat());
}

Fixed Fixed::operator/(const Fixed &value) const
{
    return Fixed(this->toFloat() / value.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->_raw_++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    this->_raw_--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &value1, Fixed &value2)
{
    return value1 < value2 ? value1 : value2;
}

Fixed &Fixed::max(Fixed &value1, Fixed &value2)
{
    return value1 > value2 ? value1 : value2;
}

const Fixed &Fixed::min(const Fixed &value1, const Fixed &value2)
{
    return value1 < value2 ? value1 : value2;
}

const Fixed &Fixed::max(const Fixed &value1, const Fixed &value2)
{
    return value1 > value2 ? value1 : value2;
}

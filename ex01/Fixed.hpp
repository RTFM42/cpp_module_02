#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int _raw_;
    static int const _fractional_bits_ = 8;

public:
    Fixed();
    Fixed(const Fixed &cpy);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    Fixed &operator=(const Fixed &other);
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fi);

#endif

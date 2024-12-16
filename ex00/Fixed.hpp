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
    ~Fixed();
    Fixed &operator=(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif

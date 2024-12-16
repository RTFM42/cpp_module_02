#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed &operator=(const Fixed &other);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed &min(Fixed &lhs, Fixed &rhs);
    static Fixed &max(Fixed &lhs, Fixed &rhs);
    static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
    static const Fixed &max(const Fixed &lhs, const Fixed &rhs);

private:
    int _raw_;
    static const int _fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif

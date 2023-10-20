#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{

}

Fixed::Fixed(const int value) : _fixedPointValue(value << this->_fractionalBits)
{

}

Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << this->_fractionalBits)))
{

}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{

}

//------------------ Arithmetic operators ------------------//

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    float divisor = fixed.toFloat();
    if (divisor == 0)
    {    
        std::cout << "Error: Division by zero" << std::endl;
        return (Fixed());
    }
    return (Fixed(this->toFloat() / divisor));
}

//------------- Increment/Decrement operators --------------//

Fixed& Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return (*this);
}

Fixed& Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

//------------------ Comparison operators ------------------//

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

//------------- mutator and accessor functions ---------------//

int     Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

//------------------- toFloat and toInt --------------------//

float   Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int     Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

//--------------------- ostream overload -------------------//

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

//----------------------- Max and Min ----------------------//

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
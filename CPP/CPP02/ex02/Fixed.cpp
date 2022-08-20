#include "Fixed.hpp"

const int Fixed::fract_bit = 8;

Fixed::Fixed( void )
{
	num = 0;
}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
}

Fixed::Fixed(const int _num)
{
	num = _num << fract_bit;
}
Fixed::Fixed(const float _num)
{
	num = roundf(_num * (1 << fract_bit));
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits( void ) const
{
	return (num);
}

void	Fixed::setRawBits( int const raw )
{
	num = raw;
}

Fixed	&Fixed::operator= (const Fixed &a)
{
	this->setRawBits(a.getRawBits());
	return (*this);
}

float	Fixed::toFloat( void ) const
{
	return ((float)num / (1 << fract_bit));
}

int		Fixed::toInt( void ) const
{
	return (num >> fract_bit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator> (const Fixed  &a)
{
	return (num > a.getRawBits());
}
bool	Fixed::operator< (const Fixed  &a)
{
	return (num < a.getRawBits());
}
bool	Fixed::operator>= (const Fixed &a)
{
	return (num >= a.getRawBits());
}
bool	Fixed::operator<= (const Fixed &a)
{
	return (num <= a.getRawBits());
}
bool	Fixed::operator== (const Fixed &a)
{
	return (num == a.getRawBits());
}
bool	Fixed::operator!= (const Fixed &a)
{
	return (num != a.getRawBits());
}
Fixed	Fixed::operator+ (const Fixed  &a)
{
	Fixed temp(this->toFloat() + a.toFloat());

	return (temp);
}
Fixed	Fixed::operator- (const Fixed  &a)
{
	Fixed temp(this->toFloat() - a.toFloat());

	return (temp);
}
Fixed	Fixed::operator* (const Fixed  &a)
{
	Fixed temp(this->toFloat() * a.toFloat());

	return (temp);
}
Fixed	Fixed::operator/ (const Fixed  &a)
{
	Fixed temp(this->toFloat() / a.toFloat());

	return (temp);
}
Fixed	&Fixed::operator++ (void)
{
	++num;

	return *this;
}
Fixed	&Fixed::operator-- (void)
{
	--num;
	
	return *this;
}
Fixed	Fixed::operator++ (int)
{
	Fixed temp = *this;

	++num;
	return (temp);
}
Fixed	Fixed::operator-- (int)
{
	Fixed temp = *this;

	--num;
	return (temp);
}
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}
Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}
const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}
const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

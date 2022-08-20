#include "Fixed.hpp"

const int Fixed::fract_bit = 8;

Fixed::Fixed( void )
{
	num = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed::Fixed(const int _num)
{
	num = _num << fract_bit;
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float _num)
{
	num = roundf(_num * (1 << fract_bit));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	
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

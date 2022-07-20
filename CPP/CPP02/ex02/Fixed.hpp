# ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	num;
	static const int fract_bit;
public:
	Fixed( void );
	Fixed(const Fixed &source);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed	&operator= (const Fixed &a);

	bool	operator> (const Fixed  &a);
	bool	operator< (const Fixed  &a);
	bool	operator>= (const Fixed &a);
	bool	operator<= (const Fixed &a);
	bool	operator== (const Fixed &a);
	bool	operator!= (const Fixed &a);
	Fixed	operator+ (const Fixed  &a);
	Fixed	operator- (const Fixed  &a);
	Fixed	operator* (const Fixed  &a);
	Fixed	operator/ (const Fixed  &a);
	Fixed	&operator++ (void);
	Fixed	&operator-- (void);
	Fixed	operator++ (int);
	Fixed	operator-- (int);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed&	min(Fixed &a, Fixed &b);
	static Fixed&	max(Fixed &a, Fixed &b);
	static const Fixed&	min(const Fixed &a, const Fixed &b);
	static const Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
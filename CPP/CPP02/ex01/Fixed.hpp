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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
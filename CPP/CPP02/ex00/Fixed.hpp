# ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int	num;
	static const int fract_bit;
public:
	Fixed();
	Fixed(const Fixed &source);
	~Fixed();
	Fixed	&operator= (const Fixed &a);
	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
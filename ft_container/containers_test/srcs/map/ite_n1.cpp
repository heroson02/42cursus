#include "common.hpp"

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> const mp;
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(); // <-- error expected	원래 에러가 나야함 ! 근데 우리꺼는 안남

	(void)it;
	return (0);
}

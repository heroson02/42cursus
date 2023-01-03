/**
 * @file pair.hpp
 * @author your name (you@domain.com)
 * @brief pair (std::pair, std::make_pair)
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft
{
    // pair
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;
        pair(): first(), second() {}
        pair(const T1& x, const T2& y): first(x), second(y) {}
        template<class U, class V>
        pair(const pair<U, V> &p): first(p.first), second(p.second) {}
		pair& operator=( const pair& other )
		{
            if (this == &other)
                return *this;
			first = other.first;
			second = other.second;
			return (*this);
		}
    };

    template <class T1, class T2>
    bool operator==(const pair<T1,T2>& x, const pair<T1,T2>& y) { return (x.first == y.first && x.second == y.second); }
    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y) { 	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);}
    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y) { return (!(x == y)); }
    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& x, const pair<T1,T2>& y) { return y < x; }
    template <class T1, class T2>
    bool operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y) { return (!(x < y)); }
    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y) { return (!(y < x)); }

	template< class T1, class T2 >
	inline ft::pair<T1, T2> make_pair( T1 t, T2 u ) { return ( ft::pair<T1, T2>(t, u) ); }
}

#endif
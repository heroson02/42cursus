/**
 * @file random_access_iterator.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "./iterator.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator
	{
		public:
            typedef std::random_access_iterator_tag						iterator_category;
            typedef typename iterator_traits<T*>::value_type        	value_type;
            typedef typename iterator_traits<T*>::difference_type   	difference_type;
            typedef typename iterator_traits<T*>::pointer           	pointer;
            typedef typename iterator_traits<T*>::reference         	reference;	
		protected:
			pointer ptr;
		public:
            random_access_iterator() : ptr(NULL) {};
			random_access_iterator(pointer _ptr): ptr(_ptr) {};
			random_access_iterator(const random_access_iterator<T> &obj) : ptr(obj.ptr) {};
			template<typename U>
			random_access_iterator(random_access_iterator<U> other) : ptr(other.base()) {}; 
			random_access_iterator& operator=(const random_access_iterator<T> &obj)
			{
				if (this != &obj)
					ptr = obj.ptr;
				return (*this);
			};
            ~random_access_iterator() {} ;
			pointer base() const { return (ptr); }
			random_access_iterator& operator++()
            {
                ++ptr;
                return (*this);
            }
            random_access_iterator operator++(int)
            {
                random_access_iterator tmp(*this);
                ++ptr;
                return (tmp);
            }
            random_access_iterator& operator--()
            {
                --ptr;
                return (*this);
            }
            random_access_iterator operator--(int)
            {
                random_access_iterator tmp(*this);
                --ptr;
                return (tmp);
            }
			random_access_iterator operator+(const difference_type &n) const
			{
				return ptr + n;
			}
			random_access_iterator operator-(const difference_type &n) const
			{
				return ptr - n;
			}
			random_access_iterator& operator+=(const difference_type n)
			{
				ptr += n;
				return (*this);
			}
			random_access_iterator& operator-=(const difference_type n)
			{
				ptr -= n;
				return (*this);
			}
			pointer operator->() const
			{
				return (ptr);
			}
			reference operator*() const
			{
				return (*ptr);
			}
			reference operator[](difference_type n) const
			{
				return *(ptr + n);
			}
			
		};
			template< class Iterator1, class Iterator2 >
			bool operator==( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs ) { return (lhs.base() == rhs.base()); }

			template< class Iterator1, class Iterator2 >
			bool operator!=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs ) { return (lhs.base() != rhs.base()); }

			template< class Iterator1, class Iterator2 >
			bool operator<( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs ) { return (lhs.base() < rhs.base()); }

			template< class Iterator1, class Iterator2 >
			bool operator<=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs ) { return (lhs.base() <= rhs.base()); }

			template< class Iterator1, class Iterator2 >
			bool operator>( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs ) { return (lhs.base() > rhs.base()); }

			template< class Iterator1, class Iterator2 >
			bool operator>=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs ) { return (lhs.base() >= rhs.base()); }

			template< class Iterator >
			ft::random_access_iterator<Iterator> operator+( const typename ft::random_access_iterator<Iterator>::difference_type n, const ft::random_access_iterator<Iterator>& it ) { return (it + n); }

			template< class Iterator >
			ft::random_access_iterator<Iterator> operator-( const typename ft::random_access_iterator<Iterator>::difference_type n, const ft::random_access_iterator<Iterator>& it ) { return (it - n); }

			template< class Iterator >
			typename ft::random_access_iterator<Iterator>::difference_type operator+( const typename ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs ) { return (lhs.base() + rhs.base()); }

			template< class Iterator >
			typename ft::random_access_iterator<Iterator>::difference_type operator-( const typename ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs ) { return (lhs.base() - rhs.base()); }

			template < class Iterator1, class Iterator2 >
			typename ft::random_access_iterator<Iterator1>::difference_type operator-( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs )
			{
				return (lhs.base() - rhs.base());
			}
}

#endif
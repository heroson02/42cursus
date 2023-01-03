/**
 * @file reverse_iterator.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

# include "./iterator.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        
    	public:
    	    typedef Iterator											    iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer			    pointer;
            typedef typename iterator_traits<Iterator>::reference		    reference;
        private:
    	    Iterator ptr;
        public:
            reverse_iterator(): ptr() {}
            explicit reverse_iterator(iterator_type x): ptr(x) {}
            template <class U>
			reverse_iterator(const reverse_iterator<U>& u) { ptr = u.base(); }
            iterator_type base() const { return (ptr); }
            reference operator*() const
            {
                Iterator tmp = ptr;
                return (*--tmp);
            }
            pointer operator->() const { return &(operator*()); }
            reverse_iterator& operator++()
            {
                --ptr;
                return (*this);
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                --ptr;
                return (tmp);
            }
            reverse_iterator& operator--()
            {
                ++ptr;
                return (*this);
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                ++ptr;
                return (tmp);
            }
            reverse_iterator operator+ (difference_type n) const { return reverse_iterator(ptr - n); }
            reverse_iterator& operator+=(difference_type n)
            {
                ptr -= n;
                return (*this);
            }
            reverse_iterator operator- (difference_type n) const { return reverse_iterator(ptr + n); }
            reverse_iterator& operator-=(difference_type n)
			{
				ptr += n;
                return (*this);	
			}
            reference operator[](difference_type n) const { return *(*this + n); }
        
    };

    template <class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) { return (x.base() == y.base()); }
    template <class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) { return (x.base() > y.base()); }
    template <class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) { return (x.base() != y.base()); }
    template <class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) { return (x.base() < y.base()); }
    template <class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) { return (x.base() <= y.base()); }
    template <class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) { return (x.base() >= y.base()); }
    
    template < class Iterator1, class Iterator2 >
    typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return (rhs.base() - lhs.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x)
    {
        return reverse_iterator<Iterator>(x.base() - n);
    }
};

#endif
/**
 * @file iterator.hpp
 * @author your name (you@domain.com)
 * @brief iterator (iterators_traits, reverse_iterator)
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
    template <typename Iterator>
    class iterator_traits
    {
        public:
            typedef typename Iterator::iterator_category	iterator_category;
            typedef typename Iterator::value_type	        value_type;
            typedef typename Iterator::difference_type	    difference_type;
            typedef typename Iterator::pointer			    pointer;
            typedef typename Iterator::reference		    reference;
    };

    template <typename T>
    class iterator_traits<T*>
    {
        public:
            typedef std::random_access_iterator_tag  iterator_category;
            typedef T	                        value_type;
            typedef ptrdiff_t                   difference_type;
            typedef T*			                pointer;
            typedef T&		                    reference;
    };
    
    template <typename T>
    class iterator_traits<const T*>
    {
        public:
            typedef std::random_access_iterator_tag  iterator_category;
            typedef const T	                    value_type;
            typedef ptrdiff_t	                difference_type;
            typedef const T*		            pointer;
            typedef const T&	        	    reference;
    };
}

#endif

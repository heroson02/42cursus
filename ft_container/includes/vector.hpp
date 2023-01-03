/**
 * @file vector.hpp
 * @author your name (you@domain.com)
 * @brief vector
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>                               
# include "./iterator/random_access_iterator.hpp"
# include "./iterator/reverse_iterator.hpp"      
# include "./utility.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
        public:
            typedef T		                                        value_type;
            typedef typename Allocator::pointer		            	pointer;
            typedef typename Allocator::const_pointer	            const_pointer;
            typedef typename Allocator::reference		            reference;
            typedef typename Allocator::const_reference	            const_reference;
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
            typedef typename Allocator::size_type                   size_type;	
            typedef typename Allocator::difference_type             difference_type;
            typedef Allocator	allocator_type;
        private:
            pointer         m_first;
            size_type       m_size, m_capacity;
            allocator_type  m_allocator;

        public:
            // default construct
            explicit vector(const allocator_type& a = allocator_type()) : m_first(0), m_size(0), m_capacity(0), m_allocator(a) {}
            // fill constructor
            explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& a = allocator_type()) : m_size(n), m_capacity(n), m_allocator(a)
		    {
                m_first = m_allocator.allocate(n);
                for(size_type i = 0; i < n; i++)
                    m_allocator.construct(m_first + i, value);
		    }
            // range constructor (enable_if, is_integral)
            template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& a = allocator_type(), typename enable_if<!is_integral<InputIterator>::value>::type* = 0): m_allocator(a)
            {
                if (&(*first) > &(*last))
                    throw std::length_error("vector");
                m_size = std::distance(first, last);
                m_capacity = m_size;
                m_first = m_allocator.allocate(m_capacity);
                for (size_type i = 0; i < m_size; i++)
                    m_allocator.construct(m_first + i, *first++);
            }
            // copy constructor
            vector(const vector& x): m_size(0), m_capacity(0) { *this = x; }
            // destructor
            ~vector()
            {
                for (size_type i = 0; i < m_size; i++)
                    m_allocator.destroy(m_first + i);
                if(m_capacity != 0)
                    m_allocator.deallocate(m_first, m_capacity);
            }
            // operator=
			vector& operator=(const vector &x)
			{
				if (this == &x)
                    return (*this);
                for (size_type i = 0; i < m_size; i++)
                    m_allocator.destroy(m_first + i);
                m_size = x.m_size;
                if (m_capacity < m_size)
                {
                    if (m_capacity != 0)
                        m_allocator.deallocate(m_first, m_capacity);
                    m_capacity = m_size;
                    m_first = m_allocator.allocate(m_capacity);
                }
                for (size_type i = 0; i < m_size; i++)
                    m_allocator.construct(m_first + i, x[i]);
                return (*this);
			}
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
			{
                if (&(*first) > &(*last))
                    std::length_error ("vector");
                clear();
				size_type diff = std::distance(first, last);
				if (diff > m_capacity)
                {
                    if (diff > m_capacity * 2)
						reserve(diff);
					else
						reserve(m_capacity * 2);
                }
				while (diff--)
                {
					push_back(*first);
					first++;
				}
			}
            void assign (size_type n, const value_type& val)
            {
				if (n == 0)
					return ;
                clear();
                if (n > m_capacity)
                {
                    if (n > m_capacity * 2)
						reserve(n);
					else
						reserve(m_capacity * 2);
                }
                while (n--)
                    push_back(val);
            }
            allocator_type get_allocator() const { return (m_allocator); }
            
            // iterators
            iterator begin() { return iterator(m_first); }
            const_iterator begin() const { return const_iterator(m_first); }
            iterator end() { return iterator(m_first + m_size); }
            const_iterator end() const { return const_iterator(m_first + m_size); }
            reverse_iterator rbegin(){ return reverse_iterator(end()); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
            reverse_iterator rend() { return reverse_iterator(begin()); }
            const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
		   

            // capacity
            size_type size() const { return (m_size); }
            size_type max_size() const { return (m_allocator.max_size()); }
			void resize (size_type n, value_type val = value_type())
			{
				if (n < m_size)
				{
					for (size_t i = n; i < m_size; i++)
						m_allocator.destroy(m_first + i);
					m_size = n;
				}
				else if (n > m_size)
				{
					if (n > m_capacity)
					{
						if (n < m_capacity * 2)
							reserve(m_capacity * 2);
						else
							reserve(n);
					}
					for (size_t i = m_size; i < n; i++)
					{
						m_allocator.construct(m_first + i, val);
						m_size += 1;
					}
				}
			}
            size_type capacity() const { return (m_capacity); }
            bool empty() const { return (m_size == 0); }
            void reserve(size_type n)
            {
                if (n < m_capacity)
                    return ;
                if (n > max_size())
                    throw std::length_error("vector");
                pointer cp = m_allocator.allocate(n);
                try
                {
                    for (size_type i = 0; i < m_size; i++)
                        m_allocator.construct(cp + i, *(m_first + i));
                }
                catch(const std::bad_alloc& e)
                {
                    for (size_type i = 0; i < m_size; i++)
                        m_allocator.destroy(cp + i);
                    m_allocator.deallocate(cp, n);
                    throw;
                }
                for (size_type i = 0; i < m_size; i++)
                    m_allocator.destroy(m_first + i);
                if(m_capacity != 0)
                    m_allocator.deallocate(m_first, m_capacity);
                m_capacity = n;
                m_first = cp;
            }

            // element access
            reference operator[](size_type n) { return *(m_first + n); }
            const_reference operator[](size_type n) const { return *(m_first + n); }
            reference at(size_type n)
            {
                if (n >= m_size)
					throw std::out_of_range("vector");
                return *(m_first + n);
            }
			const_reference at(size_type n) const
            {
                if (n >= m_size)
					throw std::out_of_range("vector");
                return *(m_first + n);
            }
            reference front() { return (*m_first); }
            const_reference front() const { return (*m_first); }
            reference back() { return *(m_first + m_size - 1); }
            const_reference back() const { return *(m_first + m_size - 1); }

            // modifiers
            void push_back(const value_type& val)
			{
				if (m_size == m_capacity)
				{
					if (m_size == 0)
						reserve(1);
					reserve(m_capacity * 2);
				}
				m_allocator.construct(m_first + m_size, val);
				m_size++;
			}
            void pop_back()
            {
                m_allocator.destroy(m_first + m_size );
                m_size--;
			}
			iterator insert(iterator position, const value_type& val)
			{
				if (begin() > position || position > end())
                    throw std::out_of_range("vector");
                size_type diff = std::distance(begin(), position);
                if (m_size == m_capacity)
                {
                    if (m_size == 0)
                        m_capacity = 1;
                    else
                        m_capacity *= 2;
                    pointer cp = m_allocator.allocate(m_capacity);
                    for (size_type i = 0; i < diff; i++)
                    {
                        m_allocator.destroy(m_first + i);
                        m_allocator.construct(cp + i, *(m_first + i));
                    }
                    m_allocator.construct(cp + diff, val);
                    for (size_type i = m_size; i > diff; i--)
                    {
                        m_allocator.destroy(m_first + i);
						m_allocator.construct(cp + i, *(m_first + i - 1));
                    }
					m_allocator.deallocate(m_first, m_size);
                    m_first = cp;
                }
                else
                {
                    for (size_type i = m_size; i > diff; i--)
                    {
                        m_allocator.destroy(m_first + i);
                        m_allocator.construct(m_first + i, *(m_first + i - 1));
                    }
                    m_allocator.destroy(&(*position));
                    m_allocator.construct(&(*position), val);
                }
				m_size++;
                return (m_first + diff);
			}
            void insert(iterator position, size_type n, const value_type& val)
            {
                if (n == 0)
                    return ;
                else if (max_size() - m_size < n)
                    throw std::length_error ("vector");
				if (begin() > position || position > end())
                    throw std::out_of_range("vector");
                size_type diff = std::distance(begin(), position);
                if (m_size + n > m_capacity)
                {
                    size_type dealloc_capacity = m_capacity;
					if (m_size + n > m_capacity * 2)
						m_capacity = m_size + n;
                    else
                        m_capacity *= 2;
                    pointer cp = m_allocator.allocate(m_capacity);
                    for (size_type i = 0; i < diff; i++)
                    {
                        m_allocator.construct(cp + i, *(m_first + i));
                        m_allocator.destroy(m_first + i);
                    }
                    for (size_type i = 0; i < n; i++)
                        m_allocator.construct(cp + diff + i, val);
                    for (size_type i = m_size; i > diff; i--)
                    {
                        m_allocator.destroy(m_first + i);
						m_allocator.construct(cp + i + n - 1, *(m_first + i - 1));
                    }
					m_allocator.deallocate(m_first, dealloc_capacity);
                    m_first = cp;
				}
                else
                {
					for (size_type i = m_size; i > diff; i--)
                    {
                        m_allocator.destroy(m_first + i + n - 1);
						m_allocator.construct(m_first + i + n - 1, *(m_first + i - 1));
                    }
					for (size_type i = 0 ; i < n; i++)
					{
						m_allocator.destroy(m_first + i + diff);
                    	m_allocator.construct(m_first + i + diff, val);
					}
                }
                m_size += n;
            }
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
            {
				if (begin() > position || position > end() || &(*first) > &(*last))
                    throw std::out_of_range("vector");
				size_type n = std::distance(first, last);
                if (max_size() - m_size < n)
                    throw std::length_error ("vector");
                size_type diff = std::distance(begin(), position);
                if (m_size + n > m_capacity)
                {
                    size_type dealloc_capacity = m_capacity;
					if (m_size + n > m_capacity * 2)
						m_capacity = m_size + n;
                    else
                        m_capacity *= 2;
                    pointer cp = m_allocator.allocate(m_capacity);
                    try
                    {
                        for (size_type i = 0; i < diff; i++)
                        {
                            m_allocator.construct(cp + i, *(m_first + i));
                        }
                        for (size_type i = 0; i < n; i++)
                            m_allocator.construct(cp + diff + i, *first++);
                        for (size_type i = m_size; i > diff; i--)
                        {
                            m_allocator.construct(cp + i + n - 1, *(m_first + i - 1));
                        }
                    }
                    catch(...)
                    {
                        for (size_type i = 0; i < m_capacity; i++)
                            m_allocator.destroy(cp + i);
                        m_allocator.deallocate(cp, m_capacity);
                        m_capacity = 0;
                        throw;
                    }
                    for (size_type i = 0; i < m_size; i++)
                        m_allocator.destroy(m_first + i);
					m_allocator.deallocate(m_first, dealloc_capacity);
                    m_first = cp;
				}
                else
                {
					for (size_type i = m_size; i > diff; i--)
                    {
                        m_allocator.destroy(m_first + i + n - 1);
						m_allocator.construct(m_first + i + n - 1, *(m_first + i - 1));
                    }
					for (size_type i = 0 ; i < n; i++)
					{
						m_allocator.destroy(m_first + i + diff);
                    	m_allocator.construct(m_first + i + diff, *first++);
					}
                }
                m_size += n;
            }
            iterator erase(iterator position)
            {
                size_type   diff = std::distance(begin(), position);
				for (size_type i = diff; i < m_size - 1; i++)
                {
                    m_allocator.destroy(m_first + i);
					m_allocator.construct(m_first + i, *(m_first + i + 1));
                }
				m_size--;
                m_allocator.destroy(m_first + m_size - 1);
				return (begin() + diff);
            }
            iterator erase(iterator first, iterator last)
			{
                size_type   diff = std::distance(first, last);
                iterator it = first;
                while ((first + diff) != end())
                {
                    m_allocator.destroy(&(*first));
                    m_allocator.construct(&(*first), *(first + diff));
                    first++;
                }
                while (first != end())
                {
                    m_allocator.destroy(&(*first));
                    first++;
                }
                m_size -= diff;
                return (it);
			}
            void swap (vector& x)
            {
                ft::swap(m_first, x.m_first);
                ft::swap(m_size, x.m_size);
                ft::swap(m_capacity, x.m_capacity);
                ft::swap(m_allocator, x.m_allocator);
            }
            void clear()
			{
				for (size_type i = 0; i < m_size; i++)
                    m_allocator.destroy(m_first + i);
                m_size = 0;
			}
    };
    template <class T, class Allocator >
    bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {
        return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
    }
    template <class T, class Allocator>
    bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }
    template <class T, class Allocator>
    bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {
        return !(x == y);
    }
    template <class T, class Allocator>
    bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {
        return (y < x);
    }
    template <class T, class Allocator>
    bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {
        return !(x < y);
    }
    template <class T, class Allocator>
    bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
    {
        return !(y < x);
    }
}

namespace std
{
	// specialized algorithms
    template <class T, class Allocator>
    void swap(ft::vector<T,Allocator>& x, ft::vector<T,Allocator>& y) { x.swap(y); }
}

#endif

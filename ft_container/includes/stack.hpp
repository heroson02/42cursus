/**
 * @file stack.hpp
 * @author your name (you@domain.com)
 * @brief stack
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STACK_HPP
# define STACK_HPP

# include "./vector.hpp"

namespace	ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef typename Container::value_type	value_type;
            typedef typename Container::size_type	size_type;
            typedef Container 						container_type;
        protected:
            container_type c;
        public:
			explicit stack(const container_type& ctnr = container_type()): c(ctnr){}
            bool				empty() const { return c.empty(); }
            size_type			size() const { return c.size(); }
            value_type&			top() { return c.back(); }
            const value_type&	top() const { return c.back(); }
            void 				push(const value_type& x) { c.push_back(x); }
            void 				pop() { c.pop_back(); }

            
    template <class A, class Contain>
    friend bool	operator==(const stack<A, Contain>& x, const stack<A, Contain>& y) { return (x.c == y.c); }
    template <class A, class Contain>
    friend bool	operator< (const stack<A, Contain>& x, const stack<A, Contain>& y) { return (x.c < y.c); }
    template <class A, class Contain>
    friend bool operator!=(const stack<A, Contain>& x, const stack<A, Contain>& y) { return (!(x == y)); }
    template <class A, class Contain>
    friend bool operator> (const stack<A, Contain>& x, const stack<A, Contain>& y) { return (x.c > y.c); }
    template <class A, class Contain>
    friend bool operator>=(const stack<A, Contain>& x, const stack<A, Contain>& y) { return (x.c >= y.c); }
    template <class A, class Contain>
    friend bool operator<=(const stack<A, Contain>& x, const stack<A, Container>& y) { return (x.c <= y.c); }
    };
}

#endif

/**
 * @file set.hpp
 * @author your name (you@domain.com)
 * @brief set
 * @version 0.1
 * @date 2022-11-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SET_HPP
# define SET_HPP

# include "./rb_tree.hpp"
# include "./utility.hpp"
# include "pair.hpp"
# include <functional>

namespace ft
{
    template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
    class set
    {
        public:
        // types:
        typedef Key                                                                 key_type;
        typedef Key                                                                 value_type;
        typedef Compare                                                             key_compare;
        typedef Compare                                                             value_compare;
        typedef Allocator                                                           allocator_type;
        typedef typename allocator_type::pointer                                    pointer;
        typedef typename allocator_type::const_pointer                              const_pointer;
        typedef typename allocator_type::reference                                  reference;
        typedef typename allocator_type::const_reference                            const_reference;
        typedef typename allocator_type::size_type                                  size_type;
        typedef typename allocator_type::difference_type                            difference_type;
        typedef typename ft::rb_tree<key_type, key_compare, allocator_type>         tree_type;
        typedef typename tree_type::const_iterator                                        iterator;
        typedef typename tree_type::const_iterator                                  const_iterator;
        typedef typename tree_type::const_reverse_iterator		                        reverse_iterator;
        typedef typename tree_type::const_reverse_iterator	                        const_reverse_iterator;

        private:
            tree_type		m_tree;
            
        public:
        explicit set(const Compare& comp = Compare(), const allocator_type& a = allocator_type()): m_tree(comp, a) {}
        template <class InputIterator>
        set(InputIterator first, InputIterator last, const Compare& comp = Compare(), const allocator_type& a = allocator_type()): m_tree(comp, a) { insert(first, last); }
        set(const set& x): m_tree(x.m_tree) {}
        ~set() {}
        set& operator=(const set& x)
        {
            if (this != &x)
                m_tree = x.m_tree;
            return (*this);
        }        
        // iterators:
        iterator begin() { return (m_tree.begin()); }
        const_iterator begin() const { return (m_tree.begin()); }
        iterator end() { return (m_tree.end()); }
        const_iterator end() const { return (m_tree.end()); }
        reverse_iterator rbegin() { return (m_tree.rbegin()); }
        const_reverse_iterator rbegin() const { return (m_tree.rbegin()); }
        reverse_iterator rend() { return (m_tree.rend()); }
        const_reverse_iterator rend() const { return (m_tree.rend()); }
        
        // capacity:
        bool empty() const { return (m_tree.empty()); }
        size_type size() const { return (m_tree.size()); }
        size_type max_size() const { return (m_tree.max_size()); }

        // modifiers:
        ft::pair<iterator, bool> insert(const value_type& x) { return (m_tree.insert(x)); }
        iterator insert(iterator position, const value_type& x)
        {
            (void)position;
            return (m_tree.insert(x).first);
        }
        template <typename InputIterator>
        void insert(InputIterator first, InputIterator last) { m_tree.insert(first, last); }
        void erase(iterator position){ m_tree.erase(*position); }
        size_type erase(const key_type& x) { return (m_tree.erase(x)); }
        void erase(iterator first, iterator last)
        { 
            while (first != last)
                m_tree.erase(*(first++));
        }
        void swap(set& x) { m_tree.swap(x.m_tree); }
        void clear() { m_tree.clear(); }
        
        // observers:
        key_compare key_comp() const { return (key_compare()); }
        value_compare value_comp() const { return (m_tree.value_comp()); }
        
        // set operations:
        iterator find(const key_type& x) { return (m_tree.find(x)); }
        const_iterator find(const key_type& x) const { return (m_tree.find(x)); }
        size_type count(const key_type& x) const { return (m_tree.count(x)); }
        iterator lower_bound(const key_type& x) { return (m_tree.lower_bound(x)); }
        const_iterator lower_bound(const key_type& x) const { return (m_tree.lower_bound(x)); }
        iterator upper_bound(const key_type& x) { return (m_tree.upper_bound(x)); }
        const_iterator upper_bound(const key_type& x) const { return (m_tree.upper_bound(x)); }
        ft::pair<iterator,iterator> equal_range(const key_type& x) { return (m_tree.equal_range(x)); }
        ft::pair<const_iterator,const_iterator> equal_range(const key_type& x) const { return (m_tree.equal_range(x)); }
        allocator_type get_allocator() const { return m_tree.get_allocator(); }
    };

    template <class Key_, class Compare_, class Alloc>
	bool operator==(const set<Key_,Compare_,Alloc>& x, const ft::set<Key_,Compare_,Alloc>& y)
	{
		if (x.size() != y.size())
			return (false);
		return (ft::equal(x.begin(), x.end(), y.begin()));
	}
    template <class Key_, class Compare_, class Alloc>
	bool operator!=(const set<Key_,Compare_,Alloc>& x, const set<Key_,Compare_,Alloc>& y) { return (!(x == y)); }

	template <class Key_, class Compare_, class Alloc>
	bool operator< (const set<Key_,Compare_,Alloc>& x, const set<Key_,Compare_,Alloc>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <class Key_, class Compare_, class Alloc>
	bool operator> (const set<Key_,Compare_,Alloc>& x, const set<Key_,Compare_,Alloc>& y) { return (y < x); }

	template <class Key_, class Compare_, class Alloc>
	bool operator>=(const set<Key_,Compare_,Alloc>& x, const set<Key_,Compare_,Alloc>& y) { return !(x < y); }

	template <class Key_, class Compare_, class Alloc>
	bool operator<=(const set<Key_,Compare_,Alloc>& x, const set<Key_,Compare_,Alloc>& y) { return !(y < x); }

    template <class Key_, class Compare_, class Alloc>
    void swap(ft::set<Key_,  Compare_, Alloc>& x, ft::set<Key_,  Compare_, Alloc>& y) { x.swap(y); }
}

#endif
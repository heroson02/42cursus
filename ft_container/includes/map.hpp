/**
 * @file map.hpp
 * @author your name (you@domain.com)
 * @brief map
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MAP_HPP
# define MAP_HPP

# include "./rb_tree.hpp"
# include "pair.hpp"
# include <functional>

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
    {
		public:
		    // types:
			typedef Key                                         key_type;
			typedef T                                           mapped_type;
			typedef ft::pair<const key_type, mapped_type>       value_type;
			typedef Compare                                     key_compare;
			typedef Allocator                                   allocator_type;
			typedef typename allocator_type::pointer            pointer;
			typedef typename allocator_type::const_pointer      const_pointer;
			typedef typename allocator_type::reference          reference;
			typedef typename allocator_type::const_reference    const_reference;
			typedef typename allocator_type::size_type          size_type;
			typedef typename allocator_type::difference_type    difference_type;

			class value_compare
			{
				protected:
					key_compare comp;
				public:
					value_compare(key_compare c) : comp(c) {}
					bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};
            typedef typename ft::rb_tree<value_type, value_compare, allocator_type>     tree_type;
            typedef typename tree_type::iterator                                        iterator;
			typedef typename tree_type::const_iterator                                  const_iterator;
			typedef typename tree_type::reverse_iterator		                        reverse_iterator;
		    typedef typename tree_type::const_reverse_iterator	                        const_reverse_iterator;	

        private:
            tree_type		m_tree;

        public:
		    // 23.3.1.1 construct/copy/destroy:
            explicit map(const Compare& comp = key_compare(), const allocator_type& a = allocator_type()): m_tree(comp, a) {}
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const allocator_type& a = allocator_type()): m_tree(comp, a) { insert(first, last); }
            map(const map& x): m_tree(x.m_tree) {}
            ~map() {}
            map& operator=(const map& x)
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

            // 23.3.1.2 element access:
            T& operator[](const key_type& x) { return (*((this->insert(ft::make_pair(x, mapped_type()))).first)).second; }

            // modifiers:
            ft::pair<iterator, bool> insert(const value_type& x) { return (m_tree.insert(x)); }
            iterator insert(iterator position, const value_type& x) { return (m_tree.insert(position, x)); }
            template <typename InputIterator>
            void insert(InputIterator first, InputIterator last) { return (m_tree.insert(first, last)); }
            void erase(iterator position) { return (m_tree.erase(position)); }
            size_type erase(const key_type& x) { return (m_tree.erase(ft::make_pair(x, mapped_type()))); }
            void erase(iterator first, iterator last) { m_tree.erase(first, last); }
            void swap(map& x) { m_tree.swap(x.m_tree); }
            void clear() { m_tree.clear(); }

            // observers:
            key_compare key_comp() const { return (key_compare()); }
            value_compare value_comp() const { return (m_tree.value_comp()); }

            // 23.3.1.3 map operations:
            iterator find(const key_type& x) { return (m_tree.find(ft::make_pair(x, mapped_type()))); }
            const_iterator find(const key_type& x) const { return (m_tree.find(ft::make_pair(x, mapped_type()))); }
            size_type count(const key_type& x) const { return (m_tree.count(ft::make_pair(x, mapped_type()))); }
            iterator lower_bound(const key_type& x) { return (m_tree.lower_bound(ft::make_pair(x, mapped_type()))); }
            const_iterator lower_bound(const key_type& x) const { return (m_tree.lower_bound(ft::make_pair(x, mapped_type()))); }
            iterator upper_bound(const key_type& x) { return (m_tree.upper_bound(ft::make_pair(x, mapped_type()))); }
            const_iterator upper_bound(const key_type& x) const { return (m_tree.upper_bound(ft::make_pair(x, mapped_type()))); }
            ft::pair<iterator,iterator> equal_range(const key_type& x) { return (m_tree.equal_range(ft::make_pair(x, mapped_type()))); }
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& x) const { return (m_tree.equal_range(ft::make_pair(x, mapped_type()))); }
            allocator_type get_allocator() const { return m_tree.get_allocator(); }
            T& at( const Key& key )
            {
                return (*((this->insert(ft::make_pair(key, mapped_type()))).first)).second;
            }
            const T& at( const Key& key ) const
            {
                return (*((this->insert(ft::make_pair(key, mapped_type()))).first)).second;
            }
	};

	template <class Key_, class T_, class Compare_, class Alloc>
	bool operator==(const ft::map<Key_,T_,Compare_,Alloc>& x, const ft::map<Key_,T_,Compare_,Alloc>& y)
	{
		if (x.size() != y.size())
			return (false);
		return (ft::equal(x.begin(), x.end(), y.begin()));
	}
    template <class Key_, class T_, class Compare_, class Alloc>
	bool operator!=(const map<Key_,T_,Compare_,Alloc>& x, const map<Key_,T_,Compare_,Alloc>& y) { return (!(x == y)); }

	template <class Key_, class T_, class Compare_, class Alloc>
	bool operator< (const map<Key_,T_,Compare_,Alloc>& x, const map<Key_,T_,Compare_,Alloc>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <class Key_, class T_, class Compare_, class Alloc>
	bool operator> (const map<Key_,T_,Compare_,Alloc>& x, const map<Key_,T_,Compare_,Alloc>& y) { return (y < x); }

	template <class Key_, class T_, class Compare_, class Alloc>
	bool operator>=(const map<Key_,T_,Compare_,Alloc>& x, const map<Key_,T_,Compare_,Alloc>& y) { return !(x < y); }

	template <class Key_, class T_, class Compare_, class Alloc>
	bool operator<=(const map<Key_,T_,Compare_,Alloc>& x, const map<Key_,T_,Compare_,Alloc>& y) { return !(y < x); }

    template <class Key_, class T_, class Compare_, class Alloc>
    void swap(ft::map<Key_, T_, Compare_, Alloc>& x, ft::map<Key_, T_, Compare_, Alloc>& y) { x.swap(y); }
}

#endif
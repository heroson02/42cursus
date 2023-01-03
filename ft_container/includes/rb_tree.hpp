#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
# include <functional>
# include "iterator/reverse_iterator.hpp"
# include "utility.hpp"
# include "pair.hpp"

# include <iostream>

namespace ft
{
	enum color { black = 0, red = 1};

	template <typename T>
	class rb_tree_node
	{
        public:
		//Member types
		typedef	T								data_type;
		typedef	color							color_type;
		typedef	rb_tree_node<data_type>*		node_ptr;
		typedef	const rb_tree_node<data_type>*	const_node_ptr;

		//Member variables
		data_type	m_value;
		color_type	m_color;
		node_ptr	m_parent;
		node_ptr	m_left;
		node_ptr	m_right;
		
		// constructors
		rb_tree_node() : m_value(), m_color(black), m_parent(), m_left(), m_right() {}
		rb_tree_node(const rb_tree_node &obj)
            : m_value(obj.m_value), m_color(obj.m_color), m_parent(obj.m_parent), m_left(obj.m_left), m_right(obj.m_right) {}
		rb_tree_node &operator=(const rb_tree_node &obj)
		{
			if (this != &obj)
			{
				m_value = obj.m_value;
				m_color = obj.m_color;
				m_parent = obj.m_parent;
				m_left = obj.m_left;
				m_right = obj.m_right;
			}
			return (*this);
		}
        
        void flip_color()
        {
            m_color = ((m_color == red) ? black : red);
        }
	};

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T>
    bool tree_is_left_child(typename rb_tree_node<T>::node_ptr node)
    {
        if (node && node->m_parent && node->m_parent->m_left)
            return node == node->m_parent->m_left;
        else
            return false;
    }

    template <typename T>
    bool tree_is_left_child(typename rb_tree_node<T>::const_node_ptr node)
    {
        if (node && node->m_parent && node->m_parent->m_left)
            return node == node->m_parent->m_left;
        else
            return false;
    }

    template <typename T>
    typename rb_tree_node<T>::node_ptr
    tree_min(typename rb_tree_node<T>::node_ptr root)
    {
        while (root->m_left != NULL)
            root = root->m_left;
        return root;
    }

    template <typename T>
    typename rb_tree_node<T>::const_node_ptr
    tree_min(typename rb_tree_node<T>::const_node_ptr root)
    {
        while (root->m_left != NULL)
            root = root->m_left;
        return root;
    }

    template <typename T>
    typename rb_tree_node<T>::node_ptr
    tree_max(typename rb_tree_node<T>::node_ptr root)
    {
        while (root->m_right != NULL)
            root = root->m_right;
        return root;
    }

    template <typename T>
    typename rb_tree_node<T>::const_node_ptr
    tree_max(typename rb_tree_node<T>::const_node_ptr root)
    {
        while (root->m_right != NULL)
            root = root->m_right;
        return root;
    }

    // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	template <typename node_ptr, typename T>
	class rb_tree_iterator
    {
        public:
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
        
        private:
            node_ptr    m_node;

        public:
            rb_tree_iterator(): m_node() {}
            rb_tree_iterator(const rb_tree_iterator& iter): m_node(iter.m_node) {}
            rb_tree_iterator(const node_ptr& n): m_node(n) {}
            rb_tree_iterator& operator=(const rb_tree_iterator& iter)
            {
                if (this != &iter)
                    m_node = iter.m_node;
                return *this;
            }
            rb_tree_iterator& operator=(const node_ptr& ptr)
            {
                m_node = ptr;
                return *this;
            }
            reference operator*() const { return m_node->m_value; }
            pointer operator->() const { return &m_node->m_value; }
            rb_tree_iterator& operator++()
            {
                if (m_node->m_right != NULL)
                    m_node = tree_min<value_type>(m_node->m_right);
                else
				{
                    while (!tree_is_left_child<value_type>(m_node))
                        m_node = m_node->m_parent;
                    m_node = m_node->m_parent;
				}
                return *this;
            }
            rb_tree_iterator operator++(int)
            {
                rb_tree_iterator rtn(*this);
                ++(*this);
                return rtn;
            }
            rb_tree_iterator& operator--()
            {
                if (m_node->m_left != NULL)
                    m_node = tree_max<value_type>(m_node->m_left);
                else
                {
                    while (tree_is_left_child<value_type>(m_node))
                        m_node = m_node->m_parent;
                    m_node = m_node->m_parent;
                }
                return *this;
            }
            rb_tree_iterator operator--(int)
            {
                rb_tree_iterator rtn(*this);
                --(*this);
                return rtn;
            }
            node_ptr base() const
            { return m_node; }
    };

    template<typename node_ptr, typename T>
    inline bool operator==(const rb_tree_iterator<node_ptr, T>& rhs, const rb_tree_iterator<node_ptr, T>& lhs)
    { return rhs.base() == lhs.base(); }

    template<typename node_ptr, typename T>
    inline bool operator!=(const rb_tree_iterator<node_ptr, T>& rhs, const rb_tree_iterator<node_ptr, T>& lhs)
    { return rhs.base() != lhs.base(); }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename const_node_ptr, typename T>
	class rb_tree_const_iterator
    {
        public:
            typedef std::bidirectional_iterator_tag                                             iterator_category;
            typedef ptrdiff_t                                                                   difference_type;
            typedef T                                                                           value_type;
            typedef const T*                                                                    pointer;
            typedef const T&                                                                    reference;
            typedef rb_tree_iterator<typename rb_tree_node<value_type>::node_ptr, value_type>   origin_iterator;
        
        private:
            const_node_ptr    m_node;

        public:
            rb_tree_const_iterator(): m_node() {}
            rb_tree_const_iterator(const rb_tree_const_iterator& iter): m_node(iter.m_node) {}
            rb_tree_const_iterator(const origin_iterator& iter): m_node(iter.base()) {}
            rb_tree_const_iterator(const const_node_ptr& n): m_node(n) {}
            rb_tree_const_iterator& operator=(const rb_tree_const_iterator& iter)
            {
                if (this != &iter)
                    m_node = iter.m_node;
                return *this;
            }
            rb_tree_const_iterator& operator=(const const_node_ptr& ptr)
            {
                m_node = ptr;
                return *this;
            }
            reference operator*() const { return m_node->m_value; }
            pointer operator->() const { return &m_node->m_value; }
            rb_tree_const_iterator& operator++()
            {
                if (m_node->m_right != NULL)
                    m_node = tree_min<value_type>(m_node->m_right);
                else
				{
                    while (!tree_is_left_child<value_type>(m_node))
                        m_node = m_node->m_parent;
                    m_node = m_node->m_parent;
				}
                return *this;
            }
            rb_tree_const_iterator operator++(int)
            {
                rb_tree_const_iterator rtn(*this);
                ++(*this);
                return rtn;
            }
            rb_tree_const_iterator& operator--()
            {
                if (m_node->m_left != NULL)
                    m_node = tree_max<value_type>(m_node->m_left);
                else
                {
                    while (tree_is_left_child<value_type>(m_node))
                        m_node = m_node->m_parent;
                    m_node = m_node->m_parent;
                }
                return *this;
            }
            rb_tree_const_iterator operator--(int)
            {
                rb_tree_const_iterator rtn(*this);
                --(*this);
                return rtn;
            }
            const_node_ptr base() const
            { return m_node; }
    };

    template<typename const_node_ptr, typename T>
    inline bool operator==(const rb_tree_const_iterator<const_node_ptr, T>& rhs, const rb_tree_const_iterator<const_node_ptr, T>& lhs)
    { return rhs.base() == lhs.base(); }

    template<typename const_node_ptr, typename T>
    inline bool operator!=(const rb_tree_const_iterator<const_node_ptr, T>& rhs, const rb_tree_const_iterator<const_node_ptr, T>& lhs)
    { return rhs.base() != lhs.base(); }

    template<typename const_node_ptr, typename node_ptr, typename T>
    inline bool operator==(const rb_tree_const_iterator<const_node_ptr, T>& rhs, const rb_tree_iterator<node_ptr, T>& lhs)
    { return rhs.base() == lhs.base(); }

    template<typename const_node_ptr, typename node_ptr, typename T>
    inline bool operator!=(const rb_tree_const_iterator<const_node_ptr, T>& rhs, const rb_tree_iterator<node_ptr, T>& lhs)
    { return rhs.base() != lhs.base(); }

    template<typename node_ptr, typename const_node_ptr, typename T>
    inline bool operator==(const rb_tree_iterator<node_ptr, T>& rhs, const rb_tree_const_iterator<const_node_ptr, T>& lhs)
    { return rhs.base() == lhs.base(); }

    template<typename node_ptr, typename const_node_ptr, typename T>
    inline bool operator!=(const rb_tree_iterator<node_ptr, T>& rhs, const rb_tree_const_iterator<const_node_ptr, T>& lhs)
    { return rhs.base() != lhs.base(); }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class rb_tree
	{
        public:
		//member types
		typedef	ft::rb_tree_node<T>											node_type;
		typedef	T															value_type;
		typedef Compare 													value_compare;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_alloc_type;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer 						const_pointer;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::size_type							size_type;
		typedef typename allocator_type::difference_type					difference_type;
		typedef typename node_type::node_ptr								node_ptr;
		typedef typename node_type::const_node_ptr							const_node_ptr;
		typedef ft::rb_tree_iterator<node_ptr, value_type>					iterator;
		typedef ft::rb_tree_const_iterator<const_node_ptr, value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		
		//member varaiables
		size_type		m_size;
		node_type		m_parent;
		node_ptr		m_begin;
		value_compare	m_compare;
		allocator_type	m_val_alloc;
		node_alloc_type	m_node_alloc;

		//member function
        public :
            rb_tree(const value_compare &comp, const allocator_type &alloc) 
                : m_size(), m_parent(), m_begin(&m_parent), m_compare(comp), m_val_alloc(alloc), m_node_alloc(alloc) {}
			rb_tree(const rb_tree &obj)
                : m_size(), m_parent(), m_begin(&m_parent), m_compare(obj.m_compare), m_val_alloc(obj.m_val_alloc), m_node_alloc(obj.m_node_alloc)
            {
                if (obj.root() != NULL)
                {
                    root() = copy(obj.root());
                    root()->m_parent = &m_parent;
                }
            }
            ~rb_tree()
            {
                if (root() != NULL)
                {
                    destroy(root());
                    root() = NULL;
                    m_begin = end_node();
                }
            }

            rb_tree &operator=(const rb_tree &obj)
            {
                if (this != &obj)
                {
                    clear();
                    m_compare = obj.m_compare;
                    if (obj.root() != NULL)
                    {
                        root() = copy(obj.root());
                        root()->m_parent = &m_parent;
                    }
                }
                return *this;
            }

            iterator begin() { return iterator(m_begin); }
            const_iterator begin() const { return const_iterator(m_begin); }
            iterator end() { return iterator(&m_parent); }
            const_iterator end() const { return const_iterator(&m_parent); }
            reverse_iterator rbegin() { return reverse_iterator(end()); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
            reverse_iterator rend() { return reverse_iterator(begin()); }
            const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

            bool empty() const { return (m_size == 0); }
            size_type size() const { return (m_size); }
            size_type max_size() const { return (m_node_alloc.max_size()); }	// or m_value_alloc?

            ft::pair<iterator, bool> insert(const value_type& val)
            {
                iterator it = find(val);
                if (it != end())
                    return (ft::make_pair<iterator, bool>(it, false));
                node_ptr new_node = construct_node(val);
                iterator pos;
                root() = insert(root(), new_node, pos);
                root()->m_parent = &m_parent;
                insertFixUp(new_node);
                root()->m_color = black;
                return (ft::make_pair(pos, true));
            }

            iterator insert(iterator position, const value_type& val)
            {
                (void)position;
                return (insert(val).first);
            }

            template<typename InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                for (; first != last; first++)
                    insert(*first);
            }

            void erase( iterator position )
            {
                node_ptr pos = position.base();
                if (pos == m_begin)
                {
                    position++;
                    m_begin = position.base();
                }
                erase(root(), pos);
                if (root() != NULL)
                {
                    root()->m_parent = end_node();
                    root()->m_color = black;
                }
                destroy_node(pos);
            }
            
            size_type erase( const value_type& val )
            {
                iterator iter = find(val);
                if (iter == end())
                    return 0;
                erase(iter);
                return 1;
            }

            void erase( iterator first, iterator last )
            {
                while (first != last)
                    erase(first++);
            }

            
            void swap(rb_tree& t)
            {
                ft::swap(m_begin, t.m_begin);
                ft::swap(m_parent.m_left, t.m_parent.m_left);
                ft::swap(m_size, t.m_size);
                if (this->m_size != 0 && t.m_size != 0)
                	ft::swap(this->root()->m_parent, t.root()->m_parent);
                else if (this->m_size != 0)
                	this->root()->m_parent = this->end_node();
                else if (t.m_size != 0)
                	t.root()->m_parent = t.end_node();
                ft::swap(m_compare, t.m_compare);
            }

            size_type count( const value_type& val ) const { return find(val) != end(); }

            iterator find( const value_type& val )
            {
                node_ptr node = root();

                while (node != NULL)
                {
                    if (m_compare(node->m_value, val))
                        node = node->m_right;
                    else if (m_compare(val, node->m_value))
                        node = node->m_left;
                    else
                        return iterator(node);
                }
                return end();
            }
            const_iterator find( const value_type& val ) const
            {
                const_node_ptr node = root();

                while (node != NULL)
                {
                    if (m_compare(node->m_value, val))
                        node = node->m_right;
                    else if (m_compare(val, node->m_value))
                        node = node->m_left;
                    else
                        return const_iterator(node);
                }
                return end();
            }
            
            void clear()
            {
                if (root() != NULL)
                {
                    destroy(root());
                    root() = NULL;
                    m_begin = end_node();
                }
            }

            iterator lower_bound( const value_type& val )
            {
                node_ptr node = root();
                node_ptr pos = end_node();

                while (node != NULL)
                {
                    if (!m_compare(node->m_value, val)) //node->m_value <= val
                    {
                        pos = node;
                        node = node->m_left;
                    }
                    else
                        node = node->m_right;
                }
                return iterator(pos);
            }

            const_iterator lower_bound( const value_type& val ) const
            {
                const_node_ptr node = root();
                const_node_ptr pos = end_node();

                while (node != NULL)
                {
                    if (!m_compare(node->m_value, val)) //node->m_value <= val
                    {
                        pos = node;
                        node = node->m_left;
                    }
                    else
                        node = node->m_right;
                }
                return const_iterator(pos);
            }

            iterator upper_bound( const value_type& val )
            {
                node_ptr node = root();
                node_ptr pos = end_node();

                while (node != NULL)
                {
                    if (m_compare(val, node->m_value)) //node->m_value < val
                    {
                        pos = node;
                        node = node->m_left;
                    }
                    else
                        node = node->m_right;
                }
                return iterator(pos);
            }

            const_iterator upper_bound( const value_type& val ) const
            {
                const_node_ptr node = root();
                const_node_ptr pos = end_node();

                while (node != NULL)
                {
                    if (m_compare(val, node->m_value)) //node->m_value < val
                    {
                        pos = node;
                        node = node->m_left;
                    }
                    else
                        node = node->m_right;
                }
                return const_iterator(pos);
            }
            ft::pair<iterator,iterator> equal_range( const value_type& val )
            {
                return ft::make_pair(lower_bound(val), upper_bound(val));
            }
            ft::pair<const_iterator,const_iterator> equal_range( const value_type& val ) const
            {
                return ft::make_pair(lower_bound(val), upper_bound(val));
            }
            value_compare value_comp() const { return m_compare; }
            allocator_type get_allocator() const { return m_val_alloc; }

        private :
            node_ptr    &root() { return (m_parent.m_left); }
            const_node_ptr  &root() const { return (const_cast<const_node_ptr&>(m_parent.m_left)); }
            node_ptr end_node() { return &m_parent; }
            const_node_ptr end_node() const { return (const_cast<const_node_ptr>(&m_parent)); }
            node_ptr insert(node_ptr node, node_ptr new_node, iterator& pos)
            {
                if (node == NULL)
                {
                    pos = new_node;
                    return new_node;
                }
                if (m_compare(new_node->m_value, node->m_value))	// less than
                {
                    node->m_left = insert(node->m_left, new_node, pos);
                    node->m_left->m_parent = node;
                }
                else if (m_compare(node->m_value, new_node->m_value))	// greater than
                {
                    node->m_right = insert(node->m_right, new_node, pos);
                    node->m_right->m_parent = node;
                }
                else
                    pos = node;
                return node;
            }
            node_ptr replace_node(node_ptr node) const
            {
                if (node->m_left == NULL || node->m_right == NULL) //node의 자식이 0개 또는 1개일때
                    return node;
                else    // 2
                    return tree_min<value_type>(node->m_right);     //node의 자식이 2개일 때
            }
            void erase(node_ptr root, node_ptr node)
            {
                node_ptr rep_node = replace_node(node);     //node의 위치를 대체할 rep_node를 찾는다.
                node_ptr rep_child = rep_node->m_left == NULL ? rep_node->m_right : rep_node->m_left;   //rep_node의 자식(자식은 0개 혹은 1개일 수 밖에 없기 떄문)
                node_ptr sibling = NULL;

                if (rep_child != NULL)                          //rep_node의 자리를 대체해야 하기 때문에 rep_child는 rep_node의 부모를 가리키게 한다. (자식이 없을 경우 x)
                    rep_child->m_parent = rep_node->m_parent;
                if (tree_is_left_child<value_type>(rep_node))   //rep_node가 parent의 왼쪽일때
                {
                    rep_node->m_parent->m_left = rep_child;     //rep_node의 부모도 rep_child를 가리키게 한다
                    if (rep_node == root)                       //rep_node가 root일 떄 예외처리
                        root = rep_child;
                    else
                        sibling = rep_node->m_parent->m_right;
                }
                else                                            //rep_node가 parent의 오른쪽일때
                {
                    rep_node->m_parent->m_right = rep_child;
                    sibling = rep_node->m_parent->m_left;
                }
                color rep_color = rep_node->m_color;
                if (rep_node != node)                           //node의 자식이 2개일때 (replace_node()함수의 else문 일때만) rep_node의 요소 저장
                {
                    rep_node->m_parent = node->m_parent;
                    if (tree_is_left_child<value_type>(node))   //node->parent에서 rep_node로 연결
                        rep_node->m_parent->m_left = rep_node;
                    else
                        rep_node->m_parent->m_right = rep_node;
                    rep_node->m_left = node->m_left;            //node의 자식들과 rep_node를 연결한다.
                    rep_node->m_left->m_parent = rep_node;
                    rep_node->m_right = node->m_right;
                    if (rep_node->m_right != NULL)
                        rep_node->m_right->m_parent = rep_node;
                    rep_node->m_color = node->m_color;          //node에 맞게 rep_node 색 변경
                    if (node == root)
                        root = rep_node;
                }
                if (rep_color == black && root != NULL) //black + root, red + root, red + non-root 모두 해당되지 않음 (규칙 5에 어긋나지 않음)
                {
                    if (rep_child != NULL)          //자식을 black으로 바꿔서 black level 유지. (규칙 5)
                        rep_child->m_color = black;
                    else
                        rebalance_for_erase(root, rep_child, sibling);  //자식이 없을 때는 추가 조치
                }
            }
            void rebalance_for_erase(node_ptr root, node_ptr node, node_ptr sibling)
            {
                while (true)
                {
                    if (!tree_is_left_child<value_type>(sibling))
                    {
                        if (get_node_color(sibling) == red)
                        {
                            sibling->flip_color();
                            sibling->m_parent->flip_color();
                            rotate_left(sibling->m_parent);
                            if (root == sibling->m_left)
                                root = sibling;
                            sibling = sibling->m_left->m_right;
                        }
                        if (get_node_color(sibling->m_left) == black && get_node_color(sibling->m_right) == black)
                        {
                            sibling->flip_color();
                            node = sibling->m_parent;
                            if (node == root || get_node_color(node) == red)
                            {
                                node->m_color = black;
                                break;
                            }
                            sibling = get_sibling(node);
                        }
                        else
                        {
                            if (get_node_color(sibling->m_right) == black)
                            {
                                sibling->m_left->flip_color();
                                sibling->flip_color();
                                rotate_right(sibling);
                                sibling = sibling->m_parent;
                            }
                            sibling->m_color = sibling->m_parent->m_color;
                            sibling->m_parent->m_color = black;
                            sibling->m_right->m_color = black;
                            rotate_left(sibling->m_parent);
                            break;
                        }
                    }
                    else
                    {
                        if (get_node_color(sibling) == red)
                        {
                            sibling->flip_color();
                            sibling->m_parent->flip_color();
                            rotate_right(sibling->m_parent);
                            if (root == sibling->m_right)
                                root = sibling;
                            sibling = sibling->m_right->m_left;
                        }
                        if (get_node_color(sibling->m_left) == black && get_node_color(sibling->m_right) == black)
                        {
                            sibling->flip_color();
                            node = sibling->m_parent;
                            if (node == root || get_node_color(node) == red)
                            {
                                node->m_color = black;
                                break;
                            }
                            sibling = get_sibling(node);
                        }
                        else
                        {
                            if (get_node_color(sibling->m_left) == black)
                            {
                                sibling->m_right->flip_color();
                                sibling->flip_color();
                                rotate_left(sibling);
                                sibling = sibling->m_parent;
                            }
                            sibling->m_color = sibling->m_parent->m_color;
                            sibling->m_parent->m_color = black;
                            sibling->m_left->m_color = black;
                            rotate_right(sibling->m_parent);
                            break;
                        }
                    }
                }
            }
            node_ptr construct_node(const value_type& val)
            {
                node_ptr new_node = m_node_alloc.allocate(1);
                m_val_alloc.construct(&new_node->m_value, val);
                new_node->m_color = red;
                new_node->m_parent = NULL;
                new_node->m_left = NULL;
                new_node->m_right = NULL;
                if (empty() || m_compare(val, m_begin->m_value))
                    m_begin = new_node;
                ++m_size;
                return new_node;
            }
            node_ptr copy(const_node_ptr node)
            {
                if (node == NULL)
                    return NULL;
                node_ptr new_node = construct_node(node->m_value);
                new_node->m_left = copy(node->m_left);
                if (new_node->m_left != NULL)
                    new_node->m_left->m_parent = new_node;
                new_node->m_right = copy(node->m_right);
                if (new_node->m_right != NULL)
                    new_node->m_right->m_parent = new_node;
                return new_node;
            }
            void destroy_node(node_ptr node)
            {
                m_val_alloc.destroy(&node->m_value);
                m_node_alloc.deallocate(node, 1);
                m_size--;
            }
            void destroy(node_ptr node)
            {
                if (node == NULL)
                    return ;
                destroy(node->m_left);
                destroy(node->m_right);
                destroy_node(node);
            }
            node_ptr get_sibling(node_ptr node) const
            {
                if (tree_is_left_child<value_type>(node))
                    return node->m_parent->m_right;
                else
                    return node->m_parent->m_left;
            }

            color get_node_color(node_ptr node)
            {
                if (node == NULL)
                    return (black);
                else
                    return (node->m_color);
            }

            void insertFixUp(node_ptr node)
            {
                while (node != root() && get_node_color(node->m_parent) == red)
                {
                    node_ptr uncle = get_sibling(node->m_parent);
                    if (get_node_color(uncle) == red)
                    {
                        uncle->flip_color();
                        node = node->m_parent;
                        node->flip_color();
                        node = node->m_parent;
                        node->flip_color();
                    }
                    else if (tree_is_left_child<value_type>(node->m_parent))
                    {
                        if (!tree_is_left_child<value_type>(node))
                        {
                            node = node->m_parent;
                            rotate_left(node);
                        }
                        node = node->m_parent;
                        node->flip_color();
                        node = node->m_parent;
                        node->flip_color();
                        rotate_right(node);
                        break ;
                    }
                    else
                    {
                        if (tree_is_left_child<value_type>(node))
                        {
                            node = node->m_parent;
                            rotate_right(node);
                        }
                        node = node->m_parent;
                        node->flip_color();
                        node = node->m_parent;
                        node->flip_color();
                        rotate_left(node);
                        break ;
                    }
                }
            }

            void rotate_left(node_ptr node)
            {
                node_ptr right_node = node->m_right;
                node->m_right = right_node->m_left;
                if (node->m_right != NULL)
                    node->m_right->m_parent = node;
                right_node->m_parent = node->m_parent;
                if (tree_is_left_child<value_type>(node))
                    node->m_parent->m_left = right_node;
                else
                    node->m_parent->m_right = right_node;
                right_node->m_left = node;
                node->m_parent = right_node;
            }

            void rotate_right(node_ptr node)
            {
                node_ptr left_node = node->m_left;
                node->m_left = left_node->m_right;
                if (node->m_left != NULL)
                    node->m_left->m_parent = node;
                left_node->m_parent = node->m_parent;
                if (tree_is_left_child<value_type>(node))
                    node->m_parent->m_left = left_node;
                else
                    node->m_parent->m_right = left_node;
                left_node->m_right = node;
                node->m_parent = left_node;
            }

        
	};
    template<typename T, typename Compare, typename Alloc>
    void swap(rb_tree<T, Compare, Alloc>& first, rb_tree<T, Compare, Alloc>& second) { first.swap(second); }
}

#endif
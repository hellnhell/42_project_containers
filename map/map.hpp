#ifndef MAP_HPP
# define MAP_HPP

# include "Tree.hpp"
# include <cstddef>
# include <limits.h>
# include <stdexcept>
# include "../utils.hpp"
# include "map_iterator.hpp"
# include <memory>

namespace ft
{
        template <class Key>
        struct less: std::binary_function<Key, Key, bool> {
                bool operator() (const Key &x, const Key &y) const { return x < y; }
        };

        template <typename Key, typename T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<Key, T> > > 
        class map
        {
             
                public:
                        typedef Key                                     key_type;
                        typedef T                                       mapped_type;
                        typedef pair<const key_type, mapped_type>       value_type;
                        typedef Compare                                 key_compare;
                        typedef value_type                              &ref;
                        typedef const value_type                        &const_ref;
                        typedef value_type                              *ptr;
                        typedef const value_type                        *const_ptr;
                        typedef Alloc                                   allocator_type;
                        typedef typename Alloc::size_type               size_type;
                        typedef MapIterator<Key, T>                     iterator;
                        typedef const iterator                          const_iterator;
                        typedef MapReverseIterator<Key, T>              reverse_iterator;
                        typedef const reverse_iterator                  const_reverse_iterator;
                        typedef std::ptrdiff_t                          difference_type;

                        explicit        map(const key_compare &comp = key_compare())
                        {
                                (void)comp;
                                _talloc = Tree_alloc_type();
                                _val = _talloc.allocate(1);
                                _talloc.construct(_val);

                        }

                        template <typename InputIterator>
                        map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
                        {
                                (void)comp;
                                (void)alloc;
                                _talloc = Tree_alloc_type();
                                _val = _talloc.allocate(1);
                                _talloc.construct(_val);
                                while(first != last)
                                {
                                        _val->add((*first).first, (*first).second);
                                        first++;
                                }
                        }

                        map(const map &m)
                        {
                                _talloc = Tree_alloc_type();
                                iterator it = m.begin();
                                _val = _talloc.allocate(1);
                                _talloc.construct(_val);
                                while (it != m.end())
                                {
                                        _val->add((*it).first, (*it).second);
                                        it++;
                                }
                        }

                        ~map() { _talloc.destroy(_val); _talloc.deallocate(_val, 1); }

                        map     &operator=(const map &m)
                        {
                                _talloc.destroy(_val);
                                _talloc.deallocate(_val, 1);
                                _val = _talloc.allocate(1);
                                _talloc.construct(_val);
                                map::iterator it = m.begin();
                                while (it != m.end())
                                {
                                        _val->add((*it).first, (*it).second);
                                        it++;
                                }
                                return *this;
                        }

                        iterator              begin() { return iterator(_val->get_begin()); }
                        const_iterator        begin() const { return const_iterator(_val->get_begin()); }
                        iterator              end() { return iterator(_val->get_end()); }
                        const_iterator        end() const { return const_iterator(_val->get_end()); }

                        reverse_iterator              rbegin() { return reverse_iterator(_val->get_rbegin()); }
                        const_reverse_iterator        rbegin() const { return const_reverse_iterator(_val->get_rbegin()); }
                        reverse_iterator              rend() { return reverse_iterator(_val->get_rend()); }
                        const_reverse_iterator        rend() const { return const_reverse_iterator(_val->get_rend()); }


                        bool    empty() const { return !_val->size; }
                        size_type size() const { return _val->size; }
                        size_type max_size() const { return allocator_type().max_size() / 5; } //?

                        mapped_type &operator[](const key_type &k)
                        {
                                if (count(k) == 0)
                                        _val->add(k, T());
                                Node<ft::pair<Key, T> > *node = _val->find(k);
                                return node->_data.second;
                        }

                        iterator insert(iterator position, const value_type &val)
                        {
                                _val->add(val.first, val.second, get_node(position));
                                return insert(val).first;
                        }

                        ft::pair<iterator, bool> insert(const value_type &val)
                        {
                                Node<ft::pair<Key, T> > *node = _val->find(val.first);
                                if (node != NULL)
                                {
                                       return ft::make_pair(iterator(node), false);
                                }
                                node = _val->add(val.first, val.second);
                                iterator it = iterator(node);
                                ft::pair<iterator, bool> _pair = ft::make_pair(it, true);
                                return _pair;
                        }

                        template<class InputIterator>
                        void    insert(InputIterator first, InputIterator last)
                        {
                                while (first != last)
                                {
                                        value_type val = value_type((*first).first, (*first).second);
                                        insert(val);
                                        first++;
                                }
                        }

                        void    erase(iterator position)
                        {
                                _val->remove(get_node(position));
                        }
                        
                        size_type erase(const key_type &key)
                        {
                                Node<ft::pair<Key, T> > *node = _val->find(key);
                                if (!node)
                                        return 0;
                                _val->remove(node);
                                return 1;
                        }

                        void    erase(iterator first, iterator last)
                        {
                           while (first != last)
                           {
                                Node<ft::pair<Key, T> > *node = get_node(first);
                                first++;
                                _val->remove(node);        
                           }
                        }

                        void    swap(map &m)
                        {
                                Tree<Key, T, Compare, Alloc> *tmp = _val;
                                _val = m._val;
                                m._val = tmp;
                        }

                        void    clear()
                        {
                                map::iterator it = begin();
                                while (it != end() + 1)
                                {
                                        Node<ft::pair<Key, T> > *node = get_node(it);
                                        _val->remove(node);
                                        it++;
                                }

                        }

                        key_compare     key_comp() const { return Compare(); };

                        class value_compare
                        {
                                friend class map;
                                protected:
                                        Compare comp;
                                        value_compare() {};
                                        value_compare (Compare c) : comp(c) {};
                                public:
                                        typedef bool        result_type;
                                        typedef value_type first_argument_type;
                                        typedef value_type second_argument_type;
                                        bool operator() (const value_type& x, const value_type& y) const
                                        {
                                                return comp(x.first, y.first);
                                        }
                        };
                        value_compare   value_comp() const { return value_compare(); }

                        iterator    find(const key_type &k)
                        {
                                Node<ft::pair<Key, T> > *node = _val->find(k);
                                if (node == NULL)
                                        return end();
                                return iterator(node);
                        };

                        const_iterator    find(const key_type &k) const
                        {
                                Node<ft::pair<Key, T> > *node = _val->find(k);
                                if (node == NULL)
                                        return end();
                                return const_iterator(node);
                        };

                        size_type count(const key_type &k) const 
                        {
                                Node<ft::pair<Key, T> > *node = _val->find(k);
                                if (node == NULL)
                                        return 0;
                                return 1;
                        }

                        iterator lower_bound(const key_type &k)
                        {
                                if (count(k))
                                        return find(k);
                                map::iterator it = begin();
                                while (it != end() && !key_compare()(k, (*it).first))
                                        it++;
                                return it;
                        }

                        const_iterator lower_bound(const key_type &k) const
                        {
                                 if (count(k))
                                        return find(k);
                                map::const_iterator it = begin();
                                while (it != end() && !key_compare()(k, (*it).first))
                                        it++;
                                return it;
                        }


                        iterator upper_bound(const key_type &k)
                        {
                                map::iterator it = begin();
                                while (it != end() && !key_compare()(k, (*it).first))
                                        it++;
                                return it;
                        }

                        const_iterator upper_bound(const key_type &k) const
                        {
                                 if (count(k))
                                        return find(k);
                                map::const_iterator it = begin();
                                while (it != end() && !key_compare()(k, (*it).first))
                                        it++;
                                return it;
                        }

                        pair<iterator,iterator> equal_range (const key_type& k)
                        {
                                pair<iterator, iterator> _pair(lower_bound(k), upper_bound(k));
                                return _pair;
                        }

                        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
                        {
                                pair<const_iterator, const_iterator> _pair(lower_bound(k), upper_bound(k));
                                return _pair;
                        }

            

                   private:
                        typedef typename Alloc::template rebind<Tree<Key, T, Compare, Alloc> >::other Tree_alloc_type;
                        Tree<Key, T, Compare, Alloc>         *_val;
                        Tree_alloc_type                      _talloc;

                        Node<ft::pair<Key, T> > *get_node(iterator it) { return (_val->find(it->first)); }

        };

        template<typename Key, typename T, typename Alloc>
        void    swap(ft::map<Key, T, Alloc> &m1, ft::map<Key, T, Alloc> &m2)
        {
                m1.swap(m2);
        };      
       
}
#endif
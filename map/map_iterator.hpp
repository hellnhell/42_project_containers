#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iterator>
# include "Node.hpp"


typedef size_t size_type;

template<typename Key, typename Value>
class MapIterator : public std::iterator<std::input_iterator_tag, Key, Value>
{

    private:
        Node<ft::pair<Key, Value> > *p;

    public:
        MapIterator() {};
        MapIterator(Node<ft::pair<Key, Value> > *nd) : p(nd) {};
        MapIterator(const MapIterator &mi) : p(mi.p) {};
        
        bool operator==(const MapIterator &m) const { return p == m.p; };
        bool operator!=(const MapIterator &m) const { return p != m.p; };

        ft::pair<Key, Value> &operator*() { return p->_data; };
        ft::pair<Key, Value> *operator->() const { return &p->_data; };
        
        MapIterator &operator++()
        {
            if (p)
            {
                if (p->right)
                {
                    p = p->right;
                    while (p->left)
                        p = p->left;
                }
                else
                {
                    while(p->parent && p == p->parent->right)
                        p = p->parent;
                    p = p->parent;
                }
            }
            return *this;
        }

        template <class Y>
        MapIterator operator++(Y)
        {
            MapIterator ret(*this);
            operator++();
            return ret;
        }

        MapIterator &operator--()
        {
            if (p)
            {
                if (p->left)
                {
                    p = p->left;
                    while (p->right)
                        p = p->right;
                }
                else
                {
                    while (p->parent && p == p->parent->left)
                        p = p->parent;
                    p = p->parent;
                }
            }
            return *this;
        }

        template <class Y>
        MapIterator operator--(Y)
        {
            MapIterator ret(*this);
            operator--();
            return ret;
        }

        MapIterator operator+(size_type n)
        {
            MapIterator ret(*this);
            while (n > 0)
            {
                ret++;
                n--;
            }
            while (n < 0)
            {
                ret--;
                n++;
            }
            return ret;
        }

        MapIterator operator-(size_type n)
        {
            MapIterator ret(*this);
            while (n > 0)
            {
                ret--;
                n--;
            }
            while (n < 0)
            {
                ret++;
                n++;
            }
            return ret;
        }

};

template<typename Key, typename Value>
class MapReverseIterator : public std::iterator<std::input_iterator_tag, Key, Value>
{

    private:
        Node<ft::pair<Key, Value> > *p;

    public:
        MapReverseIterator(Node<ft::pair<Key, Value> > *nd) : p(nd) {};
        MapReverseIterator(const MapReverseIterator &m) : p(m.p) {};
        
        bool operator==(const MapReverseIterator &m) const { return p == m.p; };
        bool operator!=(const MapReverseIterator &m) const { return p != m.p; };

        ft::pair<Key, Value> &operator*() const { return p->_data; };
        ft::pair<Key, Value> *operator->() const { return &p->_data; };

        MapReverseIterator &operator++()
        {
            if (p)
            {
                if (p->left)
                {
                    p = p->left;
                    while (p->right)
                        p = p->right;
                }
                else
                {
                    while(p->parent && p == p->parent->left)
                        p = p->parent;
                    p = p->parent;
                }
            }
            return *this;
        }

        template <class Y>
        MapReverseIterator operator++(Y)
        {
            MapReverseIterator ret(*this);
            operator++();
            return ret;
        }

        MapReverseIterator &operator--()
        {
            if (p)
            {
                if (p->right)
                {
                    p = p->right;
                    while (p->left)
                        p = p->left;
                }
                else
                {
                    while (p->parent && p == p->parent->right)
                        p = p->parent;
                    p = p->parent;
                }
            }
            return *this;
        }

        template <class Y>
        MapReverseIterator operator--(Y)
        {
            MapReverseIterator ret(*this);
            operator--();
            return ret;
        }

        MapReverseIterator operator+(size_type n)
        {
            MapReverseIterator ret(*this);
            while (n > 0)
            {
                ret++;
                n--;
            }
            while (n < 0)
            {
                ret--;
                n++;
            }
            return ret;
        }

        MapReverseIterator operator-(size_type n)
        {
            MapReverseIterator ret(*this);
            while (n > 0)
            {
                ret--;
                n--;
            }
            while (n < 0)
            {
                ret++;
                n++;
            }
            return ret;
        }

};
#endif
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <limits>
# include "reverse_iterator.hpp"
# include <stdexcept>
# include <cstring>
# include <chrono>
# include "../utils.hpp"



namespace ft
{
    template <typename T>
    class vectorIterator
    {
        public:
            typedef T   value_type;
            typedef value_type * pointer;
            typedef const value_type * const_pointer;
            typedef value_type & reference;
            typedef const value_type & const_reference;
            typedef std::size_t     size_type;
            typedef std::ptrdiff_t  difference_type;

        private:
            pointer _ptr;

        public:
            vectorIterator() : _ptr(nullptr) {};
            vectorIterator(const pointer &ptr) : _ptr(ptr) {};
            vectorIterator(const vectorIterator &src) : _ptr(src._ptr) {};
            virtual ~vectorIterator() {};
            vectorIterator &operator=(const vectorIterator &src) {
                if (this == &src)
                    return *this;
                this->_ptr = src._ptr;
                return *this;
            }
            
            pointer getPointer() const {return _ptr;}

            vectorIterator &operator++() {++_ptr; return *this;}                                        //it to next elemnt
            vectorIterator &operator--() {--_ptr; return *this;}                                        //it to back element
            vectorIterator operator++(int) {vectorIterator(_ptr++); return *this;}   //postfix increment
            vectorIterator operator--(int) {vectorIterator(_ptr--); return *this;}   //postfix decrement
            vectorIterator operator+(difference_type n) {return vectorIterator(_ptr + n);}                                   //ret an it pointing n elemnts after the it's called
            vectorIterator operator-(difference_type n) {return vectorIterator(_ptr - n);}                                   //ret an it pointing n elements before the it's call
            vectorIterator operator+=(difference_type n) {_ptr += n; return *this;}                          //increment it n elemnts (inc operator * n)
            vectorIterator operator-=(difference_type n) {_ptr -= n; return *this;}                          //decrement it n elemnts
            
            reference operator*() const {return *this->_ptr;}    //dereferencing op ret & to the elemnt wich it is pointing
            const_reference operator*() {return *this->_ptr;} 
            pointer operator->() const {return this->_ptr;} //mmbr selection op ret a * to the elemnt wich it is pointing
            const_pointer operator->() {return this->_ptr;}
            reference operator[](const size_type& n) {return _ptr[n];} //indexing op ret a & to elemnt n elemnts after elemnt pointed by it
            const_reference operator[](const size_type& n) const {return _ptr[n];}
            difference_type operator-(const vectorIterator &vi) const {return this->_ptr - vi.getPointer();} //return de diff bt 2 its
            
            bool operator==(const vectorIterator &vi) const {return _ptr == vi.getPointer();}
            bool operator!=(const vectorIterator &vi) const {return _ptr != vi.getPointer();}
            bool operator<=(const vectorIterator &vi) const {return _ptr <= vi.getPointer();}
            bool operator>=(const vectorIterator &vi) const {return _ptr >= vi.getPointer();}
            bool operator<(const vectorIterator &vi) const {return _ptr < vi.getPointer();}
            bool operator>(const vectorIterator &vi) const {return _ptr > vi.getPointer();}
            
    };

    template <typename T, typename Alloc = std::allocator<T> >
    class vector
    {

         //////////////////
        // MEMBER TYPES //
       //////////////////

        public:
            typedef T                                               value_type;
            typedef Alloc                                           allocator_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef ft::vectorIterator<value_type>                  iterator;
            typedef ft::vectorIterator<value_type const>            const_iterator;
            typedef ft::reverseIterator<iterator>                   reverse_iterator;
            typedef ft::reverseIterator<iterator const>             const_reverse_iterator;
            typedef	std::ptrdiff_t                                  difference_type;
	        typedef	typename allocator_type::size_type              size_type;

        private:
            allocator_type  _alloc;
            pointer         _val;
            size_type       _size;
            size_type       _capacity;

         ///////////////////////
        // MEMEBER FUNCTIONS //
       ///////////////////////
        public:   
            //default - empty constructor
            explicit vector(const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _val = _alloc.allocate(0);
                _size = 0;  //u_nullptr?
                _capacity = 0;
            }
            
            //fill  - with n elemnts each a copy of value
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _val = _alloc.allocate(n);
                _size = n;
                _capacity = n;
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_val + i, val);
            }

            //range - as many elemnts as the range first-last
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename std::enable_if<!std::is_same<InputIterator, int>::value>::type* = 0)
            {
                size_type  n = 0;
                for (InputIterator tmp = first; tmp != last; tmp++)
                    n++;
                _alloc = alloc;
                _size = n;
                _capacity = n;
                _val = _alloc.allocate(n);
                for (size_type i = 0; i != n; i++)
                {
                    _alloc.construct(_val + i, *first);
                    first++;
                }
            }

            //copy - each elemnt in v
            vector(const vector& x)
            {
                _alloc = x._alloc;
                _capacity = x._capacity;
                _size = x._size;
                _val = _alloc.allocate(x._capacity);
                for (size_type i = 0; i < x._size; i++)
                    _alloc.construct(_val + i, x[i]);
            }

        /////////////////
        // DESTRUCTORS //
        /////////////////
            virtual ~vector() 
            {
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_val + i);
                _alloc.deallocate(_val, _capacity);
            }


			vector &operator=(const vector &src)
			{
				if (this == &src)
					return (*this);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_val + i);
                _alloc.deallocate(_val, _capacity);
				if (src._size > _capacity)
				{
					_alloc.deallocate(_val, _capacity);
					_capacity = src._capacity;
					_val = _alloc.allocate(_capacity);
				}
				_size = src._size;
                if (src._capacity == 0)
				    _capacity = src._capacity;
				_val = _alloc.allocate(src._capacity);
				for (size_type i = 0; i != src._size; i++)
					_alloc.construct(_val + i, src[i]);
				return (*this);
			}

        ///////////////
       // ITERATORS //
      ///////////////

        iterator    begin()
        {
            return iterator(this->_val);
        }

        const_iterator    begin() const
        {
            return const_iterator(this->_val);
        }

        iterator    end()
        {
            return iterator(this->_val + this->_size);
        }

        const_iterator    end() const
        {
            return const_iterator(this->_val + this->_size);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(this->end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(this->begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(this->begin());
        }
        
       //////////////
      // CAPACITY //
     //////////////

        size_type    size() const
        {
            return (this->_size);
        }

        size_type max_size() const
        {
            return (_alloc.max_size());
        }

        void resize(size_type n, value_type val = value_type())
        {
            if (n < this->_size)
                erase(begin() + n, end());
            if (n > this->_size)
                insert(end(), n - this->_size, val);
            if (n > this->_capacity)
                reserve(n);
        }

        size_type capacity() const
        {
            return this->_capacity;
        }

        bool empty() const
        {
            return this->_size == 0;
        }

        void reserve(size_type n)
        {
            	if (n > _alloc.max_size())
					throw std::length_error("n exceed max size!");
				if (n > _capacity)
				{
					T *	new_vec = _alloc.allocate(n);
					for (size_type i = 0; i != _size; i++)
					{
						_alloc.construct(new_vec + i, _val[i]);
						_alloc.destroy(_val + i);
					}
					_alloc.deallocate(_val, _capacity);
					_capacity = n;
					_val = new_vec;
				}
		}
 

       ////////////////////
      // ELEMENT ACCESS //
     ////////////////////

        reference operator[](size_type n) {return (_val[n]);}
        const_reference operator[](size_type n) const {return (_val[n]);}

        reference at(size_type n)
        {
            if (n >= this->_size)
                throw std::out_of_range("vector::out of range");
            else
                return _val[n];
        }

        const_reference at(size_type n) const
        {
            if (n >= this->_size)
                throw std::out_of_range("vector::out of range");
            else
                return _val[n];
        }

        reference front() {return this->_val[0];}
        const_reference front() const {return this->_val[0];}

        reference back() {return this->_val[_size - 1];}
        const_reference back() const {return this->_val[_size - 1];}

       ///////////////
      // MODIFIERS //
     ///////////////

        //assing range - the new contents are elements constructed from each elemnts in the range in order
        template <class InputIterator>
            void assign(InputIterator first, InputIterator last,
            typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
            {
                clear();
                insert(begin(), first, last);
            }
        
        //asign fill - the new contents are n elements, each init as val
        void assign(size_type n, const value_type& val)
        {
            clear();
            insert(begin(), n, val);
        }

        void push_back(const value_type& val) { insert(end(), val);}

        void pop_back() { erase(end() - 1);}

        //insert single element
        iterator insert(iterator position, const value_type& val)
        {
            size_type init = 1;
            insert(position, init, val);
            return ++position;
        }

        //insert fill
        void insert(iterator position, size_type n, const value_type& val)
        {
            iterator it = this->begin();
            difference_type index = 0;
            
            while (it != position)
            {
                ++it;
                ++index;
            }
            if (!n)
                return ;
            if (_size + n > _capacity)
                this->reserve(_size + n);
            for (ptrdiff_t i = _size - 1; i >= (ptrdiff_t)index;  i--)
            {
                _alloc.construct(&_val[i + n], _val[i]);
                _alloc.destroy(&_val[i]);
            }
            for (size_type i = index; i < index + n; i++)
                _alloc.construct(&_val[i], val);
            _size +=  n;
        }

        //insert range
        template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
            {
                iterator it = this->begin();
                size_type index = 0;
                size_type n = last - first;
                
                if (_size + n > _capacity)
                    this->reserve(n + _size);
                while (it != position)
                {
                    ++it;
                    ++index;
                }
                if (!n)
                    return ;
                for (ptrdiff_t i = _size - 1; i >= (ptrdiff_t)index;  i--)
                {
                    _alloc.construct(&_val[i + n], _val[i]);
                    _alloc.destroy(&_val[i]);
                }
                for (iterator it2 = first; it2 != last; it2++)
                        _alloc.construct(&_val[index++], *it2);
                _size = _size + n;
            }

        //erase
        iterator erase(iterator position) { return erase(position, position + 1); }

        iterator erase(iterator first, iterator last)
        {
            iterator it = begin();
            size_type rng = last - first;
            size_type index = 0;
            while (it != first)
            {
                ++it;
                ++index;
            }
            if (rng <= 0)
                return last;
            for (size_type i = index; i < index + rng; i++)
                _alloc.destroy(&_val[i]);
            for (size_type i = index + rng; i < _size; i++)
            {
                _alloc.construct(&_val[i - rng], _val[i]);
                _alloc.destroy(&_val[i]);
            }
            _size = _size - rng;
            return first;
        }

        void swap(vector& x)
        {
            ft::swap(this->_alloc, x._alloc);
            ft::swap(this->_val, x._val);
            ft::swap(this->_size, x._size);
            ft::swap(this->_capacity, x._capacity);
        }

        void clear() { erase(this->begin(), this->end()); }

        allocator_type get_allocator() const { return _alloc; }

    };

    template<typename T>
    bool operator==(vector<T> const &lhs, vector<T> const &rhs) {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }

    template<typename T>
    bool operator!=(vector<T> const &lhs, vector<T> const &rhs) {
        return (!(lhs == rhs));
    }

    template<typename T>
    bool operator<(vector<T> const &lhs, vector<T> const &rhs) {
        int i = 0;
        int x;

        if (lhs.size() > rhs.size())
            x = rhs.size();
        else
            x = lhs.size();
        while (i < x)
        {
            if (lhs[i] != rhs[i])
                return lhs[i] < rhs[i];
            i++;
        }
        return lhs.size() < rhs.size();
    }

    template<typename T>
    bool operator>(vector<T> const &lhs, vector<T> const &rhs) {
        return (rhs < lhs);
    }

    template<typename T>
    bool operator<=(vector<T>const &lhs, vector<T>const &rhs) {
        return (!(rhs < lhs));
    }

    template<typename T>
    bool operator>=(vector<T>const &lhs, vector<T>const &rhs) {
        return (!(lhs < rhs));
    }

    template<typename T>
    void swap(vector<T>& x, vector<T>& y){
        x.swap(y);
    }
}

#endif
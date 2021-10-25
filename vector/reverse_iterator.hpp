#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>

namespace ft
{
    template <typename It>
    class reverseIterator : public It
    {
        public:

            using typename It::value_type;
            using typename It::pointer;
            using typename It::const_pointer;
            using typename It::reference;
            using typename It::const_reference;
            using typename It::size_type;
            using typename It::difference_type;

        private:
            It _base;
            reverseIterator();

        public:
            reverseIterator(It base) : _base(base) {};
            reverseIterator(const reverseIterator &src) : _base(src._base) {};
            virtual ~reverseIterator() {};
            reverseIterator &operator=(const reverseIterator &src) {
                if (this == &src)
                    return *this;
                this->_base = src._base;
                return *this;
            }
            
            reverseIterator &operator++() {--_base; return *this;}
            reverseIterator &operator--() {++_base; return *this;}
            reverseIterator operator++(int) {reverseIterator tmp(_base--); return tmp;}
            reverseIterator operator--(int) {reverseIterator tmp(_base++); return tmp;}
            reverseIterator &operator+=(int n) {_base -= n; return *this;}
            reverseIterator &operator-=(int n) {_base += n; return *this;}

            
            reference operator*() const {It tmp(_base); return (*--tmp);}
            const_reference operator*() {It tmp(_base); return (*--tmp);}
            pointer operator->() const {It tmp(_base); return &(*--tmp);} //mirar el const
            const_pointer operator->() {It tmp(_base); return &(*--tmp);}

     

            difference_type operator-(const reverseIterator &vi) const {return _base - vi._base;}
            
            bool operator==(const reverseIterator &vi) const {return _base == vi._base;}
            bool operator!=(const reverseIterator &vi) const {return _base != vi._base;}
            bool operator<=(const reverseIterator &vi) const {return _base >= vi._base;}
            bool operator>=(const reverseIterator &vi) const {return _base <= vi._base;}
            bool operator<(const reverseIterator &vi) const {return _base > vi._base;}
            bool operator>(const reverseIterator &vi) const {return _base < vi._base;}
    };

    template<class value_type>
        bool equal(value_type const &a, value_type const &b) {
	        return (a == b);
    }

    template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
    
}
#endif
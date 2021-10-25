#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
  template <class T1, class T2>
  struct pair {
    typedef T1   first_type;
    typedef T2   second_type;

    pair() : first(), second() {};
    pair (const first_type &a, const second_type &b) : first(a), second(b) {};

    template<class U, class V>
    pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) {};

    ~pair() {};

    pair<T1, T2>  &operator= (const pair<T1, T2> &pr) {
      first = pr.first;
      second = pr.second;
      return *this;
    };

    first_type  first;
    second_type second;
  };

	template <class T1, class T2>
  	ft::pair<T1,T2> make_pair (T1 x, T2 y) {
	  return ft::pair<T1, T2>(x, y);
  }
};

namespace ft {
	struct __true_type { };
	struct __false_type { };

	template<typename _Tp>
	struct __is_interger
	{
		enum { __value = 0};
		typedef __false_type __type;
	};

	template<>
	struct __is_interger<bool>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<char>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<signed char>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<unsigned char>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<wchar_t>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<short>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<unsigned short>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<int>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<unsigned int>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<long>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<unsigned long>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<long long>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};

	template<>
	struct __is_interger<unsigned long long>
	{
		enum { __value = 1 };
		typedef __true_type __type;
	};
};

namespace ft {
	template<bool B, class T = void>
	struct enable_if {
	};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
};

namespace ft
{
	template <class Iterator>
		class iterator_traits
		{
			public:
				typedef typename Iterator::difference_type		difference_type;
				typedef typename Iterator::value_type			value_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;
				typedef typename Iterator::iterator_category	iterator_category;
		};
	template <class T>
		class iterator_traits<T*>
		{
			public:
				typedef ptrdiff_t								difference_type;
				typedef	T										value_type;
				typedef T*										pointer;
				typedef T&										reference;
				typedef std::random_access_iterator_tag				iterator_category;
		};
	template <class T>
		class iterator_traits<const T*>
		{
			public:
				typedef ptrdiff_t								difference_type;
				typedef	T										value_type;
				typedef const T*								pointer;
				typedef const T&								reference;
				typedef std::random_access_iterator_tag			iterator_category;	
		};
};

namespace ft {
	    template <class IT1, class IT2>
        bool lexicographical_compare (IT1 first1, IT1 last1,
                                        IT2 first2, IT2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1) return false;
                else if (*first1 < *first2) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }

    template <class IT1, class IT2, class Compare>
        bool lexicographical_compare (IT1 first1, IT1 last1,
                                        IT2 first2, IT2 last2,
                                        Compare comp)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || comp(*first2, *first1)) return false;
                else if (comp(*first1, *first2)) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
}

#endif
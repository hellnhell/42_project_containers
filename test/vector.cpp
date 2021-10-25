/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:14:11 by emartin-          #+#    #+#             */
/*   Updated: 2021/10/25 15:45:29 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <typename T1, typename T2>
bool ITERATE_VECTOR(T1 &ft, T2 &st) {
    typename T1::iterator it = ft.begin();
    typename T2::iterator sit = st.begin();

    while (it != ft.end() || sit != st.end()) {
        if (*it != *sit)
        return false;
        it++;
        sit++;
    }
    if (it != ft.end() || sit != st.end())
        return false;
    return true;
}

template <typename T1, typename T2>
bool ITERATE_VECTOR_REV(T1 &ft, T2 &st) {
    typename T1::reverse_iterator it = ft.rbegin();
    typename T2::reverse_iterator sit = st.rbegin();

    while (it != ft.rend() || sit != st.rend()) {
        if (*it != *sit)
        return false;
        it++;
        sit++;
    }
    if (it != ft.rend() || sit != st.rend())
        return false;
    return true;
}

template <class T1, class T2>
void TEST_VECTOR(T1 &ft, T2 &st, bool rev = false) {
    bool empty = (ft.empty() == st.empty());
    bool size = (ft.size() == st.size());
    bool max_size = (ft.max_size() == st.max_size());
    bool content = false;

    if (rev)
        content = ITERATE_VECTOR_REV(ft, st);
    else
        content = ITERATE_VECTOR(ft, st);

    if (!empty) {
        KO;
    }
    else if (!size) {
        KO;
    }
    else if (!max_size) {
        KO;
    }
    else if (!content) {
        KO;
    }
    else
        OK;
}


void    vec_constructors()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    TEST_VECTOR(fvec, svec);
    
    ft::vector<int> fvec1(2);
    std::vector<int> svec1(2);
    TEST_VECTOR(fvec1, svec1);
    
    ft::vector<int> fvec2(3, 4);
    std::vector<int> svec2(3, 4);
    TEST_VECTOR(fvec2, svec2);

    ft::vector<std::string> fvec3(2, "eins");
    std::vector<std::string> svec3(2, "eins");
    TEST_VECTOR(fvec3, svec3);

    ft::vector<int> vec(20, 1);
    std::vector<int> vecs(20, 1);
    ft::vector<int> fvec4(vec.begin(), vec.end());
    std::vector<int> svec4(vecs.begin(), vecs.end());
    TEST_VECTOR(fvec4, svec4);

    ft::vector<std::string> vec2(20, "eins");
    std::vector<std::string> vecs2(20, "eins");
    ft::vector<std::string> fvec5(vec2.begin(), vec2.end());
    std::vector<std::string> svec5(vecs2.begin(), vecs2.end());
    TEST_VECTOR(fvec4, svec4);

    int arr[] = {1, 2, 3, 4, 5, 6};
    ft::vector<int> fvec6(arr, arr + 2);
    std::vector<int> svec6(arr, arr + 2);
    ft::vector<int> fvec62(arr, arr + 4);
    std::vector<int> svec62(arr, arr + 4);
    TEST_VECTOR(fvec6, svec6);
    TEST_VECTOR(fvec62, svec62);
}

void vec_size()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    TEST(fvec.size(), svec.size());
    
    fvec.push_back(12);
    svec.push_back(12);
    TEST(fvec.size(), svec.size());

    for (int i = 0; i < 10; i++)
    {
        fvec.push_back(i);
        svec.push_back(i);
    }
      TEST(fvec.size(), svec.size());
}

void    vec_max_size()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    TEST(fvec.max_size(), svec.max_size());

    ft::vector<std::string> fvec2;
    std::vector<std::string> svec2;
    TEST(fvec.max_size(), svec.max_size());

    ft::vector<long int> fvec3;
    std::vector<long int> svec3;
    TEST(fvec.max_size(), svec.max_size());
}

void    vec_resize()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    
    fvec.resize(4, 42);
    svec.resize(4, 42);
    TEST_VECTOR(fvec, svec);

    fvec.resize(3, 0);
    svec.resize(3, 0);
    TEST_VECTOR(fvec, svec);

    ft::vector<int> fvec2;
    std::vector<int> svec2;
    for (int i = 0; i < 10; i++)
    {
        fvec2.push_back(i);
        svec2.push_back(i);
    }
    
    fvec2.resize(3);
    fvec2.resize(5, 100);
    fvec2.resize(12);
    svec2.resize(3);
    svec2.resize(5, 100);
    svec2.resize(12);
    TEST_VECTOR(fvec2, svec2);    
}

void vec_empty()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    TEST(fvec.empty(), svec.empty()); 
   
    for (int i = 0; i < 10; i++)
    {
        fvec.push_back(i);
        svec.push_back(i);
    }
    TEST(fvec.empty(), svec.empty()); 

}

void    vec_reserve()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    TEST(fvec.capacity(), svec.capacity());

    fvec.reserve(2);
    svec.reserve(2);
    TEST(fvec.capacity(), svec.capacity());

    fvec.reserve(128);
    svec.reserve(128);
    TEST(fvec.capacity(), svec.capacity());

    fvec.reserve(200);
    svec.reserve(200);
    TEST(fvec.capacity(), svec.capacity());

}

void    vec_capacity()
{
    vec_size();
    vec_max_size();
    vec_resize();
    vec_empty();
    vec_reserve();
}

void vec_access()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    for (int i = 0; i < 100; i++)
    {
        fvec.push_back(i);
        svec.push_back(i);
    }

    TEST(fvec[12], svec[12]);
    TEST(fvec.at(42), svec.at(42));
    TEST(fvec.front(), svec.front());
    TEST(fvec.back(), svec.back());
}

void    vec_modifiers()
{
    ft::vector<int> fvec;
    std::vector<int> svec;

    fvec.push_back(1);
    fvec.push_back(2);
    fvec.push_back(3);
    fvec.push_back(4);
    svec.push_back(1);
    svec.push_back(2);
    svec.push_back(3);
    svec.push_back(4);
    TEST(fvec.back(), svec.back());

    fvec.pop_back();
    svec.pop_back();
    TEST(fvec.back(), svec.back());

    ft::vector<int> fvec2;
    std::vector<int> svec2;
    
    for (int i = 0; i < 10; i++)
    {
        fvec2.push_back(i);
        svec2.push_back(i);
    }
    fvec.assign(fvec2.begin(), --fvec2.end());
    svec.assign(svec2.begin(), --svec2.end());
    TEST_VECTOR(fvec, svec);
    
    fvec.erase(fvec.begin() + 3, fvec.end());
    svec.erase(svec.begin() + 3, svec.end());
    TEST_VECTOR(fvec, svec);
    
    fvec.swap(fvec2);
    svec.swap(svec2);
    TEST_VECTOR(fvec, svec);

    swap(fvec, fvec2);
    swap(svec, svec2);
    TEST_VECTOR(fvec, svec);

    fvec.clear();
    svec.clear();
    TEST(fvec.size(), svec.size());
    TEST_VECTOR(fvec, svec);
}

void vec_operators()
{
    ft::vector<int> fvec;
    std::vector<int> svec;
    ft::vector<int> fvec2;
    std::vector<int> svec2;

    fvec.push_back(10);
    svec.push_back(10);
    fvec2.push_back(10);
    svec2.push_back(10);
    TEST(fvec == fvec2, svec == svec2);

    fvec.push_back(20);
    svec.push_back(20);
    fvec2.push_back(30);
    svec2.push_back(30);
    TEST(fvec == fvec2, svec == svec2);
    TEST(fvec < fvec2, svec < svec2);

    fvec.push_back(50);
    svec.push_back(50);
    fvec2.push_back(40);
    svec2.push_back(40);
    TEST(fvec == fvec2, svec == svec2);
    TEST(fvec <= fvec2, svec <= svec2);
    TEST(fvec >= fvec2, svec >= svec2);
    TEST(fvec != fvec2, svec != svec2);

    fvec = fvec2;
    svec = svec2;
    TEST_VECTOR(fvec, svec);
}

int main() {

    std::cout << MAGENTA << std::setfill('*') << std::setw(90) << "*" << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    std::cout << std::setw(45) << "VECTOR" << std::endl;
    std::cout << std::setfill('*') << std::setw( 90) << "*" << RESET << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    PUT_STR("constructors");
    vec_constructors();

    PUT_STR("capacity");
    vec_capacity();

    PUT_STR("access");
    vec_access();

    PUT_STR("modifiers");
    vec_modifiers();

    PUT_STR("operators");
    vec_operators();

    std::cout << std::endl << std::endl;
    return 0;
}


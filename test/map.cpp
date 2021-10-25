/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:15:17 by emartin-          #+#    #+#             */
/*   Updated: 2021/10/25 11:38:44 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.hpp"

template<typename T1, typename T2>
bool ITERATE_MAP(T1 &ft,T2 &st)
{
    typename T1::iterator fit = ft.begin();
    typename T2::iterator sit = st.begin();

    while (fit != ft.end() || sit != st.end())
    {
        if (fit->second != sit->second)
            return false;
        fit++;
        sit++;
    }
    if (fit != ft.end() || sit != st.end())
        return false;
    return true;
}

template<typename T1, typename T2>
bool REV_ITERATE_MAP(T1 &ft,T2 &st)
{
    typename T1::reverse_iterator fit = ft.rbegin();
    typename T2::reverse_iterator sit = st.rbegin();

    while (fit != ft.rend() || sit != st.rend())
    {
        if (fit->second != sit->second)
            return false;
        fit++;
        sit++;
    }
     if (fit != ft.rend() || sit != st.rend())
        return false;
    return true;
}

template<typename T1, typename T2>
void    TEST_MAP(T1 &ft,T2 &st, bool rev = false)
{
    bool empty = ft.empty() == st.empty();
    bool size =  ft.size() == st.size();
    bool max_size =  ft.max_size() == st.max_size();
    bool content = false;
    if (rev)
        content = REV_ITERATE_MAP(ft, st);
    else
        content = ITERATE_MAP(ft, st);
    if (!empty)
        KO;
    else if (!size)
        KO;
    else if (!max_size)
        KO;
    else if (!content)
        KO;
    else
        OK;

}


void    map_constructors()
{
    ft::map<char, int> fmap;
    std::map<char, int> smap;
    fmap['a'] = 1;
    fmap['b'] = 10;
    fmap['c'] = 2;
    fmap['d'] = 3;
    fmap['e'] = 5;
    
    smap['a'] = 1;
    smap['b'] = 10;
    smap['c'] = 2;
    smap['d'] = 3;
    smap['e'] = 5;
    
    ft::map<char, int> fmap1(fmap);
    std::map<char, int> smap1(smap);

    ft::map<char, int> fmap2(fmap.begin(), fmap.end());
    std::map<char, int> smap2(smap.begin(), smap.end());

    TEST(fmap.size(), smap.size());
    TEST(fmap1.size(), smap1.size());
    TEST(fmap2.size(), smap2.size());

    // ft::map<char, int>::iterator it = fmap1.begin();
    // while (it != fmap1.end())
    // {
    //     std::cout << it->first << " | " << it->second << std::endl;
    //     it++;
    // }

    // std::map<char, int>::iterator sit = smap1.begin();
    // while (sit != smap1.end())
    // {
    //     std::cout << sit->first << " | " << sit->second << std::endl;
    //     sit++;
    // }


}

void    map_iterators()
{
    ft::map<int, int> fmap;
    std::map<int, int> smap;

    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;

    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;
    
    ft::map<int, int>::iterator it = fmap.begin();
    std::map<int, int>::iterator sit = smap.begin();
    TEST(it->first, sit->first);
    
    fmap['e'] = 5;
    smap['e'] = 5;
    
    TEST((++it)->first, (++sit)->first);
    TEST((++(++it))->first, (++(++sit))->first);

    ft::map<int, int>::iterator ite = fmap.end();
    std::map<int, int>::iterator site = smap.end();
    TEST((--ite)->first, (--site)->first);

    ft::map<int, int>::reverse_iterator rit = fmap.rbegin();
    std::map<int, int>::reverse_iterator srit = smap.rbegin();
    TEST((++rit)->first, (++srit)->first);
    
    ft::map<int, int>::const_iterator cit = fmap.begin();
    std::map<int, int>::const_iterator scit = smap.begin();
    TEST(cit == fmap.begin(), scit == smap.begin());
    TEST(cit != fmap.begin(), scit != smap.begin());
}

void    map_capacity()
{
    ft::map<char, int> fmap;
    std::map<char, int> smap;
    TEST(fmap.empty(), smap.empty());
    
    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;

    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;
    TEST(fmap.empty(), smap.empty());
    TEST(fmap.size(), smap.size());
    TEST(fmap.max_size(), smap.max_size());
}

void map_access()
{
    ft::map<char, int> fmap;
    std::map<char, int> smap;
    
    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;
    fmap['e'] = fmap['d'];

    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;
    smap['e'] = smap['d'];

    TEST(fmap['a'], smap['a']);
    TEST(fmap['b'], smap['b']);
    TEST(fmap['e'], smap['e']);
    TEST(fmap['g'], smap['g']);
    TEST(fmap.size(), smap.size());
}

void    map_modifiers()
{
    ft::map<char, int> fmap;
    std::map<char, int> smap;
    ft::map<char, int> fmap2;
    std::map<char, int> smap2;

    fmap.insert(ft::pair<const char, int>('a', 100));
    fmap.insert(ft::pair<const char, int>('z', 200));
    smap.insert(std::pair<const char, int>('a', 100));
    smap.insert(std::pair<const char, int>('z', 200));

    fmap.insert(ft::pair<const char, int>('z', 400));
    smap.insert(std::pair<const char, int>('z', 400));

    ft::map<char, int>::iterator it = fmap.begin();
    fmap.insert(it, ft::pair<const char, int>('b', 500));
    fmap.insert(it, ft::pair<const char, int>('c', 600));
    std::map<char, int>::iterator sit = smap.begin();
    smap.insert(sit, std::pair<const char, int>('b', 500));
    smap.insert(sit, std::pair<const char, int>('c', 600));

    fmap2.insert(fmap.begin(), fmap.find('c'));
    smap2.insert(smap.begin(), smap.find('c'));
    TEST_MAP(fmap, smap);
    TEST_MAP(fmap2, smap2);

    it = fmap.find('b');
    sit = smap.find('b');
    fmap.erase(it);
    smap.erase(sit);
    fmap.erase('c');
    smap.erase('c');
    TEST_MAP(fmap, smap);

    it = fmap.find('e');
    sit = smap.find('e');
    fmap.erase(it, fmap.end());
    smap.erase(sit, smap.end());
    TEST_MAP(fmap, smap);

    fmap.swap(fmap2);
    smap.swap(smap2);
    TEST_MAP(fmap, smap);

    fmap.clear();
    smap.clear();
    TEST(fmap.size(), smap.size());
}

void    map_observers()
{
    ft::map<char, int> fmap;
    ft::map<char, int>::key_compare fk_comp = fmap.key_comp();
    std::map<char, int> smap;
    std::map<char, int>::key_compare sk_comp = smap.key_comp();

    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;

    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;

    TEST(fk_comp(1, 10), sk_comp(1, 10));
    TEST(fk_comp(15, 10), sk_comp(15, 10));
    TEST(fk_comp(10, 10), sk_comp(10, 10));

    ft::pair<char,int> fh = *fmap.rbegin();
    ft::map<char,int>::iterator it = fmap.begin();
    std::pair<char,int> sh = *smap.rbegin();
    std::map<char,int>::iterator sit = smap.begin();
    TEST(fmap.value_comp()(*it++, fh), smap.value_comp()(*sit++, sh));
}

void  map_operations()
{
    ft::map<int, int> fmap2;
    std::map<int, int> smap2;
    
    fmap2[1] = 10;
    fmap2[2] = 20;
    fmap2[3] = 30;

    smap2[1] = 10;
    smap2[2] = 20;
    smap2[3] = 30;

    TEST(fmap2.count(1), smap2.count(1));
    TEST(fmap2.count(2), smap2.count(2));
    TEST(fmap2.count(3), smap2.count(3));
    TEST(fmap2.count(4), smap2.count(4));
    
    ft::map<char, int> fmap3;
    ft::map<char, int>::iterator it_low, it_up;
    std::map<char, int> smap3;
    std::map<char, int>::iterator sit_low, sit_up;

    fmap3['a'] = 20;
    fmap3['b'] = 40;
    fmap3['c'] = 60;
    fmap3['d'] = 80;
    fmap3['e'] = 100;

    smap3['a'] = 20;
    smap3['b'] = 40;
    smap3['c'] = 60;
    smap3['d'] = 80;
    smap3['e'] = 100;

    it_low = fmap3.lower_bound('b');
    it_up = fmap3.upper_bound('d');
    fmap3.erase(it_low, it_up);

    sit_low = smap3.lower_bound('b');
    sit_up = smap3.upper_bound('d');
    smap3.erase(sit_low, sit_up);
    
    ft::map<char, int> fmap4;
    std::map<char, int> smap4;
    
    fmap4['a'] = 10;
    fmap4['b'] = 20;
    fmap4['c'] = 30;

    smap4['a'] = 10;
    smap4['b'] = 20;
    smap4['c'] = 30;

    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
    ret = fmap4.equal_range('b');
    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> sret;
    sret = smap4.equal_range('b'); 
    TEST(ret.first->first, sret.first->first);
    TEST(ret.first->second, sret.first->second);
    TEST(ret.second->first, sret.second->first);
    TEST(ret.second->second, sret.second->second);
}


int main() {
    std::cout << MAGENTA << std::setfill('*') << std::setw(90) << "*" << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    std::cout << std::setw(45) << "MAP" << std::endl;
    std::cout << std::setfill('*') << std::setw( 90) << "*" << RESET << std::endl;
    std::cout << std::setfill(' ') << std::fixed;

    PUT_STR("constructors");
    map_constructors();

    PUT_STR("iterators");
    map_iterators();

    PUT_STR("capacity");
    map_capacity();

    PUT_STR("access");
    map_access();

    PUT_STR("modifiers");
    map_modifiers();

    PUT_STR("observers");
    map_observers();

    PUT_STR("operations");
    map_operations();


  std::cout << std::endl << std::endl;
  return 0;
}

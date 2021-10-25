#include "test.hpp"
#include "time.h"

void    ft_vec_constructors()
{
    ft::vector<int> fvec;
    ft::vector<int> fvec1(2);
    ft::vector<int> fvec2(3, 4);
    ft::vector<std::string> fvec3(2, "eins");
    ft::vector<int> vec(20, 1);
    ft::vector<int> fvec4(vec.begin(), vec.end());
    ft::vector<std::string> vec2(20, "eins");
    ft::vector<std::string> fvec5(vec2.begin(), vec2.end());
    int arr[] = {1, 2, 3, 4, 5, 6};
    ft::vector<int> fvec6(arr, arr + 2);
    ft::vector<int> fvec62(arr, arr + 4);
}

void ft_vec_size()
{
    ft::vector<int> fvec;
    fvec.size();
    fvec.push_back(12);
    fvec.size();
    for (int i = 0; i < 10; i++)
        fvec.push_back(i);
    fvec.size();
}

void    ft_vec_max_size()
{
    ft::vector<int> fvec;
    fvec.max_size();
    ft::vector<std::string> fvec2;
    fvec.max_size();
    ft::vector<long int> fvec3;
    fvec.max_size();
}

void    ft_vec_resize()
{
    ft::vector<int> fvec;
    fvec.resize(4, 42);
    fvec.resize(3, 0);
    ft::vector<int> fvec2;
    for (int i = 0; i < 10; i++)
        fvec2.push_back(i);
    fvec2.resize(3);
    fvec2.resize(5, 100);
    fvec2.resize(12);
}

void ft_vec_empty()
{
    ft::vector<int> fvec;
    fvec.empty();
    for (int i = 0; i < 10; i++)
        fvec.push_back(i);
    fvec.empty();
}

void    ft_vec_reserve()
{
    ft::vector<int> fvec;
    fvec.capacity();

    fvec.reserve(2);
    fvec.capacity();

    fvec.reserve(128);
    fvec.capacity();

    fvec.reserve(200);
    fvec.capacity();

}

void    ft_vec_capacity()
{
    ft_vec_size();
    ft_vec_max_size();
    ft_vec_resize();
    ft_vec_empty();
    ft_vec_reserve();
}

void ft_vec_access()
{
    ft::vector<int> fvec;

    for (int i = 0; i < 100; i++)
        fvec.push_back(i);

    fvec[12];
    fvec.at(42);
    fvec.front();
    fvec.back();
}

void    ft_vec_modifiers()
{
    ft::vector<int> fvec;
    fvec.push_back(1);
    fvec.push_back(2);
    fvec.push_back(3);
    fvec.push_back(4);
    fvec.back();
    fvec.pop_back();
    fvec.back();

    ft::vector<int> fvec2;
    for (int i = 0; i < 100; i++)
        fvec2.push_back(i);
    fvec.assign(fvec2.begin(), --fvec2.end());
    fvec.erase(fvec.begin() + 3, fvec.end());
    fvec.swap(fvec2);
    swap(fvec, fvec2);
    fvec.clear();
    fvec.size();
}

void ft_vec_operators()
{
    ft::vector<int> fvec;
    ft::vector<int> fvec2;
    int i  = 0;
    fvec.push_back(10);
    fvec2.push_back(10);
    if (fvec == fvec2)
        i++;
    fvec.push_back(20);
    fvec2.push_back(30);
    if (fvec == fvec2)
        i++;
    if (fvec < fvec2)
        i++;
    fvec.push_back(50);
    fvec2.push_back(40);
    if (fvec == fvec2)
        i++;
    if (fvec <= fvec2)
        i++;
    if (fvec >= fvec2)
        i++;
    if (fvec != fvec2)
        i++;
    fvec = fvec2;
}

// STACK

void ft_stack_constructors()
{
    ft::stack<int> fst;
    ft::stack<int> fst2(fst);
}

void ft_stack_empty()
{
    ft::stack<int> fst;
    fst.empty();
    fst.push(42);
    fst.push(42);
    fst.push(42);
    fst.empty();
}

void ft_stack_size()
{
    ft::stack<int> fst;
    fst.size();
    fst.push(42);
    fst.push(42);
    fst.push(42);
    fst.size(); 
    fst.push(42);
    fst.push(42);
    fst.push(42);
    fst.size(); 
}

void ft_stack_top()
{
    ft::stack<int> fst;
    
    fst.push(42);
    fst.top();
    fst.push(2);
    fst.top();
    fst.push(22);
    fst.top();
}

void ft_stack_pop()
{
    ft::stack<int> fst;
    for (int i = 0; i < 4; i++)
        fst.push(i);
    fst.pop();

    for (int i = 4; i < 8; i++)

        fst.push(i);
}

void ft_stack_operators()
{
    ft::stack<int> fst;
    ft::stack<int> fst2;
    for (int i = 0; i < 4; i++)
    {
        fst.push(i);
        fst2.push(i);
    }
    int i = 0;
    if(fst == fst2)
        i++;
    if(fst < fst2)
        i++;
    if(fst <= fst2)
        i++;
    if(fst > fst2)
        i++;
    if(fst >= fst2)
        i++;
    if(fst != fst2)
        i++;
}  

// MAP

void    ft_map_constructors()
{
    ft::map<char, int> fmap;
    fmap['a'] = 1;
    fmap['b'] = 10;
    fmap['c'] = 2;
    fmap['d'] = 3;
    fmap['e'] = 5;
    ft::map<char, int> fmap1(fmap);
    ft::map<char, int> fmap2(fmap.begin(), fmap.end());
    fmap.size();
    fmap1.size();
    fmap2.size();
}

void    ft_map_iterators()
{
    ft::map<int, int> fmap;
    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;
    ft::map<int, int>::iterator it = fmap.begin();
    ft::map<int, int>::iterator ite = fmap.end(); 
    ft::map<int, int>::reverse_iterator rit = fmap.rbegin();
    fmap.erase(it);
    fmap.erase(--ite);
    fmap.insert(rit, --fmap.rend());
}

void    ft_map_capacity()
{
    ft::map<char, int> fmap;
    fmap.empty();
    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;
    fmap.empty();
    fmap.size();
    fmap.max_size();
}

void ft_map_access()
{
    ft::map<char, int> fmap;
    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;
    fmap['e'] = fmap['d'];
    fmap['f'] = fmap['c'];
    fmap['g'] = fmap['b'];
    fmap.size();
}

void    ft_map_modifiers()
{
    ft::map<char, int> fmap;
    ft::map<char, int> fmap2;
    fmap.insert(ft::pair<const char, int>('a', 100));
    fmap.insert(ft::pair<const char, int>('z', 200));
    fmap.insert(ft::pair<const char, int>('z', 400));
    ft::map<char, int>::iterator it = fmap.begin();
    fmap.insert(it, ft::pair<const char, int>('b', 500));
    fmap.insert(it, ft::pair<const char, int>('c', 600));
    fmap2.insert(fmap.begin(), fmap.find('c'));
    it = fmap.find('b');
    fmap.erase(it);
    fmap.erase('c');
    it = fmap.find('e');
    fmap.erase(it, fmap.end());
    fmap.swap(fmap2);
    fmap.clear();
}

void    ft_map_observers()
{
    ft::map<char, int> fmap;
    ft::map<char, int>::key_compare fk_comp = fmap.key_comp();
    fmap['a'] = 1;
    fmap['b'] = 2;
    fmap['c'] = 3;
    fmap['d'] = 4;
    fk_comp(1, 10);
    fk_comp(15, 10);
    fk_comp(10, 10);
    ft::pair<char,int> fh = *fmap.rbegin();
    ft::map<char,int>::iterator it = fmap.begin();
    fmap.value_comp()(*it++, fh);
}

void  ft_map_operations()
{
    ft::map<int, int> fmap2;
    fmap2[1] = 10;
    fmap2[2] = 20;
    fmap2[3] = 30;
    fmap2.count(1);
    fmap2.count(2);
    fmap2.count(3);
    fmap2.count(4);
    ft::map<char, int> fmap3;
    ft::map<char, int>::iterator it_low, it_up;
    fmap3['a'] = 20;
    fmap3['b'] = 40;
    fmap3['c'] = 60;
    fmap3['d'] = 80;
    fmap3['e'] = 100;

    it_low = fmap3.lower_bound('b');
    it_up = fmap3.upper_bound('d');
    fmap3.erase(it_low, it_up);
    ft::map<char, int> fmap4;
    fmap4['a'] = 10;
    fmap4['b'] = 20;
    fmap4['c'] = 30;
    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
    ret = fmap4.equal_range('b');
}

  ///////////////////////
 //       STD         //
///////////////////////

void    std_vec_constructors()
{
    std::vector<int> svec;
    std::vector<int> svec1(2);
    std::vector<int> svec2(3, 4);
    std::vector<std::string> svec3(2, "eins");
    std::vector<int> vecs(20, 1);
    std::vector<int> svec4(vecs.begin(), vecs.end());
    std::vector<std::string> vecs2(20, "eins");
    std::vector<std::string> svec5(vecs2.begin(), vecs2.end());
    int arr[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> svec6(arr, arr + 2);
    std::vector<int> svec62(arr, arr + 4);

}

void std_vec_size()
{
        std::vector<int> svec;
    svec.size();
    svec.push_back(12);
    svec.size();
    for (int i = 0; i < 10; i++)
        svec.push_back(i);
    svec.size();
}

void std_vec_max_size()
{
    std::vector<int> svec;
    svec.max_size();
    std::vector<std::string> svec2;
    svec.max_size();
    std::vector<long int> svec3;
    svec.max_size();
}

void std_vec_resize()
{
    std::vector<int> svec;
    svec.resize(4, 42);
    svec.resize(3, 0);
    std::vector<int> svec2;
    for (int i = 0; i < 10; i++)
        svec2.push_back(i);
    svec2.resize(3);
    svec2.resize(5, 100);
    svec2.resize(12);    
}

void std_vec_empty()
{
    std::vector<int> svec;
    svec.empty(); 
    for (int i = 0; i < 10; i++)
        svec.push_back(i);
    svec.empty(); 
}

void std_vec_reserve()
{
    std::vector<int> svec;
    svec.capacity();
    svec.reserve(2);
    svec.capacity();
    svec.reserve(128);
    svec.capacity();
    svec.reserve(200);
    svec.capacity();
}

void    std_vec_capacity()
{
    std_vec_size();
    std_vec_max_size();
    std_vec_resize();
    std_vec_empty();
    std_vec_reserve();
}

void std_vec_access()
{
    std::vector<int> svec;
    for (int i = 0; i < 100; i++)
        svec.push_back(i);
    svec[12];
    svec.at(42);
    svec.front();
    svec.back();
}

void    std_vec_modifiers()
{
    std::vector<int> svec;
    svec.push_back(1);
    svec.push_back(2);
    svec.push_back(3);
    svec.push_back(4);
    svec.back();
    svec.pop_back();
    svec.back();

    std::vector<int> svec2;
    for (int i = 0; i < 100; i++)
        svec2.push_back(i);
    svec.assign(svec2.begin(), --svec2.end());
    svec.erase(svec.begin() + 3, svec.end());
    svec.swap(svec2);
    swap(svec, svec2);
    svec.clear();
    svec.size();
}

void std_vec_operators()
{
    std::vector<int> svec;
    std::vector<int> svec2;
    int i = 0;
    svec.push_back(10);
    svec2.push_back(10);
    if (svec == svec2)
        i++;
    svec.push_back(20);
    svec2.push_back(30);
    if (svec == svec2)
        i++;
    if (svec < svec2)
        i++;
    svec.push_back(50);
    svec2.push_back(40);
    if (svec == svec2)
        i++;
    if (svec <= svec2)
        i++;
    if (svec >= svec2)
        i++;
    if (svec != svec2)
        i++;
    svec = svec2;
}

// STACK 

void std_stack_constructors()
{
    ft::stack<int> fst;
    ft::stack<int> fst2(fst);
}

void std_stack_empty()
{
    std::stack<int> sst;
    sst.empty();
    sst.push(42);
    sst.push(42);
    sst.push(42);
    sst.empty();
}

void std_stack_size()
{
    std::stack<int> sst;
    sst.size();
    sst.push(42);
    sst.push(42);
    sst.push(42);
    sst.size();
    sst.push(42);
    sst.push(42);
    sst.push(42);
    sst.size();
}

void std_stack_top()
{
    std::stack<int> sst; 
    sst.push(42);
    sst.top();
    
    sst.push(2);
    sst.top();

    sst.push(22);
    sst.top();
}

void std_stack_pop()
{
    std::stack<int> sst;
    for (int i = 0; i < 4; i++)
        sst.push(i);

    sst.pop();

    for (int i = 4; i < 8; i++)
        sst.push(i);
}

void std_stack_operators()
{
    std::stack<int> sst;
    std::stack<int> sst2;

    for (int i = 0; i < 4; i++)
    {
        sst.push(i);
        sst2.push(i);
    }
    
    int i = 0;
    if(sst == sst2)
        i++;
    if(sst < sst2)
        i++;
    if(sst <= sst2)
        i++;
    if(sst > sst2)
        i++;
    if(sst >= sst2)
        i++;
    if(sst != sst2)
        i++;
}  

void    std_map_constructors()
{
    std::map<char, int> smap;
    smap['a'] = 1;
    smap['b'] = 10;
    smap['c'] = 2;
    smap['d'] = 3;
    smap['e'] = 5;
    std::map<char, int> smap1(smap);
    std::map<char, int> smap2(smap.begin(), smap.end());
    smap.size();
    smap1.size();
    smap2.size();
}

void    std_map_iterators()
{
    std::map<int, int> smap;
    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;
    std::map<int, int>::iterator sit = smap.begin();
    std::map<int, int>::iterator site = smap.end();
    std::map<int, int>::reverse_iterator srit = smap.rbegin();
    smap.erase(sit);
    smap.erase(--site);
    smap.insert(srit, --smap.rend());
}

void    std_map_capacity()
{
    std::map<char, int> smap;
    smap.empty();
    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;
    smap.empty();
    smap.size();
    smap.max_size();
}

void std_map_access()
{
    std::map<char, int> smap;
    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;
    smap['e'] = smap['d'];
    smap['f'] = smap['c'];
    smap['g'] = smap['b'];
    smap.size();
}

void    std_map_modifiers()
{
    std::map<char, int> smap;
    std::map<char, int> smap2;
    smap.insert(std::pair<const char, int>('a', 100));
    smap.insert(std::pair<const char, int>('z', 200));
    smap.insert(std::pair<const char, int>('z', 400));
    std::map<char, int>::iterator sit = smap.begin();
    smap.insert(sit, std::pair<const char, int>('b', 500));
    smap.insert(sit, std::pair<const char, int>('c', 600));
    smap2.insert(smap.begin(), smap.find('c'));
    sit = smap.find('b');
    smap.erase(sit);
    smap.erase('c');
    sit = smap.find('e');
    smap.erase(sit, smap.end());
    smap.swap(smap2);
    smap.clear();
}

void    std_map_observers()
{
    std::map<char, int> smap;
    std::map<char, int>::key_compare sk_comp = smap.key_comp();
    smap['a'] = 1;
    smap['b'] = 2;
    smap['c'] = 3;
    smap['d'] = 4;
    sk_comp(1, 10);
    sk_comp(15, 10);
    sk_comp(10, 10);
    std::pair<char,int> sh = *smap.rbegin();
    std::map<char,int>::iterator sit = smap.begin();
    smap.value_comp()(*sit++, sh);
}

void  std_map_operations()
{
    std::map<int, int> smap2;
    smap2[1] = 10;
    smap2[2] = 20;
    smap2[3] = 30;
    smap2.count(1);
    smap2.count(2);
    smap2.count(3);
    smap2.count(4);
    std::map<char, int> smap3;
    std::map<char, int>::iterator sit_low, sit_up;
    smap3['a'] = 20;
    smap3['b'] = 40;
    smap3['c'] = 60;
    smap3['d'] = 80;
    smap3['e'] = 100;
    sit_low = smap3.lower_bound('b');
    sit_up = smap3.upper_bound('d');
    smap3.erase(sit_low, sit_up);
    std::map<char, int> smap4;
    smap4['a'] = 10;
    smap4['b'] = 20;
    smap4['c'] = 30;
    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> sret;
    sret = smap4.equal_range('b'); 
}



int main() {

    std::cout << MAGENTA << std::setfill('*') << std::setw(90) << "*" << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    std::cout << std::setw(45) << "TIMER" << std::endl;
    std::cout << std::setfill('*') << std::setw( 90) << "*" << RESET << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    
    time_t ft_start;
    time_t ft_end;
    double ft_t;
    time_t std_start;
    time_t std_end;
    double st_t;

    PUT_STR("Vector");
    ft_start = clock();
    ft_vec_constructors();
    ft_vec_capacity();
    ft_vec_access();
    ft_vec_modifiers();
    ft_vec_operators();
    ft_end = clock();
    ft_t = difftime(ft_end, ft_start);

    std_start = clock();
    std_vec_constructors();
    std_vec_capacity();
    std_vec_access();
    std_vec_modifiers();
    std_vec_operators();
    std_end = clock();
    st_t = difftime(std_end, std_start);
    if (ft_t > (st_t * 20))
        std::cout << RED <<  "Error: time exceed " << RESET << std::endl;
    else
        std::cout << GREEN << "ft->" << ft_t << "  " << "std->" << st_t << RESET <<std::endl;

    PUT_STR("Stack");
    ft_start = clock();
    ft_stack_constructors();
    ft_stack_empty();
    ft_stack_size();
    ft_stack_top();
    ft_stack_pop();
    ft_stack_operators();
    ft_end = clock();
    ft_t = difftime(ft_end, ft_start);
    
    std_start = clock();
    std_stack_constructors();
    std_stack_empty();
    std_stack_size();
    std_stack_top();
    std_stack_pop();
    std_stack_operators();
    std_end = clock();
    st_t = difftime(std_end, std_start);
    if (ft_t > (st_t * 20))
        std::cout << RED <<  "Error: time exceed "  << RESET << std::endl;
    else
        std::cout << GREEN << "ft->" << ft_t << "  " << "std->" << st_t  << RESET <<std::endl;

    PUT_STR("Map");
    ft_start = clock();
    ft_map_constructors();    
    ft_map_iterators();
    ft_map_capacity();
    ft_map_access();
    ft_map_modifiers();
    ft_map_observers();
    ft_map_operations();
    ft_end = clock();
    ft_t = difftime(ft_end, ft_start);

    std_start = clock();
    std_map_constructors();    
    std_map_iterators();
    std_map_capacity();
    std_map_access();
    std_map_modifiers();
    std_map_observers();
    std_map_operations();
    std_end = clock();
    st_t = difftime(std_end, std_start);
    if (ft_t > (st_t * 20))
        std::cout << RED <<  "Error: time exceed "  << RESET << std::endl;
    else
        std::cout << GREEN << "ft->" << ft_t << "  " << "std->" << st_t  << RESET <<std::endl;
    std::cout << std::endl << std::endl;
    return 0;
}

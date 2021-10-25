/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:50:11 by emartin-          #+#    #+#             */
/*   Updated: 2021/10/25 11:57:43 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template<typename T1, typename T2>
void    TEST_STACK(T1 &ft,T2 &st)
{
    bool empty = ft.empty() == st.empty();
    bool size =  ft.size() == st.size();
    if (!empty)
        KO;
    else if (!size)
        KO;
    else
        OK;

}

void stack_constructors()
{
    
    ft::stack<int> fst;
    std::stack<int> sst;
    TEST_STACK(fst, sst);

    ft::stack<int> fst2(fst);
    std::stack<int> sst2(sst);
    TEST_STACK(fst, sst);

    std::list<int> list(4, 100);
    ft::stack<int, std::list<int> > fst3(list);
    std::stack<int, std::list<int> > sst3(list);
    TEST_STACK(fst3, sst3);

    std::deque<int> dq(5, 20);
    ft::stack<int, std::deque<int> > fst4(dq);
    std::stack<int, std::deque<int> > sst4(dq);
    TEST_STACK(fst4, sst4);

    
}

void stack_empty()
{
    ft::stack<int> fst;
    std::stack<int> sst;
    TEST(fst.empty(), sst.empty());

    fst.push(42);
    fst.push(42);
    fst.push(42);
    sst.push(42);
    sst.push(42);
    sst.push(42);
    TEST(fst.empty(), sst.empty());

    std::list<int> list(4, 100);
    ft::stack<int, std::list<int> > fst3(list);
    std::stack<int, std::list<int> > sst3(list);
    fst3.push(42);
    fst3.push(42);
    fst3.push(42);
    sst3.push(42);
    sst3.push(42);
    sst3.push(42);
    TEST(fst3.empty(), sst3.empty());
    
    std::deque<int> dq(5, 20);
    ft::stack<int, std::deque<int> > fst4(dq);
    std::stack<int, std::deque<int> > sst4(dq);
    fst4.push(42);
    fst4.push(42);
    fst4.push(42);
    sst4.push(42);
    sst4.push(42);
    sst4.push(42);
    TEST(fst4.empty(), sst4.empty());
}

void stack_size()
{
    ft::stack<int> fst;
    std::stack<int> sst;
    TEST(fst.size(), sst.size());

    fst.push(42);
    fst.push(42);
    fst.push(42);
    sst.push(42);
    sst.push(42);
    sst.push(42);
    TEST(fst.size(), sst.size());

    fst.push(42);
    fst.push(42);
    fst.push(42);
    sst.push(42);
    sst.push(42);
    sst.push(42);
    TEST(fst.size(), sst.size());
}

void stack_top()
{
    ft::stack<int> fst;
    std::stack<int> sst;
    
    fst.push(42);
    sst.push(42);
    TEST(fst.top(), sst.top());
    
    fst.push(2);
    sst.push(2);
    TEST(fst.top(), sst.top());

    fst.push(22);
    sst.push(22);
    TEST(fst.top(), sst.top());

}

void stack_pop()
{
    ft::stack<int> fst;
    std::stack<int> sst;

    for (int i = 0; i < 4; i++)
    {
        fst.push(i);
        sst.push(i);
    }
    fst.pop();
    sst.pop();
    TEST_STACK(fst, sst);

    for (int i = 4; i < 8; i++)
    {
        fst.push(i);
        sst.push(i);
    }
    TEST_STACK(fst, sst);

}

void stack_operators()
{
    ft::stack<int> fst;
    std::stack<int> sst;
    ft::stack<int> fst2;
    std::stack<int> sst2;

    for (int i = 0; i < 4; i++)
    {
        fst.push(i);
        sst.push(i);
        fst2.push(i);
        sst2.push(i);
    }
    
    TEST(fst == fst2, sst == sst2);
    TEST(fst < fst2, sst < sst2);
    TEST(fst <= fst2, sst <= sst2);
    TEST(fst > fst2, sst > sst2);
    TEST(fst >= fst2, sst >= sst2);
    TEST(fst != fst2, sst != sst2);

    

}

int main()
{
    std::cout << MAGENTA << std::setfill('*') << std::setw(90) << "*" << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    std::cout << std::setw(45) << "STACK" << std::endl;
    std::cout << std::setfill('*') << std::setw( 90) << "*" << RESET << std::endl;
    std::cout << std::setfill(' ') << std::fixed;
    
    PUT_STR("constructors");
    stack_constructors();

    PUT_STR("empty");
    stack_empty();

    PUT_STR("size");
    stack_size();

    PUT_STR("top");
    stack_top();

    PUT_STR("pop");
    stack_pop();

    PUT_STR("operators");
    stack_operators();

    std::cout << std::endl << std::endl;
    return 0;
}
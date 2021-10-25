/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:54:33 by emartin-          #+#    #+#             */
/*   Updated: 2021/10/25 11:47:27 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft 
{
    template <class T, class Container = std::vector<T> >
    class stack
    {
    public:
        typedef T               value_type;
        typedef Container       container_type;
        typedef size_t          size_type;
        
    
    public:
        explicit stack(const container_type& cont = container_type()) { _cont = cont; };
        explicit stack(const stack &st)  { _cont = st._cont; };
        
        virtual ~stack() {};

        stack &operator=(const stack &st) {_cont = st._cont; return *this; }

        bool empty() const { return _cont.empty(); }
        size_type size() const { return _cont.size(); }
        value_type& top() { return _cont.back(); }
        const value_type& top() const { return _cont.back(); }
        void push(const value_type& val) { _cont.push_back(val); }
        void pop() { _cont.pop_back(); }
        
        template <typename value_type, typename  container_type>
            friend bool operator==(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs);
        template <typename value_type, typename  container_type>
            friend bool operator!=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs);
        template <typename value_type, typename  container_type>
            friend bool operator<(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs);
        template <typename value_type, typename  container_type>
            friend bool operator<=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs);
        template <typename value_type, typename  container_type>
            friend bool operator>(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs);
        template <typename value_type, typename  container_type>
            friend bool operator>=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs);
        
    protected:
        container_type  _cont;

    }; 
        template <typename value_type, typename  container_type>
        bool operator==(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs){
            return lhs._cont == rhs._cont;
        }

        template <typename value_type, typename  container_type>
        bool operator!=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs){
            return lhs._cont != rhs._cont;
        }

        template <typename value_type, typename  container_type>
        bool operator<(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs){
            return lhs._cont < rhs._cont;
        }

        template <typename value_type, typename  container_type>
        bool operator<=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs){
            return lhs._cont <= rhs._cont;
  
        }

        template <typename value_type, typename  container_type>
        bool operator>(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs){
            return lhs._cont > rhs._cont;
            
        }

        template <typename value_type, typename  container_type>
        bool operator>=(const stack<value_type, container_type>& lhs, const stack<value_type, container_type>& rhs){
            return lhs._cont >= rhs._cont; 
        }
}
#endif
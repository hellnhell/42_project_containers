/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:04:30 by emartin-          #+#    #+#             */
/*   Updated: 2021/10/13 13:48:14 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <cmath>
# include <string>
# include <iostream>
# include <iomanip>
# include <ctype.h>
# include <stdlib.h>
# include <memory>
# include <stdexcept>

template <typename T>
class Node;

template <typename T>
    class Node
    {
   
        public:
            T           _data;
            Node<T>     *left;
            Node<T>     *right;
            Node<T>     *parent;
                 
            Node() : left(NULL), right(NULL), parent(NULL)  {};
            Node(T data) : _data(data), left(NULL), right(NULL), parent(NULL) {};
            virtual ~Node() {};

            int height(Node<T> *node)
            {
                if (node == NULL)
                    return 0;
                int r = height(node->right);
                int l = height(node->left);
                if (left > right)
                    return l + 1;
                return r + 1;

            }

            void check_balance(Node<T> *node, Node <T> **root)
            {
                int b_factor = height(node->left) - height(node->right) ; 
                if (b_factor > 1 ||  b_factor < -1)
                    balance(node, root);
                if (node->parent == NULL)
                    return ;
                check_balance(node->parent, root);
            }

            void balance(Node<T> *node, Node<T> **root)
            {
                bool is_right;
                Node<T> *tmp = node->parent;
                if (node->parent != NULL)
                    is_right = node->parent->right == node;
                if (height(node->right) - height(node->left) > 1)
                {
                    if(height(node->right->left) < height(node->right->right))
                        node = left_r(node);
                    else
                        node = right_left_r(node);
                }
                else
                {
                    if (height(node->left->left) > height(node->left->right))
                        node = right_r(node);
                    else
                        node = left_right_r(node);
                }
                if (tmp == NULL)
                    *root = node;
                else
                {
                    if(is_right == true)
                        tmp->right = node;
                    else
                        tmp->left = node;
                }
                node->parent = tmp;
            }

            Node<T> *left_r(Node<T> *node)
            {                
                Node<T> * tmp = node->right;
                node->right = tmp->left;
                tmp->left = node;
                node->parent = tmp;
                if (node->right)
                    node->right->parent = node;
                return tmp; 
            }

            Node<T> *right_r(Node<T> *node)
            {
                Node<T> *tmp = node->left;
                node->left = tmp->right;
                tmp->right = node;
                node->parent = tmp;
                if (node->left)
                    node->left->parent = node;
                return tmp;
            }

            Node<T> *left_right_r(Node<T> *node)
            {
                node->left = left_r(node->left);
                return right_r(node);  
            }

            Node<T> *right_left_r(Node<T> *node)
            {
                node->right = right_r(node->right);
                return left_r(node);  
            }
            
    };

#endif
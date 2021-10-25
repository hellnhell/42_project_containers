#ifndef TREE_HPP
# define TREE_HPP

# include "Node.hpp"
# include "../utils.hpp"

template<class Key, class Value, class Compare, class Alloc>
class Tree
{
    public:
        typedef typename Alloc::template rebind<Node<ft::pair<Key, Value> > >::other Node_allocator_type;

        Node_allocator_type          _alloc;
        Node<ft::pair<Key, Value> > *root;
        Node<ft::pair<Key, Value> > *end;
        Node<ft::pair<Key, Value> > *rend;
        int size;

        Tree()
        {
            _alloc = Node_allocator_type();
            root = NULL;
            size = 0;
            rend = _alloc.allocate(1);
            _alloc.construct(rend);
            root = rend;
            end = _alloc.allocate(1);
            _alloc.construct(end);
            rend->right = end;
            end->parent = rend;
        }

        ~Tree() { if (root) { destroy(root); };};

        void    destroy(Node<ft::pair<Key, Value> > *node)
        {
            if (node->right)
                destroy(node->right);
            if (node->left)
                destroy(node->left);
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }

        Node<ft::pair<Key, Value> > *add(Key k, Value val)
        {

            ft::pair<Key, Value> _pair = ft::make_pair(k, val);
            Node<ft::pair<Key, Value> > *node = _alloc.allocate(1);

            _alloc.construct(node, _pair);
            add(root, node);
            return node;
        }


        Node<ft::pair<Key, Value> > *add(Key k, Value val, Node<ft::pair<Key, Value> > *node)
        {
            ft::pair<Key, Value> _pair = ft::make_pair(k, val);
            Node<ft::pair<Key, Value> > *_node = _alloc.allocate(1);
            
            _alloc.construct(_node, _pair);
            add(node, _node);
            return _node;
        }


        void    add(Node<ft::pair<Key, Value> > *parent, Node<ft::pair<Key, Value> > *newNode)
        {
            if (parent == rend || (parent != end && Compare()(parent->_data.first, newNode->_data.first)))
            {
                if (parent->right == NULL)
                {
                    parent->right = newNode;
                    newNode->parent = parent;
                    size++;
                }
                else{
                    add(parent->right, newNode);
                }
            }
            else
            {
                if (parent->left == NULL)
                {
                    parent->left = newNode;
                    newNode->parent = parent;
                    size++;
                }
                else
                    add(parent->left, newNode);
            }
            root->check_balance(parent, &root);
        }

        Node<ft::pair<Key, Value> > *find(Key k) { return find_ppal(root, k); }

        Node<ft::pair<Key, Value> > *find_ppal( Node<ft::pair<Key, Value> > *root, Key k)
        {
            if (root == NULL)
                return NULL;
            if (root != end && root != end && root->_data.first == k)
                return root;
            if ( root == end || Compare()(k, root->_data.first))
            {
                if (root->left)
                    return find_ppal(root->left, k);
                return NULL;
            }
            else
            {
                if (root->right)
                    return find_ppal(root->right, k);
                return NULL;
            }
        }

        void remove(Node<ft::pair<Key, Value> > *node)
        {
            Node<ft::pair<Key, Value> > *parent = node->parent;
            if (node->right == NULL && node->left == NULL)
            {
                if (parent->right == node)
                    parent->right = NULL;
                else
                    parent->left = NULL;
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                parent->check_balance(parent, &root);
                size--;
                return;
            }
            else if (node->right == NULL)
            {
                if(parent->right == node)
                {
                    parent->right = node->left;
                    node->left->parent = parent;
                }
                else
                {
                    parent->left = node->left;
                    node->left->parent = parent;
                }
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                parent->check_balance(parent, &root);
                size--;
                return;
            }
            else if (node->left == NULL)
            {
                if(parent->right == node)
                {
                    parent->right = node->right;
                    node->right->parent = parent;
                }
                else
                {
                    parent->left = node->right;
                    node->right->parent = parent;
                }
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
                parent->check_balance(parent, &root);
                size--;
                return;
            }
        }

        Node<ft::pair<Key, Value> > *in_order_pred(Node<ft::pair<Key, Value> > *node)
        {
            node = node->left;
            while (node->right)
                node = node->right;
            return node;
        }

        bool    is_null(Node<ft::pair<Key, Value> > *node) { return (node == NULL || node == end || node == rend); }

        Node<ft::pair<Key, Value> > *get_begin()
        {
            if (size == 0)
                return end;
            if (rend->right)
                return rend->right;
            return rend->parent;
        }

        Node<ft::pair<Key, Value> > *get_rbegin()
        {
            if (size == 0)
                return rend;
            if (end->left)
                return end->left;
            return end->parent;
        }

        Node<ft::pair<Key, Value> > *get_end() { return end; }
        Node<ft::pair<Key, Value> > *get_rend() { return rend; } 
};

#endif
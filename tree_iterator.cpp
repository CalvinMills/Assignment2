#include "tree_iterator.h"

//Constructors and overloads(unfinished ones)

tree_iterator::tree_iterator(){}

tree_iterator::tree_iterator(const tree_iterator &rhs): _node (rhs._node), tree (rhs.tree){}

tree_iterator& tree_iterator:: operator++(){}

node& tree_iterator:: operator *()
{
	if (_node) return *_node;
}

inline bool tree_iterator::operator==(const tree_iterator& rhs)
{
    return _node == rhs._node;
}

inline bool tree_iterator::operator!=(const tree_iterator& rhs)
{
    return !(*this == rhs);
}

tree_iterator::tree_iterator(node *n)
{
    _node = n;
    if (_node != nullptr)
    {
        while (_node->get_number_inserted() != 0)
        {
            tree.push_back(*_node);
            _node = _node->_children[0];
        }
    }
}

//Print inorder(wishful thinking)

void tree_iterator::print_tree()
{
    node current_node = *_node;
                if (current_node._children != NULL)
                {
                    current_node = current_node._children[1][0];
                    while (current_node._children != NULL)
                    {
                        tree.push_back(current_node);
                        current_node = current_node._children[0][0];
                    }
                        tree.push_back(current_node);
                }
                else
                {
                    current_node = tree.back();
                    tree.pop_back();
                    std::cout << "value of node: " << current_node._value << std::endl;
                }

      }

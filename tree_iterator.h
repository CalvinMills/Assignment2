#ifndef tree_iterator_H
#define tree_iterator_H
#include <vector>
#include "node.h"
class tree_iterator
{
    friend class parsetree;
public:

	//default constructor 
    tree_iterator(void);
    //copy constructor
    tree_iterator(const tree_iterator & rhs);
    //Deref operator 
    node& operator *();
    //Increment operator 
    tree_iterator& operator++();
    //Decrement operator 
    tree_iterator& operator--();
    //Comparison overload
    inline bool operator==(const tree_iterator& rhs);
    //Not-Equals
    inline bool operator!=(const tree_iterator& rhs);
    //Distance Incrementor
    tree_iterator& operator+(std::size_t);
    //Distance Decrementor 
    tree_iterator& operator-(std::size_t);
    std::size_t operator-(tree_iterator);
    
    void print_tree();
    node* _node;
private:

    tree_iterator(node *node);
    std::vector<node> tree;
};

#endif // tree_iterator_H

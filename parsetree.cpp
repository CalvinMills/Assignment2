#include "parsetree.h"
using namespace std;
//Default constructor
parsetree::parsetree(){}

//Copy Constructor 
parsetree::parsetree(const parsetree & rhs): tree_iterator(rhs), root (rhs.root){}

//Move Constructor 
parsetree::parsetree(parsetree && rhs): root (move(rhs.root)){}

//Copy Assignment Operator
parsetree &parsetree::operator =(const parsetree & rhs)
{
    if(this != &rhs){root = rhs.root;}
    return *this;
}

//Move Assignment operator 
parsetree &parsetree::operator =(parsetree && rhs)
{
    if(this != &rhs){root = move(rhs.root);}
    return *this;
}

//Destructor 
parsetree::~parsetree(){}

//Begin method
tree_iterator parsetree::begin()
{
    tree_iterator i(root);
    return i;
}

//End method 
tree_iterator parsetree::end()
{
    return tree_iterator(nullptr);
}

//insert
tree_iterator parsetree::insert(tree_iterator parent_node,node &child_node)
{
    tree_iterator insert_iterator;
    if (root == nullptr)
    {
        root = &child_node;
        insert_iterator = begin();
    } else
    {
        parent_node._node->link_node(child_node);
        insert_iterator._node = &child_node;
    }
    return insert_iterator;
}

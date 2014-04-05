#ifndef PARSETREE_H
#define PARSETREE_H
#include "tree_iterator.h"

class parsetree : public tree_iterator
{
public:
	//Global Variables
	node *root = nullptr;
	
	//6 Special Member
	
    //default constructor
    parsetree(void);
    //copy constructor
    parsetree(const parsetree & rhs);
    //move constructor
    parsetree(parsetree && rhs);
    //copy assignment opperator
    parsetree &operator =(const parsetree &rhs);
    //move assignment opperator
    parsetree &operator =(parsetree && rhs);
    //destructor
    ~parsetree();
	//Find first Node
    tree_iterator begin(void);
	//Find last node
    tree_iterator end(void);
	//Insert into tree
    tree_iterator insert(tree_iterator parent, node &child);
    

};

#endif // PARSETREE_H

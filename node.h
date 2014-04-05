#ifndef node_H
#define node_H
#include <sstream>
#include "counter.h"
using namespace std;

class node : public sjp::counter<node>
{
public:
	//list of a node's children
    node ** _children;
    //The value of a node(no specialization)
    string _value;
    
    //constructors
    node(int);
    node(std::string);
    //default constructor
    node(void);
    //copy constructor
    node(const node & rhs);
    //move constructor
    node(node && rhs);
    //copy assignment opperator
    node &operator =(const node &rhs) ;
    //move assignment opperator
    node &operator =(node &&rhs);
    //destructor
    ~node();
	//Copy helper method 
    void copy(const node & other);
	//To string method
    void to_string(std::stringstream& );
	//Accessor and mutator methods 
    int get_max_num_children(void);
    int get_number_inserted(void);
    void set_value(std::string);
	//Link method to link a child to its parent node
    void link_node( node);


private:
	//How many nodes have been inserted out of the maximum allocated children
    int _inserted = 0;
    int maximum_children;
};
#endif // node_H

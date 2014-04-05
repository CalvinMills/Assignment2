#include "node.h"
//6 Special Member function definitions

node::node(int number)
{
    _children = new node*[number];
    maximum_children = number;
    for (int i = 0;i < number;++i)
    {
        _children[i] = new node();
    }
    _value = std::to_string(number);
    _inserted = 0;
}
node::node(std::string value)
{
    _children = NULL;
    _value = value;
    maximum_children = 0;
    _inserted = 0;
}
node::node()
{
    _children = NULL;
    _value = " ";
    maximum_children = 0;
    _inserted = 0;
}
node::node(const node &rhs):_value (rhs._value), _inserted (rhs._inserted), maximum_children (rhs.maximum_children){copy(rhs);}


node::node(node && rhs):_children (std::move(rhs._children)), _value (std::move(rhs._value)), _inserted (std::move(rhs._inserted)),  maximum_children (std::move(maximum_children)){}

node &node::operator =(const node &rhs)
{
    if(this != &rhs)
    {
        maximum_children = rhs.maximum_children;
        _value = rhs._value;
        _inserted = rhs._inserted;
        copy(rhs);
    }
    return *this;
}
node &node::operator =(node &&rhs)
{
    if(this != &rhs)
    {
        _children = new node*[1];
        for (int i = 0;i < rhs.maximum_children;++i)
            _children[i][0] = std::move(rhs._children[i][0]);
        maximum_children = std::move(rhs.maximum_children);
        _value = std::move(rhs._value);
        _inserted = std::move(rhs._inserted);
    }
    return *this;
}
node::~node()
{
}

void node::copy(const node &other)
{
    maximum_children = other.maximum_children;
       if ( maximum_children > 0 )
        {
           _children = new node*[1];
           for (int i = 0;i < other.maximum_children;++i)
           {
               _children[i] = other._children[i];
           }
        }
       else
        _children = NULL;
}

//send value to string stream 
 void node::to_string(std::stringstream& string_stream)
 {
        string_stream << _value;
 }

//Return the maximum children of  a node
int node::get_max_num_children()
{
    return maximum_children;
}
//return current children in a node
int node::get_number_inserted()
{
    return _inserted;
}
//Set the value of a node
void node::set_value(std::string s)
{
    _value = s;
}

//Set up a link betweeen parent and child nodes
void node::link_node(node _link)
{
    if (_inserted < maximum_children)
    {
        _children[_inserted][0] = _link;
        _inserted++;
    }
    else
    {
        std::cout << "Error: Allocated number of children is lower than required for the operation";
	}
}

//MLLCAL002
//Calvin Mills
//Assignment 2


#include <iostream>
#include <vector>
#include "node.h"
#include "parsetree.h"
using namespace std;

int main()
{
    {
	//test case(sorry it's so bad, ran out of time :( )
		parsetree tree;
		parsetree::tree_iterator root_iterator;
		parsetree::tree_iterator iterator1;

		node node1(3);
		root = tree.insert(root_iterator, node1);

		node first("6");
		iterator1 = tree.insert(root_iterator, first);

		node plus("+") ;

		iterator1 = tree.insert(root_iterator, plus);

		node second("5") ;

		iterator1 = tree.insert(root_iterator, second);
		root.print_tree();


    }
    node::print_counts(std::cout, "node");

}



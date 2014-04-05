#include <iostream>
#include <vector>
#include "node.h"
#include "parsetree.h"
using namespace std;

int main()
{
    {
    parsetree p;
    parsetree::tree_iterator root;
    parsetree::tree_iterator j;

    node n(4);
    root = p.insert(root, n);

    node x3("x3");
    j = p.insert(root, x3);

    node eq("=") ;

    j = p.insert(root, eq);

    node m(3) ;

    parsetree::tree_iterator exp;
    exp = p.insert(root, m);

    node y("y");
    j = p.insert(exp, y);

    node plus("+");
    j = p.insert(exp, plus);

    node three("3");
    j = p.insert(exp, three);

    node colon(";");
    j = p.insert(root, colon);

    cout << endl << endl << endl << endl;
    root.print_tree();

    }
    node::print_counts(std::cout, "node");

}


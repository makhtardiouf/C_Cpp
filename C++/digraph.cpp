/**
   Complete Direct graphes demo using the FXT lib
   Makhtar Diouf
   $Id$
   g++ digraph.cpp -o digraph -I/usr/local/include/fxt/ -lfxt
*/

#include <fxttypes.h>
#include <graph/digraph.h>
#include <iostream>
//#include <bits/bitsperlong.h>
#include "malib.h"

using namespace std;

digraph* dg;

// Initialization for the complete graph
digraph* make_digraph(ulong n)
{
//  number of Nodes and Edges
    ulong ng = n, ne = n*(n-1);
// edge connections
    ulong *ep, *e;
    digraph* dgp = new digraph(ng, ne, ep, e);

    ulong j = 0;
// for all nodes
    for (ulong k=0; k < ng; ++k) {
        ep[k] = j;
// connect to all nodes
        for (ulong i=0; i<n; ++i) {
            if ( k==i )  continue;
            e[j++] = i;
        }
    }
    ep[ng] = j;
    return  dgp;
}

// nodes reachable from node at pos p
void listReachable( ulong p)
{
    cout << "\nThe nodes reachable from node " << p << " are:" << endl;
    // 1st and end edges
    ulong fe, en;
    dg->get_edge_idx(p, fe, en);
    for (ulong ep=fe; ep<en; ++ep)
        cout << dg->e_[ep] << ", ";

    int len = getArrLength(dg->e_);
    cout << "\n" << len << " edges listed\n";
}

int main()
{
    dg = make_digraph(15);
    dg->print();
    cout<< "\nedge(2,3): " << dg->has_edge(2, 3);
    cout << "\nedge index(3, 4): " << dg->edge_idx(3, 4);

//dg->randomize_edge_order(2, 3);
    dg->print_horiz("\n\nHorizontal printing:\n");

    listReachable(7);
//cout << "\n\n" << BITS_PER_LONG << endl;
    return 0;
}

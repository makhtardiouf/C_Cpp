
#include "sort/equivclasses.h"  // equivalence_classes()
#include "sort/sortbykey.h"  // sort_by_key()

#include "bits/bitcyclic-dist.h"  // bit_cyclic_dist()
#include "bits/revbin.h"  // revbin()


//#include "perm/permrand.h"  // random_permute()

#include "bits/print-bin.h"  // print_bin()
#include "nextarg.h"  // NXARG()
#include "fxttypes.h"  // ulong
//#include "bits/bitsperlong.h"

#include "fxtio.h"
#include "fxtalloca.h"


//% Equivalence classes: binary bracelets.


static ulong nb;  // number of bits
static ulong mm;  // mask to complement

bool b_equiv_q(ulong x, ulong y)  // bracelets
{
    ulong d = bit_cyclic_dist(x, y, nb);
    if ( 0!=d )  d = bit_cyclic_dist(revbin(x, nb), y, nb);
    return  (0==d);
}
// -------------------------

bool bu_equiv_q(ulong x, ulong y)  // unlabeled bracelets
{
    ulong d = bit_cyclic_dist(x, y, nb);
    x ^= mm;
    if ( 0!=d )  d = bit_cyclic_dist(x, y, nb);

    x = revbin(x, nb);
    if ( 0!=d )  d = bit_cyclic_dist(x, y, nb);
    x ^= mm;
    if ( 0!=d )  d = bit_cyclic_dist(x, y, nb);

    return  (0==d);
}
// -------------------------


int
main(int argc, char **argv)
{
    nb = 6;
    NXARG(nb, "Number of bits of bracelets (0<nb<BITS_PER_LONG).");
    ulong n = 1UL<<nb;
    mm = n-1;

    ulong cq = 0;
    NXARG(cq, "Whether equivalence includes complements (==> unlabeled bracelets).");

    ulong ksq = 0;
    NXARG(ksq, "Whether to print key-sorted array.");

    ALLOCA(ulong, s, n);
    for (ulong k=0; k<n; ++k)  s[k] = k;
//    random_permute(s, n);

    ulong *e = new ulong[n];
    if ( 0==cq )  equivalence_classes(s, n, b_equiv_q, e);
    else          equivalence_classes(s, n, bu_equiv_q, e);

    // --- print all elements with 'coset leaders':
    for (ulong k=0; k<n; ++k)
    {
        cout << setw(3) << k << ": ";
        print_bin(" ", s[k], nb);
        cout << "  " << setw(2) << e[k];
        cout << endl;
    }
    cout << endl;


    sort_by_key(s, n, e, 0, true);
    if ( ksq )
    {
        for (ulong k=0; k<n; ++k)
        {
            cout << setw(3) << k << ": ";
            print_bin(" ", s[k], nb);
            cout << "  " << setw(2) << e[k];
            cout << endl;
        }
        cout << endl;
    }

    // --- print all elements in each equivalence class:
    ulong cct = 0;  // count number of classes
    for (ulong k=0; k<n; /**/ )
    {
        ++cct;
        ulong el = e[k];
        cout << setw(3) << el << ": ";
        ulong ct;
        for (ct=0;  k<n;  ++ct, ++k)
        {
            ulong ek = e[k];
            if ( ek != el )
            {
                break;
            }
            print_bin("  ", s[k], nb);
        }
        cout << "  [#=" << ct << "]";
        cout << endl;
    }
    cout << endl;
    cout << "  # of equivalence classes = " << cct << "";
    cout << endl;

    delete [] e;

    return 0;
}
// -------------------------

/*
 # of bracelets:
% for n in $(seq 1 14); do echo -n "$n: "; ./bin $n 0 | grep 'equivalence classes' | cut -d= -f2; done
1:  2
2:  3
3:  4
4:  6
5:  8
6:  13
7:  18
8:  30
9:  46
10:  78
11:  126
12:  224
13:  380
14:  687

 # of unlabeled bracelets:
% for n in $(seq 1 14); do echo -n "$n: "; ./bin $n 1 | grep 'equivalence classes' | cut -d= -f2; done
1:  1
2:  2
3:  2
4:  4
5:  4
6:  8
7:  9
8:  18
9:  23
10:  44
11:  63
12:  122
13:  190
14:  362

*/

/// Emacs:
/// Local Variables:
/// MyRelDir: "demo/sort"
/// makefile-dir: "../../"
/// make-target: "1demo DSRC=demo/sort/equivclass-bracelets-demo.cc"
/// make-target2: "1demo DSRC=demo/sort/equivclass-bracelets-demo.cc DEMOFLAGS=-DTIMING"
/// End:


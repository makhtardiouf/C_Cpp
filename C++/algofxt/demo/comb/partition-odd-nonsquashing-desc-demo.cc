
#include "comb/partition-odd-nonsquashing-desc.h"

#include "comb/comb-print.h"

#include "fxtio.h"
#include "jjassert.h"

#include "fxttypes.h"
#include "nextarg.h"

//% Non-squashing partitions into odd parts as weakly descending list of parts.
//% A non-squashing partition of n is a partition a[1] + a[2] + ... + a[m] = n
//%   such that a[k] >= sum(j=k+1..m, a[j] ).
//% Lexicographic order.
//% Cf. OEIS sequence A187821.

// Cf. comb/partition-nonsquashing-desc-demo.cc for non-squashing partitions
// Cf. comb/partition-binary-desc-demo.cc for binary partitions

//#define TIMING  // uncomment to disable printing

int
main(int argc, char **argv)
{
    ulong n = 45;
    NXARG(n, "non-squashing partitions of n into odd parts");

    partition_odd_nonsquashing_desc P(n);

    ulong ct = 0;


#ifdef TIMING
    do  { ++ct; }  while ( P.next() );

#else  // TIMING

    ulong m = P.num_parts();
    do
    {
//        cout << m-1 << ", ";  continue;
//        cout << P.data()[m-1] << ", ";  continue;

        ++ct;
        cout << setw(4) << ct << ": ";

        cout << " [" << setw(2) << m << "] ";

//        cout << " [" << setw(2) << n-m << "] ";
//        cout << " [" << setw(2) << P.data()[m-1] << "] ";

        P.print("  ");

        cout << endl;

        jjassert( P.OK() );
    }
    while ( (m=P.next()) );
#endif  // TIMING

    cout << " ct=" << ct << endl;

    return 0;
}
// -------------------------


/*
Timing: (AMD Phenom II X4 945 3000MHz)

 time ./bin 2000
arg 1: 2000 == n  [non-squashing partitions of n into odd parts]  default=45
 ct=1357345312
./bin 2000  8.02s user 0.00s system 99% cpu 8.021 total
 ==> 1357345312/8.02 == 169,245,051 per second

*/


/// Emacs:
/// Local Variables:
/// MyRelDir: "demo/comb"
/// makefile-dir: "../../"
/// make-target: "1demo DSRC=demo/comb/partition-odd-nonsquashing-desc-demo.cc"
/// make-target2: "1demo DSRC=demo/comb/partition-odd-nonsquashing-desc-demo.cc DEMOFLAGS=-DTIMING"
/// End:



#include "comb/tree-lev-seq.h"
#include "comb/word-stats.h"

#include "comb/comb-print.h"


#include "fxtio.h"
#include "fxttypes.h"
#include "jjassert.h"

#include "nextarg.h"

//% Statistics for (level sequences of) unordered rooted trees.
//% Cf. the following OEIS sequences:
//% A000081: all trees.
//% A034781: trees by height.
//% A033185: forests by number of trees.
//% A244372: trees by max branching number (out-degree).
//% A244454: trees by min branching number (out-degree) of non-leaf nodes.


// Cf. comb/ordered-tree-lev-seq-stats-demo.cc for stats for ordered trees

//#define TIMING  // uncomment to disable printing


int
main(int argc, char **argv)
{
    ulong n = 6;
    NXARG(n, "Number of non-root nodes");

    ulong sq = 0;
    NXARG(sq, "Select stats:\n"
          "    0 ==> by height\n"
          "    1 ==> number of ascents\n"
          "    2 ==> number of descents\n"
          "    3 ==> number of ones\n"
//          "    4 ==> number of fixed points\n"  // same stats as 0
          "    5 ==> number of maximal levels\n"
          "    6 ==> position of last occurrence of one\n"
//          "    7 ==> position of first occurrence of the maximal value\n"  // same stats as 0
          "    8 ==> position of last occurrence of the maximal value\n"
//          "    9 ==> number of flat steps\n"
          "   10 ==> number of even values\n"
          "   11 ==> number of odd values\n"
          "   20 ==> number of flat steps\n"
          "   21 ==> number of non-flat steps\n"
          "   25 ==> number of peaks\n"
//          "   11 ==> number of \n"
          );

    bool aa = false;  // whether to print as ASCII art
    NXARG(aa,"Whether to render trees as ASCII art");

    tree_lev_seq T(n);
    word_stats W(T.data(), T.size());

    ulong ct = 0;
    ulong * st = new ulong[n+1];  // stats
    for (ulong k=0; k<n+1; ++k)  st[k] = 0;

#ifndef TIMING
    const ulong *x = T.data();
#endif

    ulong j = 0;
    do
    {
        ++ct;
        ulong s = 0;
        switch ( sq )
        {
        case 0:  // by height: A034781
            s = W.max_val();
//            s = T.height();
            jjassert( s == T.height() );
            // column k==2: A000065 (n-node rooted trees of height 2)
            // column k==3: A000235 (n-node rooted trees of height 3)
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 2, 1, 0,
            // 0, 1, 4, 3, 1, 0,
            // 0, 1, 6, 8, 4, 1, 0,
            // 0, 1, 10, 18, 13, 5, 1, 0,
            // 0, 1, 14, 38, 36, 19, 6, 1, 0,
            // 0, 1, 21, 76, 93, 61, 26, 7, 1, 0,
            // 0, 1, 29, 147, 225, 180, 94, 34, 8, 1, 0,
            // 0, 1, 41, 277, 528, 498, 308, 136, 43, 9, 1, 0,
            // 0, 1, 55, 509, 1198, 1323, 941, 487, 188, 53, 10, 1, 0,
            // 0, 1, 76, 924, 2666, 3405, 2744, 1615, 728, 251, 64, 11, 1, 0,

        case 1:  // by number of ascents: A000000
            s = W.num_ascents();
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 2, 1, 0,
            // 0, 1, 3, 4, 1, 0,
            // 0, 1, 4, 8, 6, 1, 0,
            // 0, 1, 5, 14, 18, 9, 1, 0,
            // 0, 1, 6, 21, 39, 35, 12, 1, 0,
            // 0, 1, 7, 30, 72, 97, 62, 16, 1, 0,
            // 0, 1, 8, 40, 120, 214, 212, 103, 20, 1, 0,
            // 0, 1, 9, 52, 185, 416, 563, 429, 161, 25, 1, 0,
            // 0, 1, 10, 65, 270, 732, 1268, 1344, 804, 241, 30, 1, 0,
            // 0, 1, 11, 80, 378, 1203, 2544, 3499, 2958, 1427, 348, 36, 1, 0,


        case 2:  // by number of descents: A000000
            s = W.num_descents();
            break;
            // 1, 0,
            // 1, 0, 0,
            // 2, 0, 0, 0,
            // 3, 1, 0, 0, 0,
            // 4, 5, 0, 0, 0, 0,
            // 5, 13, 2, 0, 0, 0, 0,
            // 6, 29, 13, 0, 0, 0, 0, 0,
            // 7, 54, 50, 4, 0, 0, 0, 0, 0,
            // 8, 94, 149, 35, 0, 0, 0, 0, 0, 0,
            // 9, 150, 377, 174, 9, 0, 0, 0, 0, 0, 0,
            // 10, 230, 843, 664, 95, 0, 0, 0, 0, 0, 0, 0,
            // 11, 335, 1723, 2089, 588, 20, 0, 0, 0, 0, 0, 0, 0,
            // 12, 475, 3280, 5751, 2706, 262, 0, 0, 0, 0, 0, 0, 0, 0,


        case 3:  // by number of ones: A033185 (forests by number of trees), cf. A106234
            s = W.num_val(1);
//            s = T.branching_number(0);  // same
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 2, 1, 1, 0,
            // 0, 4, 3, 1, 1, 0,
            // 0, 9, 6, 3, 1, 1, 0,
            // 0, 20, 16, 7, 3, 1, 1, 0,
            // 0, 48, 37, 18, 7, 3, 1, 1, 0,
            // 0, 115, 96, 44, 19, 7, 3, 1, 1, 0,
            // 0, 286, 239, 117, 46, 19, 7, 3, 1, 1, 0,
            // 0, 719, 622, 299, 124, 47, 19, 7, 3, 1, 1, 0,
            // 0, 1842, 1607, 793, 320, 126, 47, 19, 7, 3, 1, 1, 0,
            // 0, 4766, 4235, 2095, 858, 327, 127, 47, 19, 7, 3, 1, 1, 0,

//        case 4:  // by number of fixed points: A034781 (same as "by height")
//            s = W.num_fixed_points();
//            break;
//            // 0, 1,
//            // 0, 0, 1,
//            // 0, 0, 1, 1,
//            // 0, 0, 1, 2, 1,
//            // 0, 0, 1, 4, 3, 1,
//            // 0, 0, 1, 6, 8, 4, 1,
//            // 0, 0, 1, 10, 18, 13, 5, 1,
//            // 0, 0, 1, 14, 38, 36, 19, 6, 1,
//            // 0, 0, 1, 21, 76, 93, 61, 26, 7, 1,
//            // 0, 0, 1, 29, 147, 225, 180, 94, 34, 8, 1,
//            // 0, 0, 1, 41, 277, 528, 498, 308, 136, 43, 9, 1,
//            // 0, 0, 1, 55, 509, 1198, 1323, 941, 487, 188, 53, 10, 1,
//            // 0, 0, 1, 76, 924, 2666, 3405, 2744, 1615, 728, 251, 64, 11, 1,

        case 5:  // by number of max levels: A000000
            s = W.num_max_val();
            // colum k==1: A000000
            break;
            // 0, 1,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 2, 1, 1, 0,
            // 0, 4, 3, 1, 1, 0,
            // 0, 9, 6, 3, 1, 1, 0,
            // 0, 21, 14, 7, 4, 1, 1, 0,
            // 0, 51, 33, 16, 9, 4, 1, 1, 0,
            // 0, 126, 82, 39, 22, 10, 5, 1, 1, 0,
            // 0, 318, 204, 99, 54, 24, 13, 5, 1, 1, 0,
            // 0, 814, 520, 252, 140, 62, 32, 14, 6, 1, 1, 0,
            // 0, 2111, 1337, 651, 361, 164, 82, 35, 17, 6, 1, 1, 0,
            // 0, 5532, 3488, 1699, 945, 435, 222, 93, 44, 19, 7, 1, 1, 0,


        case 6:  // position of last one: A000000
            s = W.last_val_idx(1);
            break;
            // 0, 1,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 2, 0, 2, 0,
            // 0, 4, 0, 1, 4, 0,
            // 0, 9, 0, 0, 2, 9, 0,
            // 0, 20, 0, 0, 3, 5, 20, 0,
            // 0, 48, 0, 0, 1, 7, 11, 48, 0,
            // 0, 115, 0, 0, 1, 10, 17, 28, 115, 0,
            // 0, 286, 0, 0, 1, 9, 27, 43, 67, 286, 0,
            // 0, 719, 0, 0, 1, 11, 45, 70, 106, 171, 719, 0,
            // 0, 1842, 0, 0, 1, 16, 54, 127, 180, 271, 433, 1842, 0,
            // 0, 4766, 0, 0, 1, 20, 90, 211, 345, 469, 695, 1123, 4766, 0,

//        case 7:  // position of first occurrence of max: A034781 (same as "by height")
//            s = W.first_max_idx();
//            break;
//            // 1, 0,
//            // 0, 1, 0,
//            // 0, 1, 1, 0,
//            // 0, 1, 2, 1, 0,
//            // 0, 1, 4, 3, 1, 0,
//            // 0, 1, 6, 8, 4, 1, 0,
//            // 0, 1, 10, 18, 13, 5, 1, 0,
//            // 0, 1, 14, 38, 36, 19, 6, 1, 0,
//            // 0, 1, 21, 76, 93, 61, 26, 7, 1, 0,
//            // 0, 1, 29, 147, 225, 180, 94, 34, 8, 1, 0,
//            // 0, 1, 41, 277, 528, 498, 308, 136, 43, 9, 1, 0,
//            // 0, 1, 55, 509, 1198, 1323, 941, 487, 188, 53, 10, 1, 0,
//            // 0, 1, 76, 924, 2666, 3405, 2744, 1615, 728, 251, 64, 11, 1, 0,

        case 8:  // position of last occurrence of max: A000000
            s = W.last_max_idx();
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 0, 2, 0,
            // 0, 0, 1, 3, 0,
            // 0, 0, 1, 3, 5, 0,
            // 0, 0, 1, 5, 7, 7, 0,
            // 0, 0, 1, 8, 14, 13, 12, 0,
            // 0, 0, 1, 13, 28, 31, 24, 18, 0,
            // 0, 0, 1, 20, 57, 72, 62, 43, 31, 0,
            // 0, 0, 1, 31, 113, 168, 158, 119, 77, 52, 0,
            // 0, 0, 1, 46, 224, 383, 405, 324, 223, 142, 94, 0,
            // 0, 0, 1, 68, 435, 871, 1016, 883, 634, 422, 265, 171, 0,
            // 0, 0, 1, 98, 838, 1954, 2534, 2362, 1810, 1234, 810, 516, 329, 0,

//        case 9:  // number of flat steps:
//            s = W.num_flat_steps();
//            break;

        case 10:  // number of even values: A122084 (bicolored trees...)
            s = W.num_even_val();
            break;
            // 0, 1,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 2, 1, 0,
            // 0, 1, 3, 4, 1, 0,
            // 0, 1, 4, 9, 5, 1, 0,
            // 0, 1, 5, 16, 18, 7, 1, 0,
            // 0, 1, 6, 25, 44, 30, 8, 1, 0,
            // 0, 1, 7, 36, 88, 98, 45, 10, 1, 0,
            // 0, 1, 8, 49, 155, 249, 181, 64, 11, 1, 0,
            // 0, 1, 9, 64, 250, 535, 576, 308, 85, 13, 1, 0,
            // 0, 1, 10, 81, 377, 1021, 1506, 1166, 479, 110, 14, 1, 0,
            // 0, 1, 11, 100, 542, 1786, 3410, 3640, 2131, 710, 138, 16, 1, 0,

        case 11:  // number of odd values: A000000
            s = W.num_odd_val();
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 2, 1, 0,
            // 0, 1, 4, 3, 1, 0,
            // 0, 1, 5, 9, 4, 1, 0,
            // 0, 1, 7, 18, 16, 5, 1, 0,
            // 0, 1, 8, 30, 44, 25, 6, 1, 0,
            // 0, 1, 10, 45, 98, 88, 36, 7, 1, 0,
            // 0, 1, 11, 64, 181, 249, 155, 49, 8, 1, 0,
            // 0, 1, 13, 85, 308, 576, 535, 250, 64, 9, 1, 0,
            // 0, 1, 14, 110, 479, 1166, 1506, 1021, 377, 81, 10, 1, 0,
            // 0, 1, 16, 138, 710, 2131, 3640, 3410, 1786, 542, 100, 11, 1, 0,


        case 20: // number of flat steps: A000000
            s = W.num_flat_steps();
            // column k=0: A002955 (rooted trimmed trees with n nodes)
            break;
            // 1, 0,
            // 1, 0, 0,
            // 1, 1, 0, 0,
            // 2, 1, 1, 0, 0,
            // 4, 3, 1, 1, 0, 0,
            // 8, 6, 4, 1, 1, 0, 0,
            // 17, 15, 9, 5, 1, 1, 0, 0,
            // 36, 35, 25, 11, 6, 1, 1, 0, 0,
            // 79, 86, 63, 35, 14, 7, 1, 1, 0, 0,
            // 175, 209, 167, 94, 48, 16, 8, 1, 1, 0, 0,
            // 395, 516, 436, 270, 134, 61, 19, 9, 1, 1, 0, 0,
            // 899, 1275, 1149, 748, 408, 177, 77, 21, 10, 1, 1, 0, 0,
            // 2074, 3171, 3022, 2099, 1187, 573, 230, 93, 24, 11, 1, 1, 0, 0,

        case 21: // number of non-flat steps: A000000
            s = W.num_nonflat_steps();
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 1, 2, 0,
            // 0, 1, 1, 3, 4, 0,
            // 0, 1, 1, 4, 6, 8, 0,
            // 0, 1, 1, 5, 9, 15, 17, 0,
            // 0, 1, 1, 6, 11, 25, 35, 36, 0,
            // 0, 1, 1, 7, 14, 35, 63, 86, 79, 0,
            // 0, 1, 1, 8, 16, 48, 94, 167, 209, 175, 0,
            // 0, 1, 1, 9, 19, 61, 134, 270, 436, 516, 395, 0,
            // 0, 1, 1, 10, 21, 77, 177, 408, 748, 1149, 1275, 899, 0,
            // 0, 1, 1, 11, 24, 93, 230, 573, 1187, 2099, 3022, 3171, 2074, 0,

        case 25: // number of peaks: A000000
            s = W.num_peaks();
            break;
            // 1, 0,
            // 1, 0, 0,
            // 2, 0, 0, 0,
            // 3, 1, 0, 0, 0,
            // 5, 4, 0, 0, 0, 0,
            // 10, 9, 1, 0, 0, 0, 0,
            // 21, 22, 5, 0, 0, 0, 0, 0,
            // 45, 53, 16, 1, 0, 0, 0, 0, 0,
            // 100, 129, 51, 6, 0, 0, 0, 0, 0, 0,
            // 223, 318, 152, 25, 1, 0, 0, 0, 0, 0, 0,
            // 506, 790, 443, 96, 7, 0, 0, 0, 0, 0, 0, 0,
            // 1156, 1974, 1261, 339, 35, 1, 0, 0, 0, 0, 0, 0, 0,
            // 2672, 4954, 3549, 1145, 158, 8, 0, 0, 0, 0, 0, 0, 0, 0,

        case 30: // max flat length: A000000
            s = W.max_flat_length();
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 2, 1, 1, 0,
            // 0, 4, 3, 1, 1, 0,
            // 0, 8, 7, 3, 1, 1, 0,
            // 0, 17, 18, 8, 3, 1, 1, 0,
            // 0, 36, 45, 21, 8, 3, 1, 1, 0,
            // 0, 79, 116, 56, 22, 8, 3, 1, 1, 0,
            // 0, 175, 298, 152, 59, 22, 8, 3, 1, 1, 0,
            // 0, 395, 776, 413, 163, 60, 22, 8, 3, 1, 1, 0,
            // 0, 899, 2025, 1131, 450, 166, 60, 22, 8, 3, 1, 1, 0,
            // 0, 2074, 5322, 3113, 1254, 461, 167, 60, 22, 8, 3, 1, 1, 0,

        case 40: // max frequency in histogram (of level seq.): A000000
            s = W.max_num_vals();
            break;
            // 0, 1,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 2, 1, 0,
            // 0, 1, 5, 2, 1, 0,
            // 0, 1, 9, 7, 2, 1, 0,
            // 0, 1, 18, 18, 8, 2, 1, 0,
            // 0, 1, 32, 47, 24, 8, 2, 1, 0,
            // 0, 1, 60, 116, 71, 26, 9, 2, 1, 0,
            // 0, 1, 107, 282, 202, 85, 30, 9, 2, 1, 0,
            // 0, 1, 196, 666, 572, 261, 101, 32, 10, 2, 1, 0,
            // 0, 1, 351, 1564, 1558, 806, 325, 112, 36, 10, 2, 1, 0,
            // 0, 1, 637, 3609, 4216, 2419, 1044, 377, 130, 39, 11, 2, 1, 0,


        case 50:  // max branching number (out-degree): A244372
            s = T.max_branching_number();
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 2, 1, 0,
            // 0, 1, 5, 2, 1, 0,
            // 0, 1, 10, 6, 2, 1, 0,
            // 0, 1, 22, 16, 6, 2, 1, 0,
            // 0, 1, 45, 43, 17, 6, 2, 1, 0,
            // 0, 1, 97, 113, 49, 17, 6, 2, 1, 0,
            // 0, 1, 206, 300, 136, 50, 17, 6, 2, 1, 0,
            // 0, 1, 450, 787, 386, 142, 50, 17, 6, 2, 1, 0,
            // 0, 1, 982, 2074, 1081, 409, 143, 50, 17, 6, 2, 1, 0,
            // 0, 1, 2178, 5460, 3044, 1169, 415, 143, 50, 17, 6, 2, 1, 0,

        case 51:  // min branching number (out-degree) of internal nodes: A244454
            // colum k=1..10: A244455, A244456, A244457, A244458, A244459,
            //   A244460, A244461, A244462, A244463, A244464
            // Cf. A244530 (same stats for ordered trees)
            s = T.min_branching_number();
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 3, 0, 1, 0,
            // 0, 7, 1, 0, 1, 0,
            // 0, 17, 2, 0, 0, 1, 0,
            // 0, 42, 4, 1, 0, 0, 1, 0,
            // 0, 105, 7, 2, 0, 0, 0, 1, 0,
            // 0, 267, 15, 2, 1, 0, 0, 0, 1, 0,
            // 0, 684, 28, 4, 2, 0, 0, 0, 0, 1, 0,
            // 0, 1775, 56, 7, 2, 1, 0, 0, 0, 0, 1, 0,
            // 0, 4639, 110, 12, 2, 2, 0, 0, 0, 0, 0, 1, 0,
            // 0, 12238, 220, 20, 4, 2, 1, 0, 0, 0, 0, 0, 1, 0,

        case 60:  // number of leaves: A055277
            s = T.num_leaves();
            // columns: A002620, A055278, ..., A055287
            break;
            // 0, 1,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 1, 2, 1, 0,
            // 0, 1, 4, 3, 1, 0,
            // 0, 1, 6, 8, 4, 1, 0,
            // 0, 1, 9, 18, 14, 5, 1, 0,
            // 0, 1, 12, 35, 39, 21, 6, 1, 0,
            // 0, 1, 16, 62, 97, 72, 30, 7, 1, 0,
            // 0, 1, 20, 103, 212, 214, 120, 40, 8, 1, 0,
            // 0, 1, 25, 161, 429, 563, 416, 185, 52, 9, 1, 0,
            // 0, 1, 30, 241, 804, 1344, 1268, 732, 270, 65, 10, 1, 0,
            // 0, 1, 36, 348, 1427, 2958, 3499, 2544, 1203, 378, 80, 11, 1, 0,

        case 70:  // min limb length: A000000
            s = T.min_limb_length();
            // columns: A244455(!)
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 3, 0, 1, 0,
            // 0, 7, 1, 0, 1, 0,
            // 0, 17, 2, 0, 0, 1, 0,
            // 0, 42, 4, 1, 0, 0, 1, 0,
            // 0, 105, 7, 2, 0, 0, 0, 1, 0,
            // 0, 267, 14, 3, 1, 0, 0, 0, 1, 0,
            // 0, 684, 27, 5, 2, 0, 0, 0, 0, 1, 0,
            // 0, 1775, 54, 8, 3, 1, 0, 0, 0, 0, 1, 0,
            // 0, 4639, 106, 14, 4, 2, 0, 0, 0, 0, 0, 1, 0,
            // 0, 12238, 212, 25, 6, 3, 1, 0, 0, 0, 0, 0, 1, 0,

        case 71:  // max limb length: A255704
            s = T.max_limb_length();
            // columns: A002955
            break;
            // 1, 0,
            // 0, 1, 0,
            // 0, 1, 1, 0,
            // 0, 2, 1, 1, 0,
            // 0, 4, 3, 1, 1, 0,
            // 0, 8, 7, 3, 1, 1, 0,
            // 0, 17, 18, 8, 3, 1, 1, 0,
            // 0, 36, 45, 21, 8, 3, 1, 1, 0,
            // 0, 79, 116, 56, 22, 8, 3, 1, 1, 0,
            // 0, 175, 298, 152, 59, 22, 8, 3, 1, 1, 0,
            // 0, 395, 776, 413, 163, 60, 22, 8, 3, 1, 1, 0,
            // 0, 899, 2025, 1131, 450, 166, 60, 22, 8, 3, 1, 1, 0,
            // 0, 2074, 5322, 3113, 1254, 461, 167, 60, 22, 8, 3, 1, 1, 0,


        default:
            cerr << "Invalid choice (exiting)." << endl;
            return 1;
        }

        jjassert( s <= T.size() );
        st[ s ] += 1;


#ifndef TIMING
        cout << setw(4) << ct << ":";

        // print RGS:
        print_vec("  ", x, n, true );

        cout << setw(4) << s;

        if ( aa )
        {
            cout << endl;
            T.print_aa("");
            cout << endl;
        }

        cout << endl;

        //        jjassert( T.OK() );
#endif  // TIMING
    }
    while ( (j=T.next()) );


    ulong sct = 0;
    for (ulong k=0; k<=n; ++k)
    {
        cout << st[k] << ", ";
        sct += st[k];
    }
    cout << endl;

    cout << " ct=" << ct;  // total: OEIS sequence A000081
    cout << endl;

    jjassert( sct == ct );

    delete [] st;

    return 0;
}
// -------------------------

/*

  Print triangle for stats q:


  OEIS example:
  q=0; for n in $(seq 1 13) ; do ./bin $n $q | grep ', $' ; done | nl -v1 -s':  ' -w2 -n rz

C++ comment:
q=0;  for n in $(seq 1 13) ; do ./bin $n $q | grep ', $' ; done | sed 's/^/\/\/ /; s/ $//;'

Extract column c from stats q:
q=0;  c=0;  echo $(for n in $(seq 1 13) ; do ./bin $n $q | grep ', $' ; done | cut -d, -f$((c+1))) | sed 's/ /, /g;'

*/



/// Emacs:
/// Local Variables:
/// MyRelDir: "demo/comb"
/// makefile-dir: "../../"
/// make-target: "1demo DSRC=demo/comb/tree-lev-seq-stats-demo.cc"
/// make-target2: "1demo DSRC=demo/comb/tree-lev-seq-stats-demo.cc DEMOFLAGS=-DTIMING"
/// End:

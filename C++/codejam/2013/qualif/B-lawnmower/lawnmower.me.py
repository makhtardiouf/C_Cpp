#!/usr/bin/env python3

# $Id$
# Codejam qualification round 2013:
# check if a lawn can be cut to the pattern described by a matrix
# Debug with " pdb3.4 lawnmower.py "

import sys

def solve(t, n, m, checkCol=False):
    """
    Check each row and column to see if the lawn eight can be cut approprietly
    """
    ok = True
    for i in range(0, n):
        for j in range(0, m):
            #ok = True
            h = t[i][j]        # min height to cut the lawn
            check = [(val > h) for val in t[i]]
            ok = not any(check)     # all(check)

            print(i, j, t[i])
            print(h, check, ok)
            if ok is False:
                break               # check next row

    print()
    if ok:
        return "YES"

    #ok = True
    if checkCol is False:
        # Transpose to check columns, as the matrix is not square but rectangle
        # thus can't use t[j][i]
        print("--- Cols:")
        t2 = list(zip(*t))
        if t2 == t:
            pass
        else:
            solve(t2, m, n, checkCol=True)

    #if ok:
    #   return "YES"
    #else:
    return "NO"



####### main
try:
    inp = open("B-small-practice.in")
    outp = open("{0}{1}".format(inp.name, ".out2"), mode='w')

    nCases = int(inp.readline().strip())
    print(nCases, " test cases")

    for k in range(1, nCases + 1):
        n, m = [int(x) for x in inp.readline().split(sep=' ')]
        print("n, m:", n, m)

        t = []  # [[0] * n for j in range(m)]
        # Read the rows
        for i in range(n):
            row = [int(x) for x in inp.readline().split(sep=' ')]
            t.append(row)

        line = "Case #{}{}{}\n".format(k, ': ', solve(t, n, m))
        sys.stdout.write(line)
        outp.write(line)

    inp.close()
    outp.close()

except Exception as ex:
    print("Error:", sys.exc_info()[0], ex)
    # raise

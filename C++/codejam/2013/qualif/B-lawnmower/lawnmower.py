#!/usr/bin/env python3

# $Id: lawnmower.py, c86448423bdc  makhtar $
# Codejam qualification round 2013:
# check if a lawn can be cut to the pattern described by a matrix
# Debug with " pdb3.4 lawnmower.py "

import sys

def solve(lawn, n, m, checkCol=False):
    lawn_possible = 1
    for i in range(n):
        for j in range(m):
            row_possible = 1
            for k in range(n):
                    if lawn[k][j] > lawn[i][j]:
                        row_possible = 0
                                        
            col_possible = 1
            for k in range(m):
                    if lawn[i][k] > lawn[i][j]:
                        col_possible = 0
            
            if not (row_possible or col_possible):
                lawn_possible = 0
        
    result = 'YES' if lawn_possible else 'NO'
    return result


####### main
try:
    file = "B-large-practice.in"
    inp = open(file)
    outp = open("{0}{1}".format(file, ".out2"), mode='w')

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

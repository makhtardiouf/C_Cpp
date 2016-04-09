#!/usr/bin/env python3
# Codejam 20160408
# $Id$
#

import sys

def flip(s):
    for i in len(s):
        if s[i] == '+':
            s[i] = '-'
        else:
            s[i] = '+'
    return s.reverse()


# If cols and rows size are the same, t[y][x] can check cols
def solve(t, n, m):
    print("hello")
    pass



#### main
try:
    file = "b-test.in" #"B-small-practice.in"
    inp = open(file)
    outp = open(inp.name + ".out", mode='w')

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

except Exception as ex:
    print("Error: ", sys.exc_info()[0], ex)
    raise

finally:
    inp.close()
    outp.close()


#!/usr/bin/env python3
# Codejam 20160408
# $Id$
# Problem A: counting sheep

import sys
import math

target = set()
for i in range(10):
    target.add(i)

def solve(n):
    if n == 0:
        return "INSOMNIA"

    digits = set()
    i = 1
    last = 0
    while True:
        last = i * n
        for j in str(last):
            digits.add(int(j))

        if(digits == target):
            return last
        i += 1
    print(i, last)


#### main
try:
    file = "A-large.in" #"a-test.in" #
    inp = open(file)
    outp = open(inp.name + ".out", mode='w')
    nCases = int(inp.readline().strip())
    print(nCases, " test cases")

    for k in range(1, nCases + 1):
        n = int(inp.readline().strip())
        print("n:", n)

        line = "Case #{}{}{}\n".format(k, ': ', solve(n))
        sys.stdout.write(line)
        outp.write(line)

except Exception as ex:
    print("Error: ", sys.exc_info()[0], ex)
    raise

finally:
    inp.close()
    outp.close()


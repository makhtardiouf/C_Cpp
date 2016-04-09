#!/usr/bin/env python3
# Codejam 20160408
# $Id$
# Problem B:

import sys

class Cake:
    def __init__(self, chars):
        # min number of time to maneuver
        self.y = 0
        self.S = list(chars)
        self.ref = len(self.S)
        #self.checkref()
        # 1st iteration
        self.it1 = True

    def checkref(self):
        # Determine the ref first = 1st - after +
        self.ref = int(len(self.S)/2)
        return
    ######
        hit = False
        start = 0 #round(self.ref/2)
        sz = len(self.S) #self.ref
        try:
            self.ref = 1
            for i in range(start, self.ref):

                if (self.S[i] == '+'): #and (self.S[i+1] == '+'):
                    if i+1 < len(self.S):
                        self.ref = i
                    break
                    hit = True

        except IndexError:
            return


    def flip(self):
        N = len(self.S)
        # Flip all characters
        flipped = False

        s = self.S[:self.ref]
        sprev = s
        s.reverse()
        self.S[:self.ref] = s
        #for i in range(N):
        remain = list()
        for i in range(self.ref):
            if self.S[i] == '-':
                self.S[i] = '+'
                flipped = True

            elif (i < N) and ('-' in sprev[i+1:self.ref]):
                self.S[i] = '-'
                flipped = True

        if flipped:
            self.it1 = False

        self.y += 1

        print("Ref:", self.ref, ", y:", self.y, ", S:", self.S, ", s:", s)
        #if self.it1:
        self.checkref()
        return self.y


def solve(S):
    if '-' not in S:
        return 0

    c = Cake(S)
    while c.S != None:
        c.flip()
        if '-' not in c.S[:c.ref]:
            return c.y
    return 0



#### main
try:
    file = "b-test.in" #"B-small.in" 
    inp = open(file)
    outp = open(inp.name + ".out", mode='w')

    nCases = int(inp.readline().strip())
    print(nCases, " test cases")

    for k in range(1, nCases + 1):
        S = inp.readline().strip()
        print("S:", S)

        line = "Case #{}{}{}\n".format(k, ': ', solve(S))
        sys.stdout.write(line)
        outp.write(line)

except Exception as ex:
    print("Error: ", sys.exc_info()[0], ex)
    raise

finally:
    inp.close()
    outp.close()


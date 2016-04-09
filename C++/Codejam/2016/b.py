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
        self.top = 0
        self.checktop()
        # 1st iteration
        self.it1 = True

    def checktop(self):
        # Determine the top first = 1st - after +
        hit = False
        sz = len(self.S)
        try:
            for i in range(sz):
                self.top = i
                if (self.S[i] == '-') and (self.S[i+1] == '+'):
                    break
                    hit = True
        except IndexError:
            pass

        if self.top < 1:
            self.top = 1

    def flip(self):
        N = len(self.S)
        # Flip all characters
        flipped = False
        #for i in range(N):
        for i in range(self.top):
            if self.S[i] == '-':
                self.S[i] = '+'
                flipped = True

            else:
                self.S[i] = '-'
                flipped = True

        if flipped:
            self.it1 = False

        self.y += 1
                
        s = self.S[:self.top]
        if len(s) > 1:
            #for j in range(self.top):
            #    self.S[j] = s[self.top-j-1]
            s.reverse()
            self.S[:self.top] = s
        
        print("Top:", self.top, ", y:", self.y, ", S:", self.S, ", s:", s)
        #if self.it1:
        self.checktop()
        return self.y


def solve(S):
    if '-' not in S:
        return 0

    c = Cake(S)
    i = 0
    while i < 10 and (c.S != None):
        c.flip()
        if '-' not in c.S[:c.top]:
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


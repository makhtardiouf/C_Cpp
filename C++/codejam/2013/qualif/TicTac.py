
# Codejam 2013  Qualification solution
# TicTac Toe https://code.google.com/codejam/contest/2270488/dashboard#s=a&a=0
# python TicTac.py < A-small-practice.in 

import sys

def solve(b):

  for c in ['X', 'O']:
    wind1 = True
    wind2 = True
    for x in range(4):
      winh = True
      winv = True
      for y in range(4):

        # cols, rows check
        if b[y][x]!=c and b[y][x]!='T': winv = False
        if b[x][y]!=c and b[x][y]!='T': winh = False
      if winh or winv: return c + ' won'

      # Diagnonal check
      if b[x][x]!=c and b[x][x]!='T': wind1 = False
      if b[3-x][x]!=c and b[3-x][x]!='T': wind2 = False
    if wind1 or wind2: return c + ' won'

  for x in range(4):
    for y in range(4):
      if b[y][x]=='.': return 'Game has not completed'

  return 'Draw'


numcases = int(sys.stdin.readline())

for casenum in range(1,numcases+1):
  board = []
  for i in range(0,5):
    board.append(sys.stdin.readline().strip())
  print 'Case #' + repr(casenum) + ': ' + solve(board)

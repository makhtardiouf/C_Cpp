# Codejam 20160408
#

import sys

def solve():
    pass



#### main
try:
numcases = int(sys.stdin.readline())

for casenum in range(1, numcases+1):
  board = []
  for i in range(0,5):
    board.append(sys.stdin.readline().strip())
  print 'Case #' + repr(casenum) + ': ' + solve(board)

except Exception as ex:
    print("Error: ", sys.exc_info()[0], ex)
    raise

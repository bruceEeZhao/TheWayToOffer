from typing import *

class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        if m<=0 or n<=0 or k<0:
            return 0

        visited = [[0 for i in range(n)] for i in range(m)]

        return self.movingCountcore(m,n,k,0,0,visited)

    def movingCountcore(self, rows,cols,k,row,col,visited):
        count = 0

        if row>=0 and row<rows and col>=0 and col<cols and self.getDigit(row) + self.getDigit(col)<=k and visited[row][col]==0:
            visited[row][col] = 1
            print(visited)
            count = 1 
            r1 = self.movingCountcore(rows, cols, k, row+1, col, visited)
            r2 =  self.movingCountcore(rows, cols, k, row, col+1, visited)
            r3 =  self.movingCountcore(rows, cols, k, row-1, col, visited)
            r4 =  self.movingCountcore(rows, cols, k, row, col-1, visited)
            count=r1+r2+r3+r4+1
            print(r1, r2, r3, r4, count)

        return count

    def getDigit(self, num):
        ret = 0

        while num>0:
            ret += num%10
            num = num//10

        return ret

s = Solution()
s.movingCount(1,2,1)
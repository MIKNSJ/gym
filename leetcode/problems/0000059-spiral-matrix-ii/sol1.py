class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        topBarrier = -1
        leftBarrier = -1
        rightBarrier = n 
        bottomBarrier = n
        matrix = []
        row = []
        num = 1

        for i in range(n):
            row.append(0)
        
        for j in range(n):
            matrix.append(row.copy())

        while True:
            for i in range(leftBarrier + 1, rightBarrier):
                matrix[topBarrier + 1][i] = num
                num+=1
            topBarrier+=1

            if num - 1 >= n * n:
                break

            for j in range(topBarrier + 1, bottomBarrier):
                matrix[j][rightBarrier - 1] = num
                num+=1
            rightBarrier-=1
            
            if num - 1 >= n * n:
                break

            for k in range(rightBarrier - 1, leftBarrier, -1):
                matrix[bottomBarrier - 1][k] = num
                num+=1
            bottomBarrier-=1

            if num - 1 >= n * n:
                break

            for m in range(bottomBarrier - 1, topBarrier, -1):
                matrix[m][leftBarrier + 1] = num
                num+=1
            leftBarrier+=1

            if num - 1 >= n * n:
                break

        return matrix
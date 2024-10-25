class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        topBarrier = -1
        leftBarrier = -1
        rightBarrier = len(matrix[0]) 
        bottomBarrier = len(matrix)
        order = []

        while True:
            for i in range(leftBarrier + 1, rightBarrier):
                order.append(matrix[topBarrier + 1][i])
            topBarrier+=1

            if (len(order) == len(matrix) * len(matrix[0])):
                break

            for j in range(topBarrier + 1, bottomBarrier):
                order.append(matrix[j][rightBarrier - 1])
            rightBarrier-=1
            
            if (len(order) == len(matrix) * len(matrix[0])):
                break

            for k in range(rightBarrier - 1, leftBarrier, -1):
                order.append(matrix[bottomBarrier - 1][k])
            bottomBarrier-=1

            if (len(order) == len(matrix) * len(matrix[0])):
                break

            for m in range(bottomBarrier - 1, topBarrier, -1):
                order.append(matrix[m][leftBarrier + 1])
            leftBarrier+=1

            if (len(order) == len(matrix) * len(matrix[0])):
                break
        
        return order
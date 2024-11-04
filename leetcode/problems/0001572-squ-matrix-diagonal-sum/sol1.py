class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        if len(mat) == 1:
            return mat[0][0]

        leftCol = 0
        rightCol = len(mat) - 1
        sum = 0

        for i in range(len(mat)):
            print(str(i), str(i))
            sum+=mat[i][i]
        
        for j in range(len(mat)):
            print(str(len(mat) - 1 - j), str(j))
            sum+=mat[len(mat) - 1 - j][j]
        
        if (len(mat) % 2 != 0):
            sum-=mat[len(mat) // 2][len(mat) // 2]
        
        return sum
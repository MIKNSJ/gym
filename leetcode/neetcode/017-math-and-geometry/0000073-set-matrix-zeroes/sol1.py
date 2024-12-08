class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        zeroCoords = []

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    zeroCoords.append([i,j])

        for coord in zeroCoords:
            x,y = coord

            for i in range(len(matrix[x])):
                matrix[x][i] = 0

            for j in range(len(matrix)):
                matrix[j][y] = 0

        #print(matrix)
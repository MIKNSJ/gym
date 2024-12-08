class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        startIdx = 0
        endIdx = len(matrix) - 1

        while startIdx <= endIdx:
            for i in range((len(matrix[startIdx]))):
                temp = matrix[startIdx][i]
                matrix[startIdx][i] = matrix[endIdx][i]
                matrix[endIdx][i] = temp

            startIdx+=1
            endIdx-=1

        for i in range(len(matrix)):
            for j in range(i, len(matrix[i])):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp

        #print(matrix)
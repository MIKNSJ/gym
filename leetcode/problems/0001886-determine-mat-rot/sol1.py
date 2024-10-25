class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        for k in range(4):
            startIdx = 0
            endIdx = len(mat) - 1

            while startIdx <= endIdx:
                for i in range((len(mat[startIdx]))):
                    temp = mat[startIdx][i]
                    mat[startIdx][i] = mat[endIdx][i]
                    mat[endIdx][i] = temp

                startIdx+=1
                endIdx-=1

            for i in range(len(mat)):
                for j in range(i, len(mat[i])):
                    temp = mat[i][j]
                    mat[i][j] = mat[j][i]
                    mat[j][i] = temp

            if mat == target:
                return True

        return False
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        visitedRowCells = set([])
        visitedColCells = set([])

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] != ".":
                    if matrix[i][j] not in visitedRowCells:
                        visitedRowCells.add(matrix[i][j])
                    else:
                        return False
            visitedRowCells.clear()

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[j][i] != ".":
                    if matrix[j][i] not in visitedColCells:
                        visitedColCells.add(matrix[j][i])
                    else:
                        return False
            visitedColCells.clear()
        
        return True
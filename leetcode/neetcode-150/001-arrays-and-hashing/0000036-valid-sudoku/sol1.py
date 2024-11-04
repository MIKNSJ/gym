class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        visitedRowCells = set([])
        visitedColCells = set([])
        visitedSubCells = set([])

        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] != ".":
                    if board[i][j] not in visitedRowCells:
                        visitedRowCells.add(board[i][j])
                    else:
                        return False
            visitedRowCells.clear()

        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[j][i] != ".":
                    if board[j][i] not in visitedColCells:
                        visitedColCells.add(board[j][i])
                    else:
                        return False
            visitedColCells.clear()

        subSections = 0
        startRow = 0
        endRow = 2
        startCol = 0
        endCol = 2

        while subSections < 9:
            for i in range(startRow, endRow + 1):
                for j in range(startCol, endCol + 1):
                    if board[i][j] != ".":
                        if board[i][j] not in visitedSubCells:
                            visitedSubCells.add(board[i][j])
                        else:
                            return False
            visitedSubCells.clear()
            subSections+=1
            startCol+=3
            endCol+=3

            if subSections % 3 == 0:
                startCol = 0
                endCol = 2
                startRow+=3
                endRow+=3
        
        return True
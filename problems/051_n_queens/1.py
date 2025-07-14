from typing import List

class GridMetadata:
    def __init__(self, n):
        self.n = n
        self.rows = [False] * n
        self.columns = [False] * n
        self.diag1 = [False] * (2 * n - 1)
        self.diag2 = [False] * (2 * n - 1)

    def setPos(self, row: int, col: int):
        self.rows[row] = True
        self.columns[col] = True
        self.diag1[row - col + self.n - 1] = True
        self.diag2[row + col] = True

    def unsetPos(self, row: int, col: int):
        self.rows[row] = False
        self.columns[col] = False
        self.diag1[row - col + self.n - 1] = False
        self.diag2[row + col] = False

    def checkPos(self, row: int, col: int) -> bool:
        return not self.rows[row] and \
        not self.columns[col] and \
        not self.diag1[row - col + self.n - 1] and \
        not self.diag2[row + col]

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # DP backtracking
        # For a row, assign a queen in each spot,
        # Then, we need to go to the next row and test out new assignments that are valid.
        # how to quickly check if we are valid given the previous row assignments?
        # hashmap of R, C, Diag?
        # complexity:
            # T(N) = N * T(N) = N^N
        # TODO: can we enforce some additional uniqueness constraints then mirror or something to generate unique?
        allBoards = []
        currentBoard = [['.' for _ in range(n)] for _ in range(n)]
        currentMetadata = GridMetadata(n)

        def fillQueens(allBoards: List[List[str]], currentBoard: List[List[str]], currentMetadata: GridMetadata, row: int):
            if row == n:
                allBoards.append([''.join(row) for row in currentBoard])
                return
            
            for col in range(n):
                if currentMetadata.checkPos(row, col):
                    currentMetadata.setPos(row, col)
                    currentBoard[row][col] = 'Q'
                    fillQueens(allBoards, currentBoard, currentMetadata, row+1) 
                    currentMetadata.unsetPos(row, col)
                    currentBoard[row][col] = '.'

        fillQueens(allBoards, currentBoard, currentMetadata, 0)
        return allBoards



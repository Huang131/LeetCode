class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        r = [[1]]
        for i in range(1, numRows):
            r.append([1] + [sum(r[-1][j:j + 2]) for j in range(i)])
        return numRows and r or []
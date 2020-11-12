class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        n = len(s)
        res = []
        jmp = 2*numRows - 2
        
        for i in range(numRows):
            cur = i
            while cur < n:
                res.append(s[cur])
                if i not in (0, numRows-1):
                    if cur + jmp - (2*i) < n:
                        res.append(s[cur + jmp - (2*i)])
                cur += jmp
            
        return ''.join(res)

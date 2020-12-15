class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        
        if n == 0:
            return ''
        
        m = len(strs[0])
        
        for j in range(m):
            for i in range(n):
                if j == len(strs[i]) or strs[i][j] != strs[0][j]:
                    return strs[0][0:j]
                
        return strs[0]

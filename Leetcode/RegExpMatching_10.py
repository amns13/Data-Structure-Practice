class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        ans = [[False]*(n+1) for _ in range(m+1)]
        ans[0][0] = True
        
        for i in range(1, n+1):
            if p[i-1] == '*':
                ans[0][i] = ans[0][i-2]
                
        for i in range(1,m+1):
            for j in range(1, n+1):
                if p[j-1] == s[i-1] or p[j-1] == '.':
                    ans[i][j] = ans[i-1][j-1]
                elif p[j-1] == '*':
                    ans[i][j] = ans[i][j-2]
                    if p[j-2] == s[i-1] or p[j-2] == '.':
                        ans[i][j] = ans[i-1][j] | ans[i][j]
                else:
                    ans[i][j] = False
                    
        return ans[m][n]

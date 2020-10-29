class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        i=0
        curlen = maxlen = 1
        cnt = 0
        xmax = ymax = 0
        
        # First check for oddlength palindromes
        while i < n:
            while i-cnt >= 0 and i+cnt < n and s[i+cnt] == s[i-cnt]:
                cnt += 1
            curlen = 2 * (cnt-1) + 1
            if curlen > maxlen:
                maxlen = curlen
                xmax = i - cnt + 1
                ymax = i + cnt - 1
            i += 1
            cnt = 0
            
        i, j = 0, 1
        cnt = 0
        # Check for Even length palindromes
        while i < n-1 and j < n:
            while i-cnt >= 0 and j+cnt < n and s[i-cnt] == s[j+cnt]:
                cnt += 1
            if cnt > 0:
                curlen = 2 * (cnt-1) + 2
                if curlen > maxlen:
                    maxlen = curlen
                    xmax = i - cnt + 1
                    ymax = j + cnt - 1
            i += 1
            j += 1
            cnt = 0
            
        return s[xmax:ymax+1]

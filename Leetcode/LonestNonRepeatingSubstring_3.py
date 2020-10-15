class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        idx = res = 0
        mp = {}
        
        for i, c in enumerate(s):
            if mp.get(c) is None or mp.get(c) < idx:
                if i == len(s)-1:
                    res = i-idx+1 if i-idx+1 > res else res
                else:
                    mp[c] = i
            else:
                res = i-idx if i-idx > res else res
                idx = mp.get(c) + 1
                mp[c] = i
                
        return res
        

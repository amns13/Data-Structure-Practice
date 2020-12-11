class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        cur = x
        res = 0
        
        while cur:
            tmp = cur % 10
            res = res * 10 + tmp
            cur //= 10
            
        return res == x

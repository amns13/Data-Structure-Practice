class Solution:
    def reverse(self, x: int) -> int:
        is_neg = False
        
        if x < 0:
            is_neg = True
            x *= -1
        res = 0
        while x > 0:
            rem = x % 10
            res = res * 10 + rem
            x //= 10
        if is_neg:
            res *= -1

        # Check if it is within 32-bit Integer range
        if res not in range(-1<<31, (1<<31)-1):
            res = 0
        return res
        

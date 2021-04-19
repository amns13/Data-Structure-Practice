class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        p, s = 1, 0
        while n:
            dgt = n % 10
            p *= dgt
            s += dgt
            n //= 10
            
        return p-s

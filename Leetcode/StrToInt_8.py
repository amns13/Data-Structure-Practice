class Solution:
    def myAtoi(self, s: str) -> int:
        res = 0
        initial_space = True
        is_neg = False
        for c in s:
            if initial_space and c == ' ':
                continue
            if initial_space and c != ' ':
                initial_space = False
                if c == '-':
                    is_neg = True
                    continue
                elif c == '+':
                    continue
            if ord(c) < ord('0') or ord(c) > ord('9'):
                break
            
            digit = ord(c) - ord('0')
            res = res * 10 + digit
        if is_neg:
            res = -res
        if res >= 1 << 31:
            res = (1<<31) - 1
        if res < -(1 << 31):
            res = -(1 << 31)
        return res

class Solution:
    def intToRoman(self, num: int) -> str:
        mp = {1: 'I', 5: 'V', 10: 'X', 50:'L', 100: 'C', 500: 'D', 1000: 'M'}
        mul = 1
        ans = []
        
        while num:
            dgt = num % 10
            
            if dgt < 4:
                tmp = mp[mul] * dgt
            elif dgt == 4:
                tmp = mp[mul] + mp[mul * 5]
            elif dgt > 4 and dgt < 9:
                tmp = mp[mul * 5] + mp[mul] * (dgt - 5)
            else:
                tmp = mp[mul] + mp[mul * 10]
                
            ans.append(tmp)
            num //= 10
            mul *= 10
            
        return ''.join(ans[::-1])

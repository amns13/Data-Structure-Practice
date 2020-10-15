class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for i,num in enumerate(nums):
            if mp.get(target-num) is None:
                mp[num] = i
            else:
                return [mp.get(target-num), i]
        

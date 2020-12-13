class Solution:
    def maxArea(self, height: List[int]) -> int:
        lo, hi = 0, len(height) - 1
        res = 0
        
        while lo < hi:
            area = (hi - lo) * min(height[lo], height[hi])
            res = area if area > res else res
            if height[lo] < height[hi]:
                lo += 1
            else:
                hi -= 1
                
        return res

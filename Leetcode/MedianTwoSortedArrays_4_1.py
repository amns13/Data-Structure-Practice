# O(log(min(m,n)))
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            return find_median(nums2, nums1)
        else:
            return find_median(nums1, nums2)

def find_median(nums1, nums2):
    x, y = len(nums1), len(nums2)
    lo, hi = 0, x

    while lo <= hi:
        partX = (lo + hi)//2
        partY = (x + y + 1)//2 - partX

        maxLeftX = nums1[partX-1] if partX > 0 else float('-inf')
        minRightX = nums1[partX] if partX < x else float('inf')
        maxLeftY = nums2[partY-1] if partY > 0 else float('-inf')
        minRightY = nums2[partY] if partY < y else float('inf')

        if maxLeftX <= minRightY and maxLeftY <= minRightX:
            if (x+y)%2 == 0:
                return (max(maxLeftX, maxLeftY) + min(minRightX,
                    minRightY))/2
            else:
                return max(maxLeftX, maxLeftY)
        elif maxLeftX > minRightY:
            hi = partX - 1
        else:
            lo = partX + 1


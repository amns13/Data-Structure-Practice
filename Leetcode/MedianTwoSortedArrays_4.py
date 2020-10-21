# O(m + n)
class Solution:    
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged = list(merge(nums1, nums2))
        
        n = len(merged)
        if n%2 == 0:
            return (merged[n//2] + merged[n//2 - 1]) / 2
        else:
            return merged[n//2]
        
    def merge(nums1, nums2):
        n1, n2 = len(nums1), len(nums2)
        if n1 == 0:
            return nums2
        if n2 == 0:
            return nums1
        
        i = j = 0
        merged = []
        
        while i < n1 or j < n2:
            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1
        
        while i < n1:
            merged.append(nums1[i])
            i += 1
        while j < n2:
            merged.append(nums2[j])
            j += 1
        return merged

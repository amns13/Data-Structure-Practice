# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        car = 0
        res = cur = None
        
        while l1 or l2:
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            
            s = a+b+car
            sum, car = s % 10, s // 10
            newnode = ListNode(sum)
            if res is None:
                res = newnode
                cur = res
            else:
                cur.next = newnode
                cur = cur.next
                
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        if car == 1:
            newnode = ListNode(1)
            cur.next = newnode
        
        return res
                

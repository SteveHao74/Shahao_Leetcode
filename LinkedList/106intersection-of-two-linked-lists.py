# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
#         if headA is None or headB is None:
#             return None
#         len_headA = 0 
#         len_headB = 0 
#         node_A = headA
#         node_B = headB
#         while node_A is not None or node_B is not None:
#             if node_A is not None:
#                 node_A = node_A.next
#                 len_headA += 1
            
#             if node_B is not None:
#                 node_B = node_B.next
#                 len_headB += 1

#         if len_headA > len_headB:
#             len_diff = len_headA - len_headB
#             node_long = headA
#             node_short = headB
#         else:
#             len_diff = len_headB -len_headA 
#             node_long = headB
#             node_short = headA

#         while node_long is not None:
#             if len_diff == 0:
#                 if node_long == node_short:
#                     return node_long
#                 node_short = node_short.next             
#             else:
#                 len_diff -= 1

#             node_long = node_long.next

# class Solution:
#     def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
#         hash = set()
#         while headA:
#             hash.add(headA)
#             headA = headA.next
#         while headB:
#             if(headB in hash):
#                 return headB
#             headB = headB.next
                            
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        A, B = headA, headB
        while A != B:
            A = A.next if A else headB
            B = B.next if B else headA
        return A


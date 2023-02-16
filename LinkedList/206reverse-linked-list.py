'''
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
'''
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
'''
迭代版
'''


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        index_slow = None
        index_fast = head#index_slow.next
        # index_slow.next = None

        while index_fast is not None:
            temp_node = index_fast.next
            index_fast.next = index_slow
            index_slow = index_fast
            index_fast = temp_node
            # print(index_slow)
        return index_slow

'''
递归版
'''

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        index_slow = None
        index_fast = head#index_slow.next

        return self.reverse(index_slow,index_fast)

    def reverse(self, index_slow, index_fast):
        if index_fast == None:
            return index_slow
        temp_node = index_fast.next
        index_fast.next = index_slow
        index_slow = index_fast
        index_fast = temp_node

        return self.reverse(index_slow,index_fast)
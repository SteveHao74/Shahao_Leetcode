class LinkedListNode:
    def __init__(self,val):
        self.val = val
        self.next = None


class MyLinkedList:

    def __init__(self):
        self.dummy_head =  LinkedListNode(0)
        self.size = 0

    def get(self, index: int) -> int:
        if index>=self.size or index<0 :
            return -1
        temp_node = self.dummy_head
        for _ in range(index+1):
            temp_node = temp_node.next
            # print(temp_node.val)
        return temp_node.val


    def addAtHead(self, val: int) -> None:
        # new_node = LinkedListNode(val)
        # new_node.next = self.dummy_head.next
        # self.dummy_head.next = new_node
        self.addAtIndex(0,val)


    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.size,val)


    def addAtIndex(self, index: int, val: int) -> None:
        if index>self.size:
            return None
        if index< 0:
            index = 0
        temp_node = self.dummy_head
        for _ in range(index):
            temp_node = temp_node.next
        new_node = LinkedListNode(val)
        new_node.next = temp_node.next
        temp_node.next = new_node
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index>=self.size or index<0 :
            return None
        temp_node = self.dummy_head
        for _ in range(index):
            temp_node = temp_node.next
        new_node = temp_node.next.next 
        temp_node.next = new_node
        self.size -= 1



# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
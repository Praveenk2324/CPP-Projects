class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def __contains__(self ):
        

        
    # O(n)
    def append(self, value):
        if self.head is None:
            self.head = Node(value)
        else:
            last = self.head
            while last.next:
                last = last.next
            last.next = Node(value)
    # O(1)
    def prepend(self, value):
        new = Node(value)
        new.next = self.head  
        self.head = new  

    # O(n)
    def insert(self, value, index):
        if index == 0:
            self.prepend(value)
        
        else:
            if self.head is None:
                raise ValueError("Index out of bounds")
            else:
                last = self.head

                for i in range(index - 1):
                    if last.next is None:
                         raise ValueError("Index out of bounds")

                    last = last.next
                
                new_node = Node(value)
                new_node.next = last.next
                last.next = new_node
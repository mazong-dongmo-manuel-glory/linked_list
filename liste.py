import sys
class Node:
    def __init__(self,data):
        self.data = data 
        self.next  = None 

class List:
    def __init__(self,data):
        self.head = Node(data)
        self.length = 1

    def add(self,data):
        ptr = self.head
        while(ptr.next != None):
            ptr = ptr.next 
        ptr.next = Node(data) 
        self.length + 1  
    
    def print(self):
        ptr = self.head 
        while(ptr!=None):
            sys.stdout.write(f"[{ptr.data}]->")
            ptr = ptr.next 
        print("")

    def deleteFirst(self):
        ptr = self.head 
        ptr = ptr.next 
        self.head = ptr

    def sortAsc(self):
        i = self.head 
        while i != None:
            j = i.next 
            iMin = i 
            while j != None:
                if iMin.data>j.data:
                    iMin = j 
                j = j.next 
            temp = iMin.data 
            iMin.data = i.data 
            i.data = temp 
            i = i.next
    
    def sortDesc(self):
        i = self.head 
        while i != None:
            j = i.next 
            iMax = i 
            while j != None:
                if iMax.data<j.data:
                    iMax = j 
                j = j.next 
            temp = iMax.data 
            iMax.data = i.data 
            i.data = temp 
            i = i.next
    
    def reverse(self):
        ptr = self.head 
        while ptr!=None:
            j = ptr.next 
            while j!=None:
                temp = j.data 
                j.data = ptr.data 
                ptr.data = temp 
                j = j.next
            ptr = ptr.next 
    
    def isEmpty(self):
        if self.head != None:
            return False 
        return True 
    def insertFirst(self,data):
        ptr = Node(data)
        ptr.next = self.head 
        self.head = ptr

    def find(self,value):
        ptr = self.head 
        while ptr!=None:
            if ptr.data == value:
                return True 
            ptr = ptr.next
        return False

a = List(10)
a.add(11)
a.add(0)
a.add(1)
a.add(0)
a.print()
a.reverse()
a.print()
a.sortAsc()
a.print()
a.print()
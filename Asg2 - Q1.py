#Creating a class called 'Node'
class Node:
   def __init__(self, my_data):
      self.data = my_data
      self.next = None

class circularLinkedList:  
   def __init__(self):  #Represent the head of circular linked list  
      self.head = None

   def add_data(self, my_data):     #add_data function will add a node to the list 
      ptr_1 = Node(my_data)
      temp = self.head    
      ptr_1.next = self.head

      if self.head is not None:
         while(temp.next != self.head):
            temp = temp.next
         temp.next = ptr_1
      else:
         ptr_1.next = ptr_1
      self.head = ptr_1

   def print_it(self):      #print_it function will print the nodes of the list  
      temp = self.head      #node temp will point to head  
      if(self.head == None):  
            print("List is empty");  
            return;  
      while(temp != None):
            print(temp.data),       #Prints each node by incrementing pointer. 
            temp = temp.next
            if (temp == self.head):
               break
my_list = circularLinkedList()
print("Elements are added to the list ")
my_list.add_data (51)
my_list.add_data (49)
my_list.add_data (25)
my_list.add_data (19)
print("The data is : ")
my_list.print_it()

#With reference to above example of circular linked list.
#Line 17 i.e. while(temp.next != self.head): temp = temp.next 
#Establishes that the traversing element/variable has reached the first element.
#We Know that in a circular linked list the last node points to the head of that linked list, hence we can check that if any node points to the head of linked list then that node is the end of circular linked list.
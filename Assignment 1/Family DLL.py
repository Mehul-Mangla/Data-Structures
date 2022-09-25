#Creating a class called 'Node'
class Node:  
    def __init__(self,name,age):  
        self.name = name;  
        self.age = age; 
        self.previous = None;  
        self.next = None;  
          
class DoublyLinkedList:  
    #Represent the head and tail of the doubly linked list  
    def __init__(self):  
        self.head = None;  
        self.tail = None;  
          
    #addNode function will add a node to the list  
    def addNode(self, name, age):  
        #Create a new node  
        newNode = Node(name,age); 
          
        #If list is empty  
        if(self.head == None):  
            #Both head and tail will point to newNode  
            self.head = self.tail = newNode;  
            #head's previous will point to None  
            self.head.previous = None;  
            #tail's next will point to None, as it is the last node of the list  
            self.tail.next = None;  
        else:  
            #newNode will be added after tail such that tail's next will point to newNode  
            self.tail.next = newNode;  
            #newNode's previous will point to tail  
            newNode.previous = self.tail;  
            #newNode will become new tail  
            self.tail = newNode;  
            #As it is last node, tail's next will point to None  
            self.tail.next = None;  
              
    #display function will print the nodes/ family members of the list  
    def display(self):  
        current = self.head;  #Node current will point to head  
        if(self.head == None):  
            print("List is empty");  
            return;  
        print("Family Members along with age: ");  
        while(current != None):   
            print(current.name, current.age);   #Prints each node by incrementing pointer.  
            current = current.next;  
              
dList = DoublyLinkedList();  
#Add nodes to the list  
dList.addNode('Dad',51);  
dList.addNode('Mom',49);  
dList.addNode('Brother',25); 
dList.addNode('Me',19);  
   
#Displays the nodes present in the list  
dList.display();    
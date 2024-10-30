#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
  Node(int data) 
	{ 
	this->data = data;
	this->next = NULL;
	this->prev = NULL;
	}

};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
	{ head = NULL;
	  tail = NULL;
	}

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int val, int position) {
        if (position < 1) {
            cout << " Invalid." <<endl;
            return;
        }
        Node* newNode = new Node(val);
        if (position == 1) {
            insertAtStart(val);
        } else {
            Node* current = head;
            int currentPosition = 1;

            while (current && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }
            if (!current) {
                cout << "Invalid Position." <<endl;
                delete newNode;
                return;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    void deleteFromStart() {
        if (!head) {
            cout << "List is empty." <<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty." <<endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }
    int count(){
    	int cc=0;
    	Node* front=head;
    		if (!head) {
            cout << "List is empty." <<endl;
            exit;
        }else{
        	
        	while(front){
        		front =front->next;
        		cc++;
			}
		}
	return cc;
	}
    void insertm(int data){
    	int half =count()/2;
    	Node* position=head;
    	if (!head) {
            cout << "List is empty." <<endl;
            return;
        }
        else{
        
        	for(int i=1;i<half-1;i++){
        		position=position->next;
			}
			Node* newnode=new Node(data);
		  newnode->next = position->next;
            newnode->prev = position;
            if (position->next) {
                position->next->prev = newnode;
            }
            position->next = newnode;
		}
	}
    void printreverseList() {
        Node* reverse = tail;
        while (reverse) {
            cout << reverse->data << " ";
            reverse = reverse->prev;
        }
        cout <<endl;
    }
     void deletevalue(int data) {
        if (!head) {
            cout << "List is empty." <<endl;
            return;
        }

        Node* temp = head;
      int cc=count();
		
       if(!head){
       	 cout << "List is empty." <<endl;
            return;
        
	   }
	     
	   else{
	   while(temp){
	   	
        if (temp->data==data) {
        	temp->prev->next=temp->next;
           temp->next=NULL;
                temp->prev=NULL;
             
                return;
        }
        else if(temp==tail){
        	cout<<"The given value does not exist"<<endl;
		}
        	temp=temp->next;
 
	

		 }
   delete temp;
    }
	return;
	}
	Node* acctail(){
		return tail;
	}
	Node* acchead(){
		return head;
	}
};

void merge(DoublyLinkedList L1,DoublyLinkedList L2){
Node* temp1;
Node* temp2;
temp1=L1.acctail();
temp2=L2.acchead();
	temp1->next=temp2;
	temp2->prev=temp1;
}
int main() {
    DoublyLinkedList Dlist;
DoublyLinkedList dlist1;
    Dlist.insertAtStart(8);
    Dlist.insertAtEnd(10);
    Dlist.insertAtStart(4);
    Dlist.insertAtPosition(6, 2);
    Dlist.printList();
    cout<<"Reverse print of Doubly LinkList"<<endl;
    Dlist.printreverseList();
    Dlist.deleteFromStart();
    Dlist.deleteFromEnd();
    Dlist.printList();
    Dlist.insertAtEnd(13);
    Dlist.insertAtPosition(12, 2);
    Dlist.printList();
    int count=Dlist.count();
    cout<<"Size of list "<<count<<endl;
    Dlist.insertm(1);
      Dlist.printList();
    Dlist.insertm(2);
      Dlist.printList();
    Dlist.insertm(3);
      Dlist.printList();
    Dlist.insertm(4);
      Dlist.printList();
      Dlist.deletevalue(16);
         Dlist.deletevalue(1);
    Dlist.printList();
    dlist1.insertAtStart(1);
    dlist1.insertAtStart(2);
    dlist1.insertAtStart(3);
    dlist1.insertAtStart(4);
    dlist1.insertAtStart(5);
    dlist1.insertAtStart(6);
    dlist1.insertAtStart(7);
    dlist1.insertAtStart(8);
    dlist1.insertAtStart(9);
    cout<<"list 2"<<endl;
    dlist1.printList();
    merge(Dlist,dlist1);
    cout<<"Lists after merging"<<endl;
    Dlist.printList();
    return 0;
}


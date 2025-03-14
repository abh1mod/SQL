#include<iostream>
using namespace std;

class Node{
     public: 
     int data;
     Node* next;     
        Node(int val){
            data = val;
            next = NULL;
        }
};

class LinkedList{
	public:
     	Node* p;
     	LinkedList(int val){
     	    p = new Node(val);
     	    p->next = p;
     	}
     	void insert(int val){
     	    Node* temp = new Node(val);
     	      temp->next = p->next;
     	      p->next = temp;
     	      p = p->next;  
     	}
     	void traverse(int n){
     	    for(int i = 0; i<n; i++){
     	        cout<<p->data<<endl;
     	        p = p->next;
     	    }
     	}
	
	Node* findNode(int a){
		Node* temp = p;
		while(true){
		   temp = temp->next;
		   if(temp->data == a) break; 
		}
		return temp;
	}
     	int findDist(int a, int b){
     	    Node* first = findNode(a);
     	    Node* second = findNode(b);
     	    int dist1 = 0; int dist2 = 0;
     	    Node* temp1 = first; 
     	    Node* temp2 = second; 
     	    while(true){
     	    	temp1 = temp1->next;
     	    	dist1++;
     	    	if(temp1 == second) break;
     	    }
     	    while(true){
     	    	temp2 = temp2->next;
     	    	dist2++;
     	    	if(temp2 == first) break;
     	    }
     	    cout<<"Distance between "<<a<<" and "<<b<<" is "; 
     	    return min(dist1,dist2);
     	}

};


int main(){
	LinkedList a = LinkedList(1);
	a.insert(5);
	a.insert(10);
	a.insert(15);
	a.insert(20);
	a.insert(25);
	a.insert(30);
	a.insert(35);
	a.insert(40);
	a.traverse(20);
	cout<<a.findDist(35,10)<<endl;
	
	
	

    return 0;
}

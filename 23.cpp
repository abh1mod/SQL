#include<bits/stdc++.h>
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
      void traverse(Node* head){
        while(head!= NULL){
           cout<< head->data << " ";
           head = head->next; 
        }
        cout<<endl;
      }
      
      Node* insertAtEnd(Node* head, int val){
         Node* endNode = new Node(val);
         if(!head) return endNode; 
         Node* temp = head;
         while(temp->next){
            temp = temp->next;
         }
         temp->next = endNode;
         return head;
      }
      
      Node* insertAtPosition(Node* head, int p, int val){   
          Node* newNode = new Node(val);
          if(p==1){
              newNode->next = head;
              return newNode;
          }
          Node* temp = head;
          for(int i = 1; i<p-1; i++){
             temp = temp->next;
             if(temp==NULL){
                cout<<"Enter Valid Position"<<endl;
                return head;
             }
          }
          newNode->next = temp->next;
          temp->next = newNode;
          return head;
      }
     Node* removeNode(Node* head, int p){
        Node* temp = head;
        if(p==1){
           head = head->next;
           delete temp;
           return head;
        }
        for(int i = 1; i<p-1; i++){
             temp = temp->next;
             if(temp->next==NULL){
                cout<<"Enter Valid Position"<<endl;
                return head;
             }
          }
          Node* temp2 = temp->next;
          temp->next = temp2->next;
          delete temp2;
          return head;
     }


int main(){
   int n;
   Node* head;
   cout<<"Enter Number of Nodes you want to Insert ";
   cin>>n;
   cout<<"Enter Elements ";
   for(int i=0; i<n; i++){
      int x;
      cin>>x;
      if(i==0) head = new Node(x);
      else head = insertAtEnd(head,x);
   }
   cout<<"Enter position and Value to Insert ";
   int p,val;
   cin>>p>>val;
   head = insertAtPosition(head,p,val);
   traverse(head);
   cout<<"Enter position to delete ";
   cin>>p;
   head = removeNode(head,p);
   traverse(head);
   return 0;
}

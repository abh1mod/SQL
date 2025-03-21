#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
      data = val;
      left = nullptr;
      right = nullptr;
    }
};


    void insert(int val, Node* root){
       Node* node = new Node(val);
       if(root == NULL) root = node;
       else{
          Node* temp = root;
          Node* prev = root;
          while(temp){
            prev = temp;
            if(val == temp->data) return;
            if(val < temp->data) temp = temp->left;
            else if(val > temp->data) temp = temp->right;
          }
          if(val < prev->data) prev->left = node;
          if(val > prev->data) prev->right = node;
       }
    }
  
    void preorder(Node* temp){
    	if(!temp) return;
    	cout<<temp->data<<" ";
    	preorder(temp->left);
    	preorder(temp->right);
    }
    void inorder(Node* temp){
    	if(!temp) return;
    	inorder(temp->left);
    	cout<<temp->data<<" ";
    	inorder(temp->right);
    }    
    void postorder(Node* temp){
    	 if(!temp) return;
    	postorder(temp->left);
    	postorder(temp->right);
    	cout<<temp->data<<" ";
    }

int main(){	

    Node* root;
    
    int x;
    int flag = 0;
    while(x){
     cout<<"Enter 1 to Insert Data"<<endl;
     cout<<"Enter 0 to stop"<<endl;
     cin>>x;
     if(x==1){
        int val;
     	cout<<"Enter data ";
     	cin>>val;
       if(!flag){root = new Node(val); flag = 1;}
       else insert(val,root);
     }
    }
    
    cout<<"Preorder "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Postorder "<<endl;
    postorder(root);
    cout<<endl;
    
}

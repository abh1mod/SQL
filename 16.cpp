#include<iostream>
using namespace std;
#define max 5
class Stack{
    int arr[max];
    int idx;

    public:
    	Stack(){
    	idx = -1;
    	}
    	
    	void push(int val){
    	    if(isFull()){
    	    	cout<<"Stack is Full"<<endl;
    	    	return;
    	    }
    	    arr[++idx] = val;
    	}
    	
    	void pop(){
    	   if(isEmpty()){
    	     cout<<"Stack Empty"<<endl;
    	     return;
    	   }
    	   cout<<"Element Popped "<<top()<<endl;
    	   idx--;
    	}
    	
    	int top(){
    	   if(isEmpty()){
    	     cout<<"Stack Empty"<<endl;
    	     return -1;
    	   }
    	   return arr[idx];
    	}
    	
    	bool isFull(){
           return (idx==max-1);
    	}
    	bool isEmpty(){
    	    return (idx==-1);
    	}	
    	int size(){
    	  return idx+1;
    	}
};

int main(){
	Stack st;
	while(true){
          int c;
          cout<<endl;
	  cout<<"Enter 1 for push"<<endl;
	  cout<<"Enter 2 for pop"<<endl;
	  cout<<"Enter 3 for top"<<endl;
	  cout<<"Enter 4 for size"<<endl;
	  cout<<"Enter 5 for terminate"<<endl;
	  cout<<"CHOICE : ";
	  cin>>c;  
	  if(c==1){
	    int val;
	    cout<<"Enter Element ";
	    cin>>val;
	    st.push(val);
	  }
	  else if(c==2) st.pop();
	  else if(c==3) cout<<st.top()<<endl;
	  else if(c==4) cout<<st.size()<<endl;
	  else break;
	  }
	return 0;
}

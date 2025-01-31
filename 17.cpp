#include<iostream>
using namespace std;
#define max 5
class Queue{
    int arr[max];
    int i;
    int j;

    public:
    	Queue(){
    	i = -1;
    	j = -1;
        }   	
    	void enqueue(int val){
    	    if(isFull()){
    	    	cout<<"Queue is Full"<<endl;
    	    	return;
    	    }
    	    if(i==-1 && j==-1){
    	    	i++;
    	    	j++;
    	    	arr[j] = val;
    	    	return;
    	    }
    	    j = (j+1)%max;
    	    arr[j] = val;
    	}
    	
    	void dequeue(){
    	   if(isEmpty()){
    	     cout<<"Queue Empty"<<endl;
    	     return;
    	   }
    	   cout<<"Element deleted is "<<arr[i]<<endl;
    	   if(i==j){
    	      i = -1;
    	      j = -1;
    	   }
    	   else i = (i+1)%max;
    	   
    	}
    	
    	int front(){
    	   if(isEmpty()){
    	     cout<<"Queue Empty"<<endl;
    	     return -1;
    	   }
    	   return arr[i];
    	}
    	
    	bool isFull(){
           return ((j+1)%max == i);
    	}
    	bool isEmpty(){
    	    return(i==-1 && j==-1);
    	}
    	int size(){
    	   if(isEmpty()) return 0;
    	   if(isFull()) return max;
    	   if(i<j) return j-i+1;
    	   return i+j;
    	}
};

int main(){
	Queue q;
	while(true){
          int c;
          cout<<endl;
	  cout<<"Enter 1 for enqueue"<<endl;
	  cout<<"Enter 2 for dequeue"<<endl;
	  cout<<"Enter 3 for front"<<endl;
	  cout<<"Enter 4 for size"<<endl;
	  cout<<"Enter 5 for terminate"<<endl;
	  cout<<"CHOICE : ";
	  cin>>c;  
	  if(c==1){
	    int val;
	    cout<<"Enter Element ";
	    cin>>val;
	    q.enqueue(val);
	  }
	  else if(c==2) q.dequeue();
	  else if(c==3) cout<<q.front()<<endl;
	  else if(c==4) cout<<q.size()<<endl;
	  else break;
	}
	
	return 0;
}

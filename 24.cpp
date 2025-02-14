#include<iostream>
#include<stack>
using namespace std;

void reverseArray(int arr[], int n){
   stack<int> st;
   for(int i=0; i<n; i++) st.push(arr[i]);
   int i = 0;
   while(!st.empty()){
      arr[i] = st.top();
      st.pop();
      i++;
   }
}

int main(){
  int n;
  cout<<"Enter Size of Array : ";
  cin>>n;
  int arr[n];
  cout<<"Enter Elements : ";
  for(int i = 0; i<n; i++) cin>>arr[i];
  reverseArray(arr,n);
  cout<<"After Reverse"<<endl;
  for(auto &ele : arr) cout<<ele<<" ";
  return 0;
}

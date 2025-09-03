#include<bits/stdc++.h>
using namespace std;

void fun(int t0, double alpha, vector<int> time){
	int n = time.size();
	vector<int> next(n,0);
	next[0] = t0;
	for(int i = 1; i<n; i++){
		next[i] = alpha*time[i-1] + (1-alpha)*next[i-1];
	}
	for(int i = 0; i<n; i++){
		cout<<"T"<<i<<"  = "<<next[i]<<endl;
	}
}

int main(){
  	fun(10,0.5, {6,4,6,4,13,13});
}

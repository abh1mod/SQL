#include<bits/stdc++.h>
using namespace std;

void fcfs(vector<int> bt){
	int n = bt.size();
	vector<int> wt(n,0);
	for(int i = 1; i<n; i++){
		wt[i] = wt[i-1] + bt[i-1];
	}
	int waiting_time = 0;
	for(int i = 0; i<n; i++){
		waiting_time += wt[i];
	}
	
	cout<<"AVG waiting time : "<< (double)waiting_time/n <<endl;
	
	
	cout<<"p_id"<<"   "<<"WT"<<endl;
	for(int i = 0; i<n; i++){
		cout<<"p"<<i+1<<"     "<<wt[i]<<endl;
	}

}

int main(){
  	fcfs({6,8,7,3});
}

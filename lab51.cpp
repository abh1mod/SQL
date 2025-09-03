#include<bits/stdc++.h>
using namespace std;

struct Process{
	string pid;
	int at;
	int bt;
	int wt;
	int tat;
	bool done;
};

void fun(int process_cnt, vector<int> burst_time, vector<int> arrival_time){
	vector<Process> process_arr(process_cnt);
	for(int i = 0; i<process_cnt; i++){
		process_arr[i].pid = "P" + to_string(i+1);
		process_arr[i].at = arrival_time[i];
		process_arr[i].bt = burst_time[i];
	}
	int n = process_cnt;
	int finished = 0;
	int time = 0;
	
	while(finished != n){
		
		int bt = INT_MAX;
		Process& toExecute;
		for(int i = 0; i<n; i++){
			if(process_arr[i].done) continue;
			if(process_arr[i].at <= time && process_arr[i].bt < bt){
				toExecute = process_arr[i];
				bt = process_arr[i].bt;
			}
		}

		toExecute.wt = time - toExecute.at;  // current time - arrival time
		toExecute.done = true;
		toExecute.tat = time + toExecute.bt - toExecute.at;  // turn around time = currentTime + burst time - arrival time
		time += toExecute.bt; 
		finished++;
	}
	for(int i = 0; i<n; i++){
		Process &obj = process_arr[i];
		cout<<obj.pid<<" "<<obj.at<<" "<<obj.bt<<" "<<obj.wt<<" "<<obj.tat<<endl;
	}
	
}

int main(){
  	fun()
}

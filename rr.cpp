#include<bits/stdc++.h>
using namespace std;

struct Process{
	int at;
	int bt;
	int rem_bt;
	string p_id;
	Process(int at, int bt, int rem_bt, string p_id){
		this.at = at;
		this.bt = bt;
		this.rem_bt = rem_bt;
		this.p_id = p_id;
	}
};

void insertNewProcess(int current_time, priority_queue<pair<pair<int,int>, string>>& incoming, queue<Process*>& q){
	if(incoming.empty()) return;
	auto t = incoming.top();
	int at = -t.first.first;
	int bt = t.first.second;
	string p_id = it.second;
	if(current_time > at) return;
	incoming.pop();
	Process p = Process(at, bt, bt, p_id);
}

void roundRobin(vector<pair<string, pair<int,int>>>& v, int t){
	priority_queue<pair<pair<int,int>, string>> incoming;
	
	for(auto &ele : v){
		string p_id = ele.first;
		int at = ele.second.first;
		int bt = ele.second.second;
		incoming.push({{-at, bt},p_id});
	}
	
	queue<Process*> q;
	int time = -incoming.top().first.first;
	
	insertNewProcess(time,incoming, q);
	
	while(!incoming.empty()){
		if(q.empty() && !incoming.empty()){
			time = -incoming.top().first.first;
			insertNewProcess(time, incoming, q);
			continue;
		}
		auto current_process = q.front();
		q.pop();
		int at = current_process.at;
		int bt = current_process.bt;
		int rem_bt = current_process.rem_bt;
		string p_id = current_process.p_id;
		
		time -= min(rem_bt , t);
		
		rem_bt -= min(rem_bt, t);
		
		vector<pair<string, vector<int>>> ans;
		
		if(rem_bt > 0){
			q.push(current_process);
		}
		else{
			ans.push_back({p_id,{at, bt, time}});
		}
	}
	for(auto &ele : ans){
		string p_id = ans.first;
		int at = ans.second[0];
		int bt = ans.second[1];
		int ct = ans.second[2];
		int tat = ct - at;
		int wt = tat - bt;
		cout<<p_id<<"  "<<at<<"  "<<bt<<"  "<<ct<<"  "<<tat<<<"  "<<wt<<endl;
	
	}

}

int main(){
	int n;
	cout<<"Enter Number of Process ";
	cin>>n;
	int t;
	cout<<"Enter time quantum ";
	cin>>t;
	
	vector<pair<string, pair<int,int>>> v;
	for(int i = 0; i<n; i++){
		string p_id;
		int at,bt;
		cout<<"Enter process_id, arrival_time, burst_time ";
		cin>>p_id>>at>>bt;
		v.push_back({p_id, {at, bt}});
		
	}
	roundRobin(v, t);
	return 0;
}




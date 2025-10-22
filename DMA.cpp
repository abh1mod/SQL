#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> find_waiting_process(vector<int>& process){
	vector<pair<int,int>> res;
	for(int i = 0; i<process.size(); i++){
		if(process[i] != INT_MAX && process[i] > 0){
			res.push_back({process[i], i});
		}
	}
	return res;
}

void solve(vector<int>& block, vector<int>& process){
	int m = block.size();
	int n = process.size();
	
	int strategy = 0;
	while(strategy>3 || strategy<1){
		cout<<"Enter 1 for First Fit :"<<endl;
		cout<<"Enter 2 for Best Fit  :"<<endl;
		cout<<"Enter 3 for Worst Fit :"<<endl;
	
		cin>>strategy;
	}

	if(strategy == 1){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(process[i] <= block[j]){
					block[j] -= process[i];
					process[i] = INT_MAX;
					cout<<"Process "<<i+1<<" -> "<<"Block "<<j+1<<endl; 
				}
			}
		}
			
	}
	else if(strategy == 2){
		for(int i = 0; i<n; i++){
			int block_ind = INT_MAX;
			int block_size = INT_MAX;
			for(int j = 0; j<m; j++){
				if(block[j] < block_size && block[j] >= process[i]){
					block_ind = j;
					block_size = block[j];
				}
			}
			if(block_size != INT_MAX){
				block[block_ind] -= process[i];
				process[i] = INT_MAX;
				cout<<"Process "<<i+1<<" -> "<<"Block "<<block_ind+1<<endl; 
			}
		}
	}
	else if(strategy == 3){
		for(int i = 0; i<n; i++){
			int block_ind = INT_MIN;
			int block_size = INT_MIN;
			for(int j = 0; j<m; j++){
				if(block[j] > block_size && block[j] >= process[i]){
					block_ind = j;
					block_size = block[j];
				}
			}
			if(block_size != INT_MIN){
				block[block_ind] -= process[i];
				process[i] = INT_MAX;
				cout<<"Process "<<i+1<<" -> "<<"Block "<<block_ind+1<<endl; 
			}
		}
	}
	int total_free = 0;
	vector<pair<int,int>> waiting_process = find_waiting_process(process);
	
	if(waiting_process.size() == 0){
		cout<<"All Process Executed Successfully ";
		return;
	}
	
	for(int i = 0; i<m; i++){
		if(block[i]) total_free += block[i];
	}
	
	cout<<"Total free Space Available : "<<total_free<<endl;
	
	bool to_compact = false;
	cout<<"Do You want to perform compaction on available free memory space 1/0 : ";
	cin>>to_compact;
	
	if(to_compact){
		for(auto &ele : waiting_process){
			int size = ele.first;
			int ind = ele.second;
			if(size <= total_free){
				total_free -= size;
				cout<<"Process "<<ind + 1<<" Executed Successfully"<<endl;
			}
		}		
	}
	else{
		cout<<"Process in Waiting state"<<endl;
		for(auto &ele : waiting_process){
			int size = ele.first;
			int ind = ele.second;
			cout<<"Process "<<ind + 1<<endl;
		
		}
		
	
	}
	
	
	
	
}


int main(){
	int memory_block_cnt;
	int process_cnt;
	cout<<"Enter number of memory blocks and number of process ";
	cin>>memory_block_cnt>>process_cnt;
	vector<int> block(memory_block_cnt); 
	vector<int> process(process_cnt);
	cout<<"Enter "<< memory_block_cnt<< " memory block : ";
	
	for(int i = 0; i<memory_block_cnt; i++){
		cin>>block[i];
	}
	cout<<"Enter "<< process_cnt<< " processes : ";
	for(int i = 0; i<process_cnt; i++){
		cin>>process[i];
	}
	
	solve(block, process);
	
	return 0;
}


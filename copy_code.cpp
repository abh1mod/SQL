#include<bits/stdc++.h>
using namespace std;

// Insert all processes which have arrived at 'time' from incoming queue to ready queue
void insert_new_process(priority_queue<pair<pair<int,int>, string>>& incoming, queue<pair<string, vector<int>>>& q ,int time){
    while(!incoming.empty()){
        auto it = incoming.top();
        int at = -it.first.first;
        if(at > time) break;  // no more arrived processes
        int bt = it.first.second;
        string p_id = it.second;
        incoming.pop();
        q.push({p_id, {at, bt, bt}});  // rem_bt = bt initially
    }
}

void mlq(vector<pair<string, vector<int>>>& process, int time_quantum){
    priority_queue<pair<pair<int,int>, string>> rr_incoming;
    priority_queue<pair<pair<int,int>, string>> fcfs_incoming;

    for(auto &ele : process){
        string p_id = ele.first;
        int at = ele.second[0];
        int bt = ele.second[1];
        int p = ele.second[2];
        if(p == 1){
            rr_incoming.push({{-at,bt},p_id});
        }
        else{
            fcfs_incoming.push({{-at,bt},p_id});
        }
    }

    queue<pair<string, vector<int>>> q; // ready queue
    vector<pair<string, vector<int>>> ans; // store results: p_id, at, bt, completion_time, priority

    int time = 0;

    while(true){
        if(rr_incoming.empty() && fcfs_incoming.empty() && q.empty()) break;

        // Insert all arrived RR processes first
        insert_new_process(rr_incoming, q, time);

        if(!q.empty()){
            auto it = q.front();
            q.pop();
            string p_id = it.first;
            int at = it.second[0];
            int bt = it.second[1];
            int rem_bt = it.second[2];

            int exec_time = min(time_quantum, rem_bt);
            time += exec_time;
            rem_bt -= exec_time;

            // After execution, check if new RR processes arrived
            insert_new_process(rr_incoming, q, time);

            if(rem_bt == 0){
                ans.push_back({p_id, {at, bt, time, 1}}); // priority 1 = RR
            } else {
                q.push({p_id, {at, bt, rem_bt}});
            }
        } 
        else {
            // No RR process in ready queue; try FCFS
            insert_new_process(fcfs_incoming, q, time);

            if(!q.empty()){
                auto it = q.front();
                q.pop();
                string p_id = it.first;
                int at = it.second[0];
                int bt = it.second[1];
                int rem_bt = it.second[2];

                time += rem_bt;
                ans.push_back({p_id, {at, bt, time, 2}}); // priority 2 = FCFS
            } else {
                // No process arrived yet, advance time to earliest arrival
                int next_time = INT_MAX;
                if(!rr_incoming.empty()){
                    next_time = min(next_time, -rr_incoming.top().first.first);
                }
                if(!fcfs_incoming.empty()){
                    next_time = min(next_time, -fcfs_incoming.top().first.first);
                }
                if(next_time != INT_MAX){
                    time = next_time;
                }
            }
        }
    }

    int total_tat = 0;
    int total_wt = 0;

    cout << "P_ID\tAT\tBT\tCT\tPriority\tTAT\tWT\n";

    for(auto &it : ans){
        string p_id = it.first;
        int at = it.second[0];
        int bt = it.second[1];
        int ct = it.second[2];
        int priority = it.second[3];

        int tat = ct - at;
        int wt = tat - bt;
        total_wt += wt;
        total_tat += tat;

        cout << p_id << "\t" << at << "\t" << bt << "\t" << ct << "\t" << priority << "\t\t" << tat << "\t" << wt << "\n";
    }

    cout << "Avg Wt: " << (double)total_wt / ans.size() << endl;
    cout << "Avg Tat: " << (double)total_tat / ans.size() << endl;
}

int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<pair<string, vector<int>>> process(n);

    for(int i = 0; i < n; i++){
        string p_id;
        int at, bt, p;
        cout << "Enter process Id, Arrival Time, Burst Time, Priority (1 for RR, 2 for FCFS): ";
        cin >> p_id >> at >> bt >> p;
        process[i] = {p_id, {at, bt, p}};
    }

    mlq(process, 3);

    return 0;
}


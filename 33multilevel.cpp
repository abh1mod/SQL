#include <bits/stdc++.h>

using namespace std;


class employee{
      protected:
	int id;
	string name;
	int age;
	long mobile_number;
	public:
	employee(){
	   cout<<"Enter id, name, age, mobile_number : ";
	   cin>>id>>name>>age>>mobile_number;
	}	
	void get_e_detail(){
	   cout<<"Employee_id : "<<id<<endl;
	   cout<<"Name        : "<<name<<endl;
	   cout<<"Age         : "<<age<<endl;
	   cout<<"Mobile Num  : "<<mobile_number<<endl;
	}
};

class manager : public employee{
    protected :
       int manager_id;
       string department;
       int team_size;
       public:
       manager(){
          cout<<"Enter manager_id, department, team_size : ";
          cin>>manager_id>>department>>team_size;
       }
       void get_m_detail(){
           cout<<"Manager_id  : "<<manager_id<<endl;
           cout<<"Department  : "<<department<<endl;
           cout<<"Team Size   : "<<team_size<<endl;
       }     
};

class officer : public manager{
    public:
      int officer_id;
      string position;
      officer(){
      	cout<<"Enter officer_id and position : ";
      	cin>>officer_id>>position;
      }
      void get_o_detail(){
           cout<<"Officer_id  : "<<officer_id<<endl;
           cout<<"Position    : "<<position<<endl;
      }
      
};

int main(){
	manager a;
	a.get_e_detail();
	a.get_m_detail();
//	a.get_o_detail();
	

	
	

return 0;
}

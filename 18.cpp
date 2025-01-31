#include<iostream>
using namespace std;

class student{
    int reg_no;
    string name;
    int marks[5];

    public:
    	void insert(string name, int reg_no, int marks[]){
    	    this->name = name;
    	    this->reg_no = reg_no;
    	    for(int i = 0; i < 5; i++) {
                this->marks[i] = marks[i];  
            }
    	}
    	int result(){
           float sum = 0;
           for(auto &ele:marks) sum += ele;
           return sum/5;
        }
        string getName(){
            return name;
        }
        int getRegNo(){
            return reg_no;
        }
};

int main(){
	int n;
	cout<<"Enter Number of student ";
	cin>>n;
	student s[n];
	for(int i = 0; i<n; i++){
           int reg;
           string name;
           int marks[5];
           cout<<"Enter name and reg_number ";
           cin>>name>>reg;
           cout<<"Enter marks of 5 subjects ";
           for(int j = 0; j<5; j++) cin>>marks[j];
           s[i].insert(name,reg,marks);
           cout<<"Result : "<<s[i].result()<<endl;
        }
	
	return 0;
}

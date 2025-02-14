#include <iostream>
#include <stack>
#include <string>
using namespace std;

int result(int a,int b, char op){
	int ans;
	if(op=='+') ans = a+b;
	else if(op=='-') ans = a-b;
	else if(op=='*') ans = a*b;
	else if(op=='/') ans = a/b;
	return ans;
}


int evaluatePostfix(string s) {
    stack<int> st;   
    for(int i = 0; i < s.length(); i++) {
    	char ch = s[i];
        if (isdigit(ch)){
            st.push(ch - '0');
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop(); 
            int ans = result(op2,op1,ch);    
            st.push(ans);
        }
    }
    return st.top();
}

int main() {
   string s; 
   cout<<"Enter a Postfix expression :";
   getline(cin, s);
   cout << "Result of Postfix Evaluation: " << evaluatePostfix(s) << endl;
   return 0;

}



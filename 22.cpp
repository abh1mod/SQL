#include <iostream>
#include <stack>
#include <string>
using namespace std;


char opposite(char ch) {
    if (ch == ')') return '(';
    if (ch == '}') return '{';
    if (ch == ']') return '[';
    return '\0';
}

bool isValid(string s) {
    stack<char> st;
    int n = s.length();
    if (n % 2 == 1) return false; 
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else {
            if (st.empty() || st.top() != opposite(ch)) return false;          
            st.pop();
        }
    }
    return st.empty();
}
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (isValid(s)) cout << "True";
    else cout << "False";
    

    return 0;
}


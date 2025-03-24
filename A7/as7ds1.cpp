

#include <iostream>
#include <stack>
#include <string>

using namespace std;


int evaluatePostfix(string postfix) {
    stack<int> st;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        
        if (isdigit(c)) {
            st.push(c - '0');
        }
        
        else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            
            switch (c) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
            }
        }
    }
    
    return st.top();
}


int main() {
    cout << "Enter postfix expression: ";
    string postfix;
    cin >> postfix;
    cout << "Output: " << evaluatePostfix(postfix) << endl;
    
    return 0;
}
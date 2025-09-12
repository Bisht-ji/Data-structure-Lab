#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix, postfix = "";
    cin >> infix;

    stack<char> st;
    
    for(int i = 0; i < infix.length(); i++) {
        char symb = infix[i];

        if(symb >= 'a' && symb <= 'z') {
            postfix += symb;
        } 
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(symb)) {
                postfix += st.top();
                st.pop();
            }
            st.push(symb);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix: " << postfix << endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define STACKSIZE 50

struct stk {
    char Item[STACKSIZE];
    int Top;
};
struct stk S;

void Initialize() {
    S.Top = -1;
}

bool IsEmpty() {
    return (S.Top == -1);
}

void Push(char x) {
    if (S.Top == (STACKSIZE - 1)) {
        cout << "Stack Overflow";
        exit(1);
    } else {
        S.Top++;
        S.Item[S.Top] = x;
    }
}

char Pop() {
    if (IsEmpty()) {
        cout << "Stack Underflow";
        exit(1);
    } else {
        char x = S.Item[S.Top];
        S.Top--;
        return x;
    }
}

char StackTop() {
    return S.Item[S.Top];
}

bool Prcd(char op1, char op2) {
    
    if (op1 == '(' || op2 == '(') return false;

    if (op1 == '^') {
        // ^ is right associative
        if (op2 == '^') return false;
        else return true;
    } else if (op1 == '*' || op1 == '/' || op1 == '%') {
        if (op2 == '^') return false;
        else return true;
    } else if (op1 == '+' || op1 == '-') {
        if (op2 == '+' || op2 == '-') return true;
        else return false;
    }
    return false;
}

int main() {
    Initialize();
    char Infix[100];
    cin >> Infix;
    string Postfix;
    int i = 0;

    while (Infix[i] != '\0') {
        char symbol = Infix[i];
        i++;

        if (isalnum(symbol)) {
            Postfix.push_back(symbol);
        } else if (symbol == '(') {
            Push(symbol);
        } else if (symbol == ')') {
            while (!IsEmpty() && StackTop() != '(') {
                Postfix.push_back(Pop());
            }
            Pop(); 
        } else{
            while (!IsEmpty() && Prcd(StackTop(), symbol)) {
                Postfix.push_back(Pop());
            }
            Push(symbol);
        }
    }

    while (!IsEmpty()) {
        Postfix.push_back(Pop());
    }

    cout << Postfix;
    return 0;
}

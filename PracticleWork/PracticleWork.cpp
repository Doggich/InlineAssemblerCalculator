#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <cctype>

using namespace std;

int _add(int a, int b) 
{
    int result;

    __asm 
    {
        mov eax, a
        add eax, b
        mov result, eax
    }

    return result;
}
int _sub(int a, int b) 
{
    int result;

    __asm
    {
        mov eax, a
        sub eax, b
        mov result, eax
    }

    return result;
}
int _mul(int a, int b)
{
    int result;

    __asm
    {
        mov eax, a
        mul b
        mov result, eax
    }

    return result;
}
int _div(int a, int b)
{
    int result;

    __asm
    {
        mov edx, 0
        mov eax, a
        div b
        mov result, eax
    }

    return result;
}
int _pow(int a, int b) 
{
    int result;

    __asm 
    {
        mov eax, 1
        mov ebx, a
        mov ecx, b

        cmp ecx, 0

        jle end_pow

        loop_pow:
            mul ebx
            dec ecx
            jnz loop_pow

        end_pow:
            mov result, eax
    }

    return result;
}

bool isNumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

vector<string> infixToRPN(const string& input) {
    map<char, int> priority = 
    { 
        {'+', 1}, {'-', 1}, 
        {'*', 2}, {'/', 2}, 
        {'^', 3}
    };
    vector<string> output;
    stack<char> operators;
    int i = 0;
    while (i < input.size()) {
        if (isspace(input[i])) {
            ++i;
            continue;
        }
        if (isdigit(input[i])) {
            string num;
            while (i < input.size() && isdigit(input[i])) num += input[i++];
            output.push_back(num);
            continue;
        }
        if (input[i] == '(') {
            operators.push('(');
        }
        else if (input[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output.push_back(string(1, operators.top()));
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        }
        else if (priority.count(input[i])) {
            while (!operators.empty() && operators.top() != '(' &&
                priority[operators.top()] >= priority[input[i]]) {
                output.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(input[i]);
        }
        ++i;
    }
    while (!operators.empty()) {
        output.push_back(string(1, operators.top()));
        operators.pop();
    }
    return output;
}

int evalRPN(const vector<string>& tokens) {
    stack<int> st;
    for (const auto& t : tokens) {
        if (isNumber(t)) {
            st.push(stoi(t));
        }
        else if (t == "+") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(_add(a, b));
        }
        else if (t == "-") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(_sub(a, b));
        }
        else if (t == "*") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(_mul(a, b));
        }
        else if (t == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(_div(a, b));
        }
        else if (t == "^") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(_pow(a, b));
        }
    }
    return st.top();
}

int main() {
    while (true) {
        cout << ">> ";
        string pattern;
        getline(cin, pattern);
        if (pattern.empty()) continue;

        vector<string> rpn = infixToRPN(pattern);

        try {
            int answer = evalRPN(rpn);
            cout << "result: " << answer << endl;
        }
        catch (...) {
            cout << "Error, invalid syntax" << endl;
        }
    }
    return 0;
}

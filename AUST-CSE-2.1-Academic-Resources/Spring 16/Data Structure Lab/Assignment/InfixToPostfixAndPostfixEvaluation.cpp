#include <iostream>
#include <string>
#include <stack>

using namespace std;

int charToInt(char x)
{
    return (x-'0');
}

int applyOperator(int x, int y, char op)
{
    switch(op)
    {
    case '+':
        return (x+y);
    case '-':
        return (x-y);
    case '*':
        return (x*y);
    case '/':
        return (x/y);
    }
}

int postfixEvaluation(string s)
{
    stack <int> st;
    int save = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s.at(i)>='0' && s.at(i)<='9')
        {
            save = save * 10 + charToInt(s.at(i));
            if(s.at(i+1)== ' ')
            {
                st.push(save);
                save = 0;
            }
        }
        else if(s.at(i)!= ' ')
        {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            st.push(applyOperator(x, y, s.at(i)));
        }
    }
    return st.top();
}

int priorityCheck(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else if(ch == '#')
    {
        return -1;
    }
    return 0;
}

string infixToPostfix(string s){
    string s2;
    stack<char> st;
    st.push('#');
    int save=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s.at(i)>='0' && s.at(i)<='9')
        {
            s2 += s.at(i);
            if(s.at(i+1)== ' ')
            {
                s2 += ' ';
            }
        }
        else if(s.at(i) != ' ')
        {
            if(s.at(i) == ')')
            {
                char x = st.top();
                st.pop();
                while(x!='(')
                {
                    s2 += x;
                    s2 += ' ';
                    x = st.top();
                    st.pop();
                }
            }
            else if(s.at(i)=='(')
            {
                st.push(s.at(i));
            }
            else
            {
                while(priorityCheck(s.at(i)) <= priorityCheck(st.top()))
                {
                    s2 += st.top();
                    s2 += ' ';
                    st.pop();
                }
                st.push(s.at(i));
            }
        }
    }
    while(st.top()!='#')
    {
        s2 += st.top();
        st.pop();
    }
    return s2;
}

int main()
{
    string s, s2;
    cout << "Enter infix expression: (Please press space after every operand)\n";
    getline(cin, s);
    s2 = infixToPostfix(s);
    cout << "\nPostfix Expression : "<< s2;
    cout << "\n\nResult : "<< postfixEvaluation(s2) << "\n\n";
    return 0;
}

//Postfix:
#include<bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
if(ch == '^')
 return 3;
else if(ch == '/' || ch =='*')
 return 2;
else if(ch == '+' || ch == '-')
 return 1;
else
 return -1;
}


string infixToPostfix(string s)
{
    stack<char> st;
string postfix_exp;

for(int i = 0; i < s.length(); i++)
    {
 char ch = s[i];


 if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
 postfix_exp += ch;

 
 else if(ch == '(')
 st.push('(');

 

 else if(ch == ')') {
 while(st.top() != '(')
 {
  postfix_exp += st.top();
  st.pop();
 }
 st.pop();
 }


 else
        {
 while(!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
  postfix_exp += st.top();
  st.pop();
 }
 st.push(ch);
 }
}


while(!st.empty())
    {
 postfix_exp += st.top();
 st.pop();
}

return postfix_exp;
}

int main()
{
string infix_expression = "A+B";
cout<<"The postfix string is: "<<infixToPostfix(infix_expression);
return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool isValid(string &s){
    stack<char> stack;
    for(int i=0 ;i<s.length();i++){
        if(stack.empty() || s[i]=='{' || s[i]=='(' || s[i]=='[') stack.push(s[i]);
        else if(s[i] == '}' && stack.top() != '{' ) return false;
        else if(s[i] == ')' && stack.top() != '(') return false;
        else if(s[i] == ']' && stack.top() != '[') return false;
        else stack.pop();
    }
    return stack.size() == 0;
}

int main(){
    string s;
    cout<<"Enter the string to check validity : ";
    cin>>s;
    if(isValid(s)) cout<<"The given string is Valid";
    else cout<<"Not Valid!!";
    return 0;
    }
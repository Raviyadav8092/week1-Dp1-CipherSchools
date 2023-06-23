#include<bits/stdc++.h>
using namespace std;

void solve(int open,int close,int n,string curr,vector<string> &ans){
    if(open == close && open == n){
        ans.push_back(curr);
        return;
    } 
    if(open < n){
        curr += '(';
        solve(open+1,close,n,curr,ans);
        curr.pop_back();
    }
    if(close < n && close < open){
        curr += ')';
        solve(open,close+1,n,curr,ans);
        curr.pop_back();
    }
}

vector<string> GenerateParentheses(int n){
    vector<string> ans;
    solve(0,0,n,"",ans);
    return ans;
}

int main(){
    int n;
    cout<<"Enter N:";
    cin>>n;
    vector<string> ans = GenerateParentheses(n);
    for(string i : ans){
        cout<<i<<endl;
    }
    return 0;
    }
#include<bits/stdc++.h>
using namespace std;


void solve(string s,int index,set<string> &ans){
    if(index == s.length()) {
        ans.insert(s);
        return;
    }
    for(int i=0 ;i<s.length();i++){
        swap(s[index],s[i]);
        solve(s,index+1,ans);
        swap(s[index],s[i]);
    }
}

vector<string> Permute(string s){
    set<string> ans;
    solve(s,0,ans);
    return vector<string>(ans.begin(),ans.end());
}

int main(){
    string s;
    cout<<"Enter string:";
    cin>>s;
    vector<string> ans = Permute(s);
    for(string i : ans)
        cout<<i<<endl;

    return 0;
}
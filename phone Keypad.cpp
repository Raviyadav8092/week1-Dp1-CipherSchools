#include<bits/stdc++.h>
using namespace std;

void build_mapping(unordered_map<char,string> &mp){
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
    }

    void solve(string digits,int index,string curr,vector<string> &ans,unordered_map<char,string> &mp){
        if(index == digits.length()) {
            ans.push_back(curr);
        }
        for(char i : mp[digits[index]]){
            curr += i;
            solve(digits,index+1,curr,ans,mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> ans;
        unordered_map<char,string> mp;
        build_mapping(mp);
        solve(digits,0,"",ans,mp);
        return ans;
    }

int main(){
    string s;
    cout<<"Enter String of numbers:\n";
    cin>>s;
    vector<string> ans = letterCombinations(s);
    cout<<"Possible Combinations are :\n";
    for(string i : ans) cout<<i<<endl;
    return 0;
    }
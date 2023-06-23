#include<bits/stdc++.h>
using namespace std;

void solve(int *arr,int n,int index,vector<int> curr,vector<vector<int>> &ans){
    if(index == n) {
        ans.push_back(curr);
        return;
    }
    //exc
    solve(arr,n,index+1,curr,ans);
    //inc
    curr.push_back(arr[index]);
    solve(arr,n,index+1,curr,ans);
    curr.pop_back();
}

vector<vector<int>> PowerSet(int *arr,int n){
    vector<vector<int>> ans;
    solve(arr,n,0,{},ans);
    return ans;
}

int main(){
    int n;
    cout<<"Enter Size of set:";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the values:";
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> ans = PowerSet(arr,n);
    for(vector<int> i : ans)
            {for(int j : i)
                cout<<j<<" ";
        cout<<endl;    }

    return 0;
    }
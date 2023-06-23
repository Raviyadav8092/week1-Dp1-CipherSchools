#include<bits/stdc++.h>
using namespace std;

void solve(bool **arr,int n,int m,int i,int j,string curr,vector<string> &ans){
    if(i==n-1 && j==m-1){
        ans.push_back(curr);
        return;
    }
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j]) return;
    arr[i][j] = true;
    curr += 'L';
    solve(arr,n,m,i,j-1,curr,ans);
    curr.pop_back();
    
    curr += 'R';
    solve(arr,n,m,i,j+1,curr,ans);
    curr.pop_back();
    
    curr += 'U';
    solve(arr,n,m,i-1,j,curr,ans);
    curr.pop_back();
    
    curr += 'D';
    solve(arr,n,m,i+1,j,curr,ans);
    curr.pop_back();
    arr[i][j] = false;
}

vector<string> findpaths(bool **arr,int n,int m){
    vector<string> ans;
    solve(arr,n,m,0,0,"",ans);
    return ans;
}


int main(){
    bool **arr;
    cout<<"Enter number of rows and columns :";
    int n,m;
    cin>>n>>m;
    arr =new bool*[n];
    for(int i=0;i<n;i++) arr[i] = new bool[m];
    cout<<"Enter the values Row-wise:\nNote: 1 means that the cell can not be travelled through by the rat"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    vector<string> ans = findpaths(arr,n,m);
    if(ans.size()==0) {cout<<"Cant reach to destination !!\n";return 0;}
    cout<<"The possible ways are:\n";
    for(string i : ans)
        cout<<i<<endl;
    return 0;
    }
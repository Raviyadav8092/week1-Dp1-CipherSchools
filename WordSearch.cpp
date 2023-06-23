#include<bits/stdc++.h>
using namespace std;

bool dfs(char **board,int n,int m,vector<vector<bool>> &vis,int i,int j,string word,int index){
        if(index == word.length()) return true;
        if(i<0 || j<0 || i>=n|| j>=m || board[i][j] != word[index] || vis[i][j]) return false;
        vis[i][j] = true;
        bool ans = dfs(board,n,m,vis,i+1,j,word,index+1) || dfs(board,n,m,vis,i-1,j,word,index+1) || dfs(board,n,m,vis,i,j+1,word,index+1) || dfs(board,n,m,vis,i,j-1,word,index+1);
        vis[i][j] = false;
        return ans;
    }

    bool exist(char **board,int n,int m, string word) {
        if(word.length() ==0) return true;
        if(n == 0) return false;
        vector<vector<bool>> vis(n+1,vector<bool> (m+1,false));
        bool ans = false;
        for(int i=0;i<n;i++){
            for(int j =0 ;j<m;j++){
            if(board[i][j] == word[0] && dfs(board,n,m,vis,i,j,word,0)) ans = true;
                if(ans) return true;
            }
        }
        return ans;
    }



int main(){
    int n,m;
    cout<<"Enter the number of rows and columns :";
    cin>>n>>m;
    cout<<"Enter the grid row-wise:";
    char **arr= new char*[n];
    for(int i =0 ;i<n;i++) arr[i] = new char[m];
    for(int i =0 ;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>arr[i][j];
    cout<<"Enter the word to be searched:";
    string s;cin>>s;
    if(exist(arr,n,m,s)) cout<<"The word is present in the grid!\n";
    else cout<<"The word is not present in the grid\n";
    return 0;
    }
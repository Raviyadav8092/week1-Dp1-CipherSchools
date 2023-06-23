#include <bits/stdc++.h>
using namespace std;
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
bool dfs(int x, int y, int rows, int cols, vector<vector<int>> &jumps, int move)
{
    if(move == rows*cols - 1)
    {
        jumps[x][y] = move;
        return true;
    }
    
    jumps[x][y] = move;
    
    for(int i=0; i<8; i++)
    {
    	int nextx = x + dx[i];
        int nexty = y + dy[i];
        
        if(nextx >= 0 && nextx < rows && nexty >= 0 && nexty < cols && jumps[nextx][nexty] == -1)
        {
            if(dfs(nextx, nexty, rows, cols, jumps, move+1) == true)
            {
                return true;
            }
        }
    }   
    
    jumps[x][y] = -1;
    return false;
}
vector<vector<int>> knightTour(int rows, int cols) {
    vector<vector<int>> jumps(rows, vector<int>(cols, -1));
    int move = 0;
    
    if(dfs(0, 0, rows, cols, jumps, move) == true)
    {
        return jumps;
    }
    
    vector<vector<int>> x(rows, vector<int>(cols, -1));
    return x;
}

int main(){
    cout<<"Enter the number of rows and columns:";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> ans = knightTour(n,m);
    if(ans[0][0] == -1) {
        cout<<"Invalid Size!!";return 0;
    }
    else{
        for(auto i : ans){
            for(auto j : i)
                cout<<j<<" ";
            cout<<endl;
        }
    }
    
    return 0;
    }
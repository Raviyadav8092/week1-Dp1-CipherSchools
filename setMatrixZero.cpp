#include<bits/stdc++.h>
using namespace std;

void SetMatrixZeroes(int **matrix,int n,int m)
{
    unordered_map<int,int> row,col;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            
                if(matrix[i][j] == 0)
                {
                    row[i]=true;
                    col[j]=true;
                }
                
                
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(row[i] || col[j]) matrix[i][j]=0;
                
                
        return;
}

void print(int **arr,int n,int m){
    
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
            cout<<endl;
            
        }
}

int main()
{
    int **arr;
    int n,m;
    cout<<"Enter number of rows and column:";
    cin>>n>>m;
    arr =new int*[n];
    for(int i=0;i<n;i++) 
        arr[i] = new int[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
    SetMatrixZeroes(arr,n,m);
    
    print(arr,n,m);

    return 0;
    }
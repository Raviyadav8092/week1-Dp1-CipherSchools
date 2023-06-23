#include<bits/stdc++.h>
using namespace std;

bool isPresent(int **matrix,int n,int m,int target,pair<int,int> &p)
{
        int row = n-1;
        int col = 0;
        while(row >=0 && col < m)
        {
            if(matrix[row][col] == target) 
            {
                p.first = row;
                p.second = col;
                return true;
            }
            if(matrix[row][col] > target){
                row--;
            }
            else col++;
        }
        return false;
}

int main()
{
    int **arr;
    int n,m;
    cout<<"Enter number of rows and columns:";
    cin>>n>>m;
    
    arr =new int*[n];
    for(int i=0;i<n;i++) arr[i] = new int[m];
    cout<<"Enter values row-wise in sorted order:";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
    int target;
    cout<< "Enter the value to search:"; 
    cin>>target;
    
    pair<int,int> p;
    if(isPresent(arr,n,m,target,p)){
        cout<<"Value is present at "<<p.first<<" row and "<<p.second<<" column."<<endl;
    }
    
    else cout<<"Value is not present in the matrix"<<endl;
    
    
    
    return 0;
    }
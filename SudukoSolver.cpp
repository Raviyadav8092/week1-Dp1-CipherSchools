#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr,int row,int col,int k){
    for(int i =0;i<9;i++){
        if(arr[i][col] == k || arr[row][i] == k) return false;
        if(arr[3*(row/3)+ i/3][3*(col/3)+i%3] == k) return false;
    }
    return true;
}


bool solve(int **arr){
    for(int i =0 ;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j] == 0){
                for(int k=1;k<=9;k++){
                    if(isSafe(arr,i,j,k)){
                        arr[i][j]= k;
                        bool forward = solve(arr);
                        if(forward) return true;
                        else{
                            arr[i][j] = 0;
                        }
                    }
                }
                return false;



            }
        }
    }

    return true;
}




int main(){
    cout<<"Enter the Sodoku Row-wise:";
    int **arr = new int*[9];
    for(int i =0 ;i<9;i++) arr[i]=new int[9]{0};
    for(int i=0 ;i<9;i++)
        for(int j =0 ;j<9;j++)
            cin>>arr[i][j];
    if(solve(arr)){
        cout<<"Solution is :"<<endl;
        for(int i= 0;i<9;i++)
            {
                for(int j = 0;j<9;j++)
                    cout<<arr[i][j]<<" ";
                cout<<endl;
            }
    }
    else{
        cout<<"The Given Sudoku is not Valid!"<<endl;
    }

    return 0;
    }
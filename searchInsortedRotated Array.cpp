#include<bits/stdc++.h>
using namespace std;

bool isPresent(int *arr,int start,int end ,int target,int &idx){
    if(start > end) return false;
    int mid = start + (end - start)/2;
    if(arr[mid] == target) {
        idx = mid;
        return true;
    }
    if(arr[mid] >= arr[start]){
        if(target >= arr[start] && target <= arr[mid]){
            return isPresent(arr,start,mid,target,idx);
        }
        else{
            return isPresent(arr,mid+1,end,target,idx);
        }
    }
    else{
        if(target >= arr[mid] && target <= arr[end])
            return isPresent(arr,mid,end,target,idx);
        else
            return isPresent(arr,start,mid-1,target,idx);
    }
}

int main(){
    int *arr;
    cout<<"Enter N:";
    int n;cin>>n;
    arr =new int[n];
    cout<<"Enter the sorted and rotated array:";
    for(int i=0;i<n;i++) cin>>arr[i];
    int target;
    cout<<"Enter value to search:";
    cin>>target;
    int idx=-1;
    if(isPresent(arr,0,n-1,target,idx)){
        cout<<"The element is present at index : "<<idx<<endl;
    }
    else cout<<"Element Not Found!"<<endl;
    return 0;
    }
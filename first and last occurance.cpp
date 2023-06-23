#include<bits/stdc++.h>
using namespace std;

int FirstOccurence(int *arr,int n,int target){
    int low = 0,high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target) {
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] > target){
            high = mid-1;
        }
        else low++;
    }
    return ans;
}
int LastOccurence(int *arr,int n,int target){
    int low = 0,high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target) {
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] > target){
            high = mid-1;
        }
        else low++;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter N:";
    cin >>n;
    int *arr= new int[n];
    cout<<"Enter elements in sorted order:";
    for(int i=0 ;i<n;i++) cin>>arr[i];
    cout<<"Enter the value to find the first and last occurence:";
    int key;cin>>key;
    cout<<FirstOccurence(arr,n,key) <<" is the first occurence and "<<LastOccurence(arr,n,key)<<" is the last occurence"<<endl;
    return 0;
    }
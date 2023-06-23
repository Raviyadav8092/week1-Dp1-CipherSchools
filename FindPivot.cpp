#include<bits/stdc++.h>
using namespace std;

int findpivot(int *nums,int n){
        int low = 0;
        int high = n-1;
        if(n==1) return nums[0];
        if(n==2) return min(nums[0],nums[1]);
        if(nums[low] <= nums[high]) return nums[low];
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[high]) high=mid;
            else low = mid+1;
        }
        return nums[low];
}


int main(){
    int *arr;
    int n;
    cout<<"Enter N:";
    cin>>n;
    arr= new int[n];
    cout<<"Enter values of Rotated Sorted Array:";
    for(int i=0;i<n;i++) cin>>arr[i];
    int x= findpivot(arr,n);
    cout<<"The pivot element is "<<x<<endl;

    return 0;
    }
#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(int* arr,int n) {
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] < arr[mid+1]){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }

int main(){
    int *arr;
    int n;
    cout<<"Enter N:";
    cin>>n;
    arr= new int[n];
    cout<<"Enter values of Mountain Array:";
    for(int i=0;i<n;i++) cin>>arr[i];
    int x= peakIndexInMountainArray(arr,n);
    cout<<"The Mountain element is "<<arr[x]<<endl;
    return 0;
    }
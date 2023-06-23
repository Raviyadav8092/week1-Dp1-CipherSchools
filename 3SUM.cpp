#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(int *nums,int n) {
        set<vector<int>> ans;
        sort(nums,nums+n);
        for(int k=0 ;k<n-2;k++){
            int i =k+1,j=n-1;
            while(i<j){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.insert({nums[k],nums[i++],nums[j]});
                }
                else if (sum > 0){
                    j--;
                }
                else i++;
            }
        }
        return vector<vector<int>> (ans.begin(),ans.end());
    }

int main(){
    int *arr;
    int n;
    cout<<"Enter N:";
    cin>>n;
    arr= new int[n];
    cout<<"Enter values of Rotated Sorted Array:";
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> ans = threeSum(arr,n);
    cout<<"The triplets are: \n";
    for(auto i: ans){
        for(int j:i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
    }
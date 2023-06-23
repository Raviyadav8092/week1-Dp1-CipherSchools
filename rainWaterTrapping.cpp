#include<bits/stdc++.h>
using namespace std;

int TrappedRainwater(int *height,int n) 
{
        vector<int> lmax(n),rmax(n);
        
        lmax[0]=height[0];
        
        rmax[n-1]=height[n-1];
        
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(height[i],lmax[i-1]);
            rmax[n-i-1]=max(height[n-i-1],rmax[n-i]);
        }
        
        int water = 0;
        
        for(int i= 1;i<n-1;i++)
        {
            water += (min(lmax[i],rmax[i])-height[i]);
        }
        
        return water;
    }

int main()
{
    cout<<"Enter N:";
    int n;
    cin>>n;
    int *arr;
    arr =new int[n];
    cout<<"Enter heights :";
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    cout<<TrappedRainwater(arr,n);
    
    
    return 0;
    }
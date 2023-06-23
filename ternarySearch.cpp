#include<bits/stdc++.h>
using namespace std;

void inputData(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

int ternarySearch(vector<int> &arr, int target)
{
    int lb = 0, rb = arr.size() -1;

    while(lb <= rb)
    {
        int mid1 = lb + (rb - lb) / 3;
        int mid2 = rb - (rb - lb) / 3;

        if(arr[mid1] == target) {
            return mid1;
        }
        if(arr[mid2] == target) {
            return mid2;
        }

        if(arr[mid1] > target) {
            rb = mid1 -1;
        }
        else if(arr[mid2] < target){
            lb = mid2 +1;
        }
        else {
            lb = mid1 +1;
            rb = mid2 -1;
        }
    }
    return -1;
}

int main()
{
    int n, target;
    cin>> n >> target;

    vector<int> arr(n);
    inputData(arr, n);

    cout<< ternarySearch(arr, target);
}
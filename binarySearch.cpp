#include<bits/stdc++.h>
using namespace std;

void inputData(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

int binarySearch(vector<int> &arr, int target)
{
    int lb = 0, rb = arr.size() -1;

    while(lb <= rb)
    {
        int mid = lb + (rb - lb) / 2;

        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] > target) {
            rb = mid -1;
        }
        else {
            lb = mid +1;
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

    cout<< binarySearch(arr, target);
}
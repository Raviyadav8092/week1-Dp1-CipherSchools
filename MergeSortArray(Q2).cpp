#include<iostream>
#include<vector>

using namespace std;

void takeInput(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
        cin>> arr[i];
}

void print(vector<int>& arr)
{
    for(int i =0; i < arr.size(); i++)
        cout<< arr[i] << ' ';
    cout<< endl;
}

int lastOccurance(vector<int>& arr, int target, int x, int n)
{
    int lb = x, rb = n -1;
    int lastInd = -1;
    while(lb <= rb)
    {
        int mid = lb + (rb - lb) / 2;

        if(arr[mid] < target) {
            lb = mid +1;
        }
        else if(arr[mid] > target){
            rb = mid -1;
        }
        else {
            lastInd = mid;
            lb = mid +1;
        }
    }

    return lastInd;
}

int firstOccurance(vector<int>& arr, int target)
{
    int lb = 0, rb = arr.size() -1;
    int firstInd = -1;

    while(lb <= rb)
    {
        int mid = lb + (rb - lb) / 2;

        if(arr[mid] < target) {
            lb = mid +1;
        }
        else if(arr[mid] > target){
            rb = mid -1;
        }
        else {
            firstInd = mid;
            rb = mid -1;
        }
    }

    return firstInd;
}

int main()
{
    int n, target;
    cin>> n >> target;

    vector<int> arr(n);
    takeInput(arr);

    int first = -1, last = -1;

    first = firstOccurance(arr, target);

    if(first != -1) {
        last = lastOccurance(arr, target, first, n);
    }

    cout<< first << ' ' << last << endl;
}
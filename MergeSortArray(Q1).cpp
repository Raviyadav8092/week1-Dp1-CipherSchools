#include<iostream>
#include<vector>
using namespace std;

void inputData(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

void print(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<< arr[i] << ' ';
    cout<< endl;
}

void mergeSort(vector<int>& arr1, vector<int>& arr2, int m, int n)
{
    int i = m -1, j = n -1, k = m +n -1;

    while(i >= 0 && j >= 0) {
        if(arr1[i] >= arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        }
        else {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
}

int main()
{
    int m, n;
    cin>> m >> n;
    vector<int> arr1(m +n), arr2(n);

    inputData(arr1, m);
    inputData(arr2, n);

    mergeSort(arr1, arr2, m, n);

    print(arr1);
}
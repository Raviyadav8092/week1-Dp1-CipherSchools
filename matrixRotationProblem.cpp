#include<iostream>
#include<vector>
using namespace std;

void takeInput(vector<vector<int>> &matrix)
{
    int n; cin>> n;
    for(int i = 0; i < n; i++) {
        vector<int> row(n);
        for(int j = 0; j < n; j++) {
           cin>> row[j];
        }
        matrix.push_back(row);
    }
}

void print(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<< matrix[i][j] << ' ';
        } cout<< endl;
    }cout<<endl;
}

void tranposeMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotatematrix(vector<vector<int>> &matrix)
{
    tranposeMatrix(matrix);

    int n = matrix.size();

    for(int i = 0; i < n; i++) {
        int lb = 0, rb = n -1;
        while(lb < rb) {
            int temp = matrix[i][lb];
            matrix[i][lb] = matrix[i][rb];
            matrix[i][rb] = temp;
            lb++;
            rb--;
        }
    }
}

int main()
{

    vector<vector<int>> matrix;

    takeInput(matrix);

    rotatematrix(matrix);
    cout<< endl;

    print(matrix);
}
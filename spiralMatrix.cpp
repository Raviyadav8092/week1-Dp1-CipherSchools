#include<iostream>
#include<vector>
using namespace std;

void takeInput(vector<vector<int>> &matrix, int m, int n)
{

    for(int i = 0; i < m; i++) {
        vector<int> row(n);
        for(int j = 0; j < n; j++) {
           cin>> row[j];
        }
        matrix.push_back(row);
    }
}

void print(vector<vector<int>> &matrix, int m, int n)
{
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<< matrix[i][j] << ' ';
        } cout<< endl;
    }cout<<endl;
}

vector<int> spiralMatrix(vector<vector<int>> matrix, int m, int n)
{
    vector<int> result;

    int startRow = 0, endRow = m -1;
    int startCol = 0, endCol = n -1;

    while(startRow <= endRow && startCol <= endCol)
    {

        for(int i = startCol; i <= endCol; i++) {
            result.push_back(matrix[startRow][i]);
        } startRow++;

        for(int i = startRow; i <= endRow; i++) {
            result.push_back(matrix[i][endCol]);
        } endCol--;

        if(startRow > endRow || startCol > endCol)
            break;

        for(int i = endCol; i >= startCol; i--) {
            result.push_back(matrix[endRow][i]);
        } endRow--;


        for(int i = endRow; i >= startRow; i--) {
            result.push_back(matrix[i][startCol]);
        } startCol++;
    }

    return result;
}

int main()
{

    int m, n;
    cin>> m >> n;

    vector<vector<int>> matrix;
    takeInput(matrix, m, n);

    vector<int> result = spiralMatrix(matrix, m, n);

    cout<< endl;
    for(int i = 0; i < result.size(); i++)
        cout<< result[i] << ' ';

}
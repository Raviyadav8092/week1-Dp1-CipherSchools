#include<bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int size=0;
    int capacity=0;
    int *arr;
    int top=-1;
    
    public:
        StackUsingArray(){}
        StackUsingArray(int cap){
            capacity = cap;
            arr= new int[cap];

        }
        void push(int ele){
            if(size == capacity) {
                cout<<"Stack Overflow !!"<<endl;
                return;
            }
            arr[++top] = ele;
            size++;
        }
        int pop(){
            if(size == 0){
                cout<<"Stack Underflow !!"<<endl;
            }
            int ele = arr[top];
            size--;
            top--;
            return ele;
        }
        bool empty() {return size == 0;}
        int getSize() {return size;}
        void print(){
            if(size == 0) {
                cout<<"Stack is empty!!"<<endl;
                return;
            }
            for(int i = size - 1;i>=0;i--){
                cout<< arr[i] <<" ";
            }
            cout<<endl;
        }
};

int main(){
    StackUsingArray *mystack = new StackUsingArray(30);
    for(int i= 0 ;i<10;i++) mystack->push(i+1);
    mystack->print();
    return 0;
    }
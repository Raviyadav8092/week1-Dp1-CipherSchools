#include<bits/stdc++.h>
using namespace std;

class myQueue{
    int size=0;
    int *arr;
    int back=0;
    int front=0;
    public:
        myQueue(){}
        myQueue(int cap){
            arr = new int[cap];
            size = cap;
        }
        bool isempty(){
            return front == back;
        }
        bool isfull(){
            return (back + 1)%size == front;
        }
        void enqueue(int ele){
            if(isfull()){
                cout<<"Queue Overflow"<<endl;
                return ;
            }
            back = (back+1) % size;
            arr[back] = ele;
            return;
        }
        int dequeue(){
            if(isempty()){
                cout<<"Queue Underflow !!"<<endl;
                return -1;
            }
            front = (front + 1) % size;
            int ele = arr[front];
            return ele;
        }
        void print(){
            if(isempty()) {
                cout<<"Queue is empty!"<<endl;
                return;
            }
            int index = front+1;
            while(index != back+1){
                cout<<arr[index]<<" ";
                index = (index + 1) %size;
            }
            cout<<endl;
        }
};

int main(){
    myQueue *que = new myQueue(30);
    for(int i =0 ;i<10;i++) que->enqueue(i+1);
    cout<<que->dequeue()<<endl;
    que->print();
    return 0;
    }
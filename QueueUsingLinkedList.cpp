#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){}
        Node(int val) : data(val),next(NULL) {};
};

class QueueUsingLinkedList{
    int size = 0;
    int cap = 0;
    Node *front = NULL;
    Node *tail = NULL;
    public:
        QueueUsingLinkedList(){}
        QueueUsingLinkedList(int capacity) : cap(capacity) {};
        bool isempty(){ return size==0; }
        bool isfull(){return size == cap;}
        void push(int val){
            if(size == cap) {cout<<"Queue Overflow !" ; return;}
            if(!front) {front = tail = new Node(val);}
            else{
                tail ->next = new Node(val);
                tail = tail->next;
            }
                size++;
        }
        int pop(){
            if(!front){
                cout<<"Queue Underflow!!";return -1;
            }
            int ele= front->data;
            Node * temp = front;
            front = front->next;
            delete temp;
            return ele;
        }
        void print(){
            Node *ptr = front;
            while(ptr){
                cout<<ptr->data<<" ";
                ptr =ptr->next;
            }
            return;
        }
};

int main(){
    QueueUsingLinkedList *myque = new QueueUsingLinkedList(30);
    for(int i =0 ;i<10;i++) myque->push(i+1);
    myque->print();
    return 0;
    }
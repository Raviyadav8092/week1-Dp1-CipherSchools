#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){}
        Node(int data) : data(data),next(NULL) {};
};

class StackUsingList{
    int size=0;
    int capacity=0;
    Node *head = NULL;
    public :
        StackUsingList(){}
        StackUsingList(int a){capacity = a;}
        bool empty(){return size == 0;}
        void push(int a){
            if(size == capacity) {
                cout<<"Stack Overflow!!";return;
            }
            Node *temp= new Node(a);
            temp->next = head;
            head= temp;
            size++;
            return;
        }

        int pop(){
            if(size == 0){
                cout<<"Stack Underflow !!";return -1;
            }
            Node *temp = head->next;
            int ele = head->data;
            head = head->next;
            size--;
            delete temp;
            return ele;
        }
        void print(){
            Node * ptr = head;
            while(ptr){
                cout<<ptr->data << " ";
                ptr = ptr->next;
            }
            cout<<endl;
        }

};

int main(){
    StackUsingList * mystack = new StackUsingList(30);
    for(int i =0 ;i<10;i++) mystack->push(i+1);
    mystack->print();
    return 0;
    }
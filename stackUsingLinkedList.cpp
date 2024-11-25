#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(){
        next=nullptr;
    }
};

class stack{
private:
    Node *top;
public:
    stack(){
        top=nullptr;
    }

    void push(int value){
        Node *newNode = new Node();
        newNode->data=value;
        newNode->next=top;
        top=newNode;
        cout<<value<<" pushed in to the stack"<<endl;
    }

    void pop(){
        if(top==nullptr){
            cout<<"Stack is empty "<<endl;
            return;
        }
        Node *temp=top;
        top=top->next;
        cout<<"Popped item: "<<temp->data<<endl;
        delete temp;
    }

    int peek(){
        if(top==nullptr){
            cout<<"Stack is empty "<<endl;
            return 0;
        }
        else{
            return top->data;
        }
    }

    ~stack(){
        while(top!=nullptr){
            pop();
        }
    }
};

int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
}
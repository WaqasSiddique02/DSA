#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node *next;
    Node *top;
public:
    Node(){
        data = 0;
        next = NULL;
        top=NULL;
    }

    void push(int value){
        Node *newNode= new Node();
        newNode->data = value;
        newNode->next=top;
        top=newNode;
    }

    void pop(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
        }
        else{
            Node *temp=top;
            top=temp->next;
            delete temp;
        }
    }

    void printStack(){
        Node *temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    Node st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.printStack();
}
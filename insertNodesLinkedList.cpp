#include <iostream>
using namespace std;

class Node{
private:
    int value;
    Node *next;

public:
    Node(){
        value=0;
        next = nullptr;
    }

    void addNodeAtBeg(Node **head,int newValue){
        Node *newNode= new Node();
        newNode->value=newValue;
        newNode->next=*head;
        *head=newNode;
    }

    void addNodeAtEnd(Node **head,int newValue){
        Node *newNode= new Node();
        newNode->value=newValue;
        newNode->next=nullptr;
        if(*head==NULL){
            *head=newNode;
            return;
        }

        Node *last= *head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=newNode;
    }

    void addNodeAfter(Node* prev,int newValue){
        if(prev==NULL){
            cout<<"Previous node cannot be null"<<endl;
            return ;
        }

        Node *newNode= new Node();
        newNode->value=newValue;
        newNode->next=prev->next;
        prev->next=newNode;
    }

    void printList(Node **head){
        Node *temp = *head;
        while(temp!=nullptr){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<"Null"<<endl;
    }

    Node* reverseList(Node **head){
    Node *prev = nullptr;
    Node *curr = *head;
    Node *nextPtr;

    while(curr != nullptr){
        nextPtr = curr->next;
        curr->next = prev;  
        prev = curr;     
        curr = nextPtr;        
    }

    *head = prev; 
    return *head;
}
};

int main(){
    Node *head=nullptr;
    Node *node= new Node();
    node->addNodeAtBeg(&head,10);
    node->addNodeAtBeg(&head,20);
    node->addNodeAtBeg(&head,30);
    node->addNodeAtEnd(&head,50);
    node->addNodeAfter(head,40);
    node->printList(&head);
    cout<<"Reversed linked list"<<endl;
    Node *newhead=node->reverseList(&head);
    node->printList(&newhead);
    
    return 0;
}
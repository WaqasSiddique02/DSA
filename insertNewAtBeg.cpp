#include <iostream>
using namespace std;

class Node{
    int num;
    Node *next;

public:
    Node* head;
    Node(){
        this->num = 0;
        this->next = nullptr;
        this->head=nullptr;
    }

    void insertNode(int num){
        Node *newNode=new Node();
        newNode->num = num;
        newNode->next =head ;
        head=newNode;
    }

    void insertAtBeginning(int newElement){
        Node *newNode=new Node();
        newNode->num = num;
        newNode->next =head ;
        head=newNode;
    }

    void displayNode(){
        Node *temp=head;
        while(temp!=nullptr){
            cout<<temp->num<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    Node *current=new Node();
    current->insertNode(8);
    current->insertNode(10);
    current->insertNode(2);
    current->insertNode(4);
    current->insertNode(7);
    cout<<"Displaying current Linked List"<<endl;
    current->displayNode();

    cout<<"After inserting at beginning"<<endl;
    current->insertAtBeginning(0);
    cout<<"Displaying Linked List"<<endl;
    current->displayNode();
    return 0;
}
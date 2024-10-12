#include <iostream>
using namespace std;

class Node
{
private:
    int num;
    Node *next;

public:
    Node *head;
    Node()
    {
        num = 0;
        next = nullptr;
        head = nullptr;
    }

    void addNode(int n)
    {
        Node *newNode = new Node();
        newNode->num = n;
        newNode->next = head;
        head = newNode;
    }

    void displayNode()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->num << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    void reversedList()
    {
     Node *curr=head;
     Node *prev =nullptr;
     Node *next;

     while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
     }
     head=prev;
    }
};

int main()
{
    Node *listObj = new Node();
    int noOfElements;
    cout << "Enter the elements you want to insert in linked list" << endl;
    cin >> noOfElements;

    cout << "Enter the elemets of the linked list" << endl;
    for (int i = 0; i < noOfElements; ++i)
    {
        int num;
        cin >> num;
        listObj->addNode(num);
    }

    listObj->displayNode();
    listObj->reversedList();
    cout << "Reversed List: " << endl;
    listObj->displayNode();
    return 0;
}
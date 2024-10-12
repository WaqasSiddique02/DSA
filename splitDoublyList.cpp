#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node() {
        this->data = "";
        this->next = nullptr;
        this->prev = nullptr;
    }

    void addNode(Node** head, string newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = *head;
        newNode->prev = nullptr;

        if (*head != nullptr) {
            (*head)->prev = newNode;
        }

        *head = newNode;
    }

    void displayLinkedList(Node* head) {
        Node* current = head;
        cout << "Traversal in forward direction" << endl;
        while (current != nullptr) {
            cout << " " << current->data << " ->";
            current = current->next;
        }
        cout << " NULL" << endl;
    }

    void splitList(Node* head, Node** head1, Node** head2) {
        if (head == nullptr || head->next == nullptr) {
            *head1 = head;
            *head2 = nullptr;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        *head1 = head;
        *head2 = slow->next;

        if (*head2 != nullptr) {
            (*head2)->prev = nullptr;
        }
        slow->next = nullptr;
    }
};

int main() {
    Node* newNode = new Node();
    Node* head = nullptr;

    newNode->addNode(&head, "Peach");
    newNode->addNode(&head, "Grapes");
    newNode->addNode(&head, "Orange");
    newNode->addNode(&head, "Banana");
    newNode->addNode(&head, "Apple");

    cout << "Original Doubly Linked List:" << endl;
    newNode->displayLinkedList(head);

    Node* head1 = nullptr;
    Node* head2 = nullptr;
    newNode->splitList(head, &head1, &head2);

    cout << "\nFirst Half:" << endl;
    newNode->displayLinkedList(head1);

    cout << "\nSecond Half:" << endl;
    newNode->displayLinkedList(head2);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string color;
    Node* next;
    Node* prev;

    Node(string color) {
        this->color = color;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    void insertNode(string color) {
        Node* newNode = new Node(color);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void displayForward(int n = 8) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        int count = 0;
        cout << "Forward traversal: ";
        do {
            cout << temp->color << " -> ";
            temp = temp->next;
            count++;
        } while (temp != head && count < n);
        cout << " (circular)" << endl;
    }

    void displayReverse(int n = 8) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head->prev;
        int count = 0;
        cout << "Reverse traversal: ";
        do {
            cout << temp->color << " -> ";
            temp = temp->prev;
            count++;
        } while (temp != head->prev && count < n);
        cout << " (circular)" << endl;
    }
};

int main() {
    DoublyCircularLinkedList list;
    list.insertNode("Red");
    list.insertNode("Green");
    list.insertNode("Blue");
    list.insertNode("Yellow");

    list.displayForward();
    list.displayReverse();

    return 0;
}



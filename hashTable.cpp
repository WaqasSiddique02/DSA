#include <iostream>
using namespace std;

class hashTable {
	static const int maxSize = 10;
	class Node {
	public:
		string key;
		int value;
		Node* next;

		Node(string k,int v) {
			key = k;
			value = v;
			next = nullptr;
		}
	};

	Node* table[maxSize];
	int hash(string key) {
		int hashValue = 0;
		for (char ch:key) {
			hashValue += ch;
		}
		return hashValue % maxSize;
	}

public:
	hashTable() {
		for (int i = 0; i < maxSize;i++) {
			table[i] = nullptr;
		}
	}

	void insert(string key,int value) {
		int index = hash(key);
		Node* newNode = new Node(key, value);
		newNode->next = table[index];
		table[index] = newNode;
	}

	bool search(string key, int& value) {
		int index = hash(key);
		Node* current = table[index];
		while (current) {
			if (current->key==key) {
				value = current->value;
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void remove(string key) {
		int index = hash(key);
		Node* current = table[index];
		Node* prev = nullptr;
		while (current) {
			if (current->key==key) {
				if (prev) {
					prev->next = current->next;
				}
				else {
					table[index] = current->next;
				}
				delete current;
				return;
			}
			prev = current;
			current = current->next;
		}
	}
};

int main() {
	hashTable ht;

	// Insert key-value pairs
	ht.insert("Alice", 25);
	ht.insert("Bob", 30);

	// Search for a key
	int value;
	if (ht.search("Alice", value)) {
		cout << "Alice's age: " << value << endl;
	}
	else {
		cout << "Alice not found" << endl;
	}

	// Remove a key
	ht.remove("Bob");

	// Try searching for Bob after removal
	if (ht.search("Bob", value)) {
		cout << "Bob's age: " << value << endl;
	}
	else {
		cout << "Bob not found" << endl;
	}

	return 0;
}

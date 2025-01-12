#include <iostream>
using namespace std;

class hashTable {
	const static int tableSize = 10;
	class node {
	public:
		string key;
		int value;
		node* next;

		node(string k,int v) {
			key = k;
			value = v;
			next = nullptr;
		}
	};

	node* table[tableSize];

	int hashFunction(string key) {
		int hashValue = 0;
		for (char ch:key) {
			hashValue += ch;
		}

		return hashValue % tableSize;
	}

public:
	hashTable() {
		for (int i = 0; i < tableSize;i++) {
			table[i] = nullptr;
		}
	}

	void insert(string key,int value) {
		int index = hashFunction(key);
		node* newNode = new node(key, value);

		newNode->next = table[index];
		table[index] = newNode;
	}

	bool search(string key,int value) {
		int index = hashFunction(key);
		node* current = table[index];
		while (current) {
			if (current->key==key) {
				value = current->value;
				return true;
			}
			current = current->next;
		}
	}

	void remove(string key) {
		int index = hashFunction(key);
		node* current = table[index];
		node* prev = nullptr;
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

}

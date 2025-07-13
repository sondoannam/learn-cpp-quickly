#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

// Insert at the front
void insertFront(Node*& head, int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = head;
    head = newNode;
}

// Print the list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Delete the whole list to free memory
void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;

    insertFront(head, 10);
    insertFront(head, 20);
    insertFront(head, 30);

    cout << "Linked List: ";
    printList(head);

    deleteList(head);
    cout << "After deletion: ";
    printList(head);

    return 0;
}

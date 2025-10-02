/*
Aditya Patra
Modularize Linked List
Lab 17

Purpose:
Rewrite the code such that it leverages functions to perform these linked list operations: 
adding a node to the front
adding a node to the tail
deleting a node
inserting a node
deleting the entire linked list.
*/
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addFront(Node * &, int);
void addTail(Node * &, int);
void deleteNode(Node * &);
void insertNode(Node * &);
void deleteList(Node * &);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    Node *newVal;
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        newVal = new Node;
        
        addFront(head, tmp_val);
    }
    newVal = new Node;
    addTail(head, 26);
    output(head);

    // deleting a node
    Node * current = head;
    int entry;
    Node *prev = head;
    deleteNode(head);
    output(head);

    insertNode(head);
    output(head);

    deleteList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node * &head, int tmp_val) {
    Node * newVal = new Node;
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = tmp_val;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = head;
        newVal->value = tmp_val;
        head = newVal;
    }
}

void addTail(Node * &head, int tmp_val) {
    Node * newVal = new Node;
    Node * current;
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = tmp_val;
    }
    else { // its a second or subsequent node; place at the head
        current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newVal;
        newVal->value = tmp_val;
        newVal->next = nullptr;
    }
}

void deleteNode(Node * &head) {
    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void insertNode(Node * &head) {
    // insert a node
    Node *current;
    Node *prev;
    current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
}

void deleteList(Node * &head) {
    // deleting the linked list
    Node *current;
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
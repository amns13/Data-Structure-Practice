#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next = nullptr;

    Node(int d) : data(d) {}
};

void push_front(Node **headptr, int data) {
    Node *newnode = new Node(data);
    newnode->next = *headptr;
    *headptr = newnode;
}

void pop_front(Node **headptr) {
    Node *tmp = *headptr;
    if (!tmp)
        return;
    *headptr = tmp->next;
    delete tmp;
}

void push_back(Node **headptr, int data) {
    Node *newnode = new Node(data);
    if (!(*headptr)) {
        *headptr = newnode;
        return;
    }
    
    Node *cur = *headptr;
    while(cur->next) {
        cur = cur->next;
    }
    cur->next = newnode;
}

void pop_back(Node **headptr) {
    if (!(*headptr))
        return;
    Node *prev = nullptr;
    Node *cur = *headptr;

    while (cur->next) {
        prev = cur;
        cur = cur->next;
    }
    if (!prev) {
        *headptr = nullptr;
    } else {
        prev->next = nullptr;
    }
    delete cur;
}

void print(Node *head) {
    if (!head) {
        cout << "Empty List!" << endl;
    }
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

void arr_to_list(Node **headptr, int A[], int n) {
    for (int i = n-1; i >= 0; --i)
        push_front(headptr, A[i]);
}

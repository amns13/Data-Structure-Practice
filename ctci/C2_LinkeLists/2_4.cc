#include <iostream>
#include "node.cc"

using namespace std;

void push_at_tail(Node **tailptr, int data) {
    Node *newnode = new Node(data);
    if (*tailptr) {
        (*tailptr)->next = newnode;
    }
    *tailptr = newnode;
}

Node* partition(Node *head, int x) {
    Node *phead = nullptr, *ptail = nullptr;
    Node *cur = head;

    while (cur) {
        if (cur->data < x) {
            push_front(&phead, cur->data);
            if (!ptail)
                ptail = phead;
        } else {
            push_at_tail(&ptail, cur->data);
            if (!phead)
                phead = ptail;
        }
        cur = cur->next;
    }

    return phead;
}

int main() {
    char c = 'n';
    do {
        int N;
        cin >> N;
        Node *head = nullptr;
        while (N--) {
            int val;
            cin >> val;
            push_front(&head, val);
        }
        print(head);
        int x;
        cin >> x;
        cout << "Calling partition" << endl;
        Node *p = partition(head, x);
        print(p);
        cout << "Continue (y/N)?" << endl;
        cin >> c;
    } while (c == 'y');
}

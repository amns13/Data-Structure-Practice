#include <iostream>
#include "node.cc"

using namespace std;

void delete_node_in_middle(Node *cur) {
    if (!cur || !(cur->next))
        return;
    Node *tmp = cur->next;
    cur->data = tmp->data;
    cur->next = tmp->next;

    delete tmp;
    tmp = nullptr;
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
        Node *cur = head;
        while (--x) {
            cur = cur->next;
        }
        delete_node_in_middle(cur);
        print(head);
        cout << "Continue (y/N)?" << endl;
        cin >> c;
    } while (c == 'y');
}

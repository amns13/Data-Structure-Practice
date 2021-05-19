#include <iostream>
#include "node.cc"

using namespace std;

int kth_to_last(Node *head, int k) {
    Node *fwd = head;
    for (int i = 0; i < k; ++i) {
        fwd = fwd->next;
    }

    Node *bwd = head;
    while (fwd) {
        fwd = fwd->next;
        bwd = bwd->next;
    }

    return bwd->data;
}

int main() {
    Node *head = nullptr;
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 10;
        push_front(&head, val);
    }
    print(head);

    for (int i = 1; i <= 10; ++i)
        cout << kth_to_last(head, i) << endl;

    return 0;
}

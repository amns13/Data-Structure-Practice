#include <iostream>
#include "node.cc"

Node *get_loop_node(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (!fast || !(fast->next))
        return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

int main() {
    Node *head = nullptr;
    int A[] = {1, 2, 3, 4, 5 ,6};
    arr_to_list(&head, A, 6);
    print(head);
    Node *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = head->next->next;
    Node *nptr = head;
    for (int i = 0; i < 15; ++i) {
        if (nptr) {
            cout << nptr->data << " -> ";
            nptr = nptr->next;
        }
    }
    cout << endl;
    Node *loop_node = get_loop_node(head);
    cout << loop_node->data << endl;

    return 0;
}

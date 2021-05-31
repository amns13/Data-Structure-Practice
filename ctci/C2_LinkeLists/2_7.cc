#include <iostream>
#include "node.cc"

Node *get_intersection(Node *head1, Node *head2) {
    if (!(head1 && head2))
        return nullptr;
    Node *tail1 = head1, *tail2 = head2;
    int len1 = 1, len2 = 1;

    while(tail1->next) {
        tail1 = tail1->next;
        ++len1;
    }
    while(tail2->next) {
        tail2 = tail2->next;
        ++len2;
    }
    if (tail1 != tail2)
        return nullptr;

    Node *cur1 = head1, *cur2 = head2;
    while (len1 < len2) {
        cur2 = cur2->next;
        len1++;
    }
    while (len2 < len1) {
        cur1 = cur1->next;
        len2++;
    }

    while (cur1->next) {
        if (cur1 == cur2)
            return cur1;
        else {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }

    return cur1;
}


int main() {
    Node *head1 = nullptr, *head2 = nullptr;
    int A[] = {1, 2, 3, 4,5 ,6};
    arr_to_list(&head1, A, 6);
    int B[] = {2};
    arr_to_list(&head2, B, 1);
    head2->next = head1->next->next->next;
    print(head1);
    print(head2);
    Node *intersection = get_intersection(head1, head2);
    if (intersection)
        cout << intersection->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}

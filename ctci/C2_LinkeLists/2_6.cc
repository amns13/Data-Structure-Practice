#include <iostream>
#include "node.cc"

using namespace std;

Node *get_mid_node(Node *head) {
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *is_palindrome_recur(Node *cur, Node *head) {
    if (!cur)
        return head;

    Node *comp_node = is_palindrome_recur(cur->next, head);
    if (comp_node && comp_node->data == cur->data)
        return comp_node->next;
    return nullptr;
}

bool is_palindrome(Node *head) {
    if (!head || !(head->next))
        return true;
    Node *mid = get_mid_node(head);
    return is_palindrome_recur(mid->next, head) != nullptr;
}

int main() {
    int c;
    do {
        Node *num = nullptr;
        Node *num2 = nullptr;
        srand(time(nullptr));
        int size = rand()%10;
        for (int i = 0; i < size; ++i) {
            int val = rand() % 10;
            push_front(&num, val);
            push_front(&num2, val);
            push_back(&num2, val);
        }
        print(num);
        print(num2);
        if (is_palindrome(num))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (is_palindrome(num2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << "=====================" << endl;
    
    } while (cin >> c);

    return 0;
}

#include <iostream>
#include "node.cc"

Node *sum_lists(Node *num1, Node *num2) {
    Node *result = nullptr, *curr_digit = nullptr;
    int carry = 0;

    while (num1 || num2) {
        int d1 = num1 ? num1->data : 0;
        int d2 = num2 ? num2->data : 0;

        Node *new_node = new Node ((d1 + d2 + carry) % 10);
        carry = (d1 + d2 + carry) / 10;

        if (result) {
            curr_digit->next = new_node;
            curr_digit = curr_digit->next;
        } else {
            result = new_node;
            curr_digit = result;
        }

        if (num1)
            num1 = num1->next;
        if (num2)
            num2 = num2->next;
    }
    if (carry > 0) {
        Node *new_node = new Node(carry);
        curr_digit->next = new_node;
    }

    return result;
}

Node *sum_node(Node *n1, Node *n2, int &carry) {
    if (!n1)
        return nullptr;
    Node *next_dig_node = sum_node(n1->next, n2->next, carry);
    int cur_sum = n1->data + n2->data + carry;
    Node *new_node = new Node(cur_sum % 10);
    new_node->next = next_dig_node;
    carry = cur_sum / 10;
    return new_node;
}

Node *sum_lists_forward(Node *n1, Node *n2) {
    int len1 = 0, len2 = 0;
    Node *cur1 = n1, *cur2 = n2;

    while(cur1 || cur2) {
        if (cur1) {
            len1++;
            cur1 = cur1->next;
        }
        if (cur2) {
            len2++;
            cur2 = cur2->next;
        }
    }

    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; ++i)
            push_front(&n1, 0);
    }
    if (len2 < len1) {
        for (int i = 0; i < len1 - len2; ++i)
            push_front(&n2, 0);
    }

    int carry = 0;
    Node *res = sum_node(n1, n2, carry);
    if (carry > 0) {
        push_front(&res, carry);
    }

    return res;
}

int main() {
    int c;
    do {
        Node *num1 = nullptr;
        Node *num2 = nullptr;
        srand(time(nullptr));
        int size1 = rand()%10;
        for (int i = 0; i < size1; ++i) {
            int val = rand() % 10;
            push_front(&num1, val);
        }
        int size2 = rand()%10;
        for (int i = 0; i < size2; ++i) {
            int val = rand() % 10;
            push_front(&num2, val);
        }

        print(num1);
        print(num2);
        Node *result = sum_lists_forward(num1, num2);
        print(result);
        cout << "=====================" << endl;
    
    } while (cin >> c);

    return 0;
}

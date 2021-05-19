#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include "node.cc"

using namespace std;

// Using a hashmap
// Time: O(N), Space: O(N)
void remove_dups(Node *head) {
    unordered_set<int> seen;
    Node *cur = head;
    Node *prev = nullptr;

    while (cur) {
        int val = cur->data;
        if (seen.find(val) == seen.end()) {
            seen.insert(val);
            prev = cur;
            cur = cur->next;
        } else {
            Node *tmp = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete tmp;
            tmp = nullptr;
        }
    }
}

void remove_dups_without_extra_space(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *checker = cur;
        while (checker->next) {
            if (checker->next->data == cur->data) {
                Node *tmp = checker->next;
                checker->next = tmp->next;
                delete tmp;
                tmp = nullptr;
            } else {
                checker = checker->next;
            }
        }
        cur = cur->next;
    }
}

int main() {
    int c;
    cout << "Testing remove_dups" << endl;
    do {
        Node *head = nullptr;
        srand(time(nullptr));
        for (int i = 0; i < 15; ++i) {
            int val = rand() % 10;
            push_front(&head, val);
        }

        print(head);
        remove_dups(head);
        print(head);
    
    } while (cin >> c);
    cin.ignore();

    cout << "Testing remove_dups_without_extra_space" << endl;
    do {
        Node *head = nullptr;
        srand(time(nullptr));
        for (int i = 0; i < 15; ++i) {
            int val = rand() % 10;
            push_front(&head, val);
        }

        print(head);
        remove_dups_without_extra_space(head);
        print(head);
    
    } while (cin >> c);
}

#include <iostream>
#include <string>
#include <unordered_set>
#include <cassert>

using namespace std;

// Using a hash set.
// No constraint on the allowed characters
// Time: O(N), Space: O(N)
bool has_unique_chars_set(const string& str) {
    unordered_set<char> s;

    for (char c: str) {
        if (s.find(c) != s.end()) {
            return false;
        } else {
            s.insert(c);
        }
    }

    return true;
}

// Using an array of booleans. Each char will have one slot.
// Mark those that are found as True. Use when number of
// possible characters is known.
// Time: O(N), Space: O(1)
bool has_unique_chars_charset_array(const string& str) {
    if (str.length() > 128)
        return false;

    bool char_set[128] = {false};
    
    for (int i = 0; i < str.length(); ++i) {
        int val = str[i];
        if (char_set[val])
            return false;
        char_set[val] = true;
    }

    return true;
}

// Using a bit vector.This assumes that the allowed characters
// are the 26 small letters in the alohabet. In this case we can
// use a single int to create the bit vector.
// Time: O(N), Space: O(1)
bool has_unique_chars_bit_vector(const string& str) {
    int checker = 0;
    for (int i = 0; i < str.length(); ++i) {
        int val = str[i];
        if ((checker & (1 << val)) != 0)
            return false;
        checker |= (1 << val);
    }

    return true;
}

int main() {
    assert(has_unique_chars_set("abc"));

    return 0;
}

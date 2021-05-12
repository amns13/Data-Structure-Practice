#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

// Using a hashmap. At most 1 character can appear
// Odd number of times. All other characters will have 
// even frequency.
// Time: O(N), Space: O(N)
bool is_permutation_of_palindrome_hashmap(const string& str) {
    unordered_map<char, int> mp;
    for (char c : str) {
        if (!isspace(c)) {
            c = tolower(c);
            if (mp.find(c) == mp.end()) {
                mp.insert(pair<char, int>(c, 1));
            } else {
                ++mp[c];
            }
        }
    }

    int odd_cnt = 0;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->second % 2 != 0) {
            if (odd_cnt == 1)
                return false;
            odd_cnt++;
        }
    }

    return true;
}

// Using a bitvector. Assuming that the allowed characters are only english alphabets.
// Use Bit tweedling techniques.
// Time: O(N), Space: O(N)
int toggle_bit(int bitvector, int x) {
    return bitvector ^= (1 << x);
}

bool is_exactly_one_bit_set(int n) {
    return (n & (n - 1)) == 0;
}

int create_bitvector(const string& str) {
    int bitvector = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (!isspace(str[i])) {
            int x = tolower(str[i]) - 'a';
            bitvector = toggle_bit(bitvector, x);
        }
    }
    return bitvector;
}

bool is_permutation_of_palindrome_bitvector(const string& str) {
    int bitvector = create_bitvector(str);
    return bitvector == 0 || is_exactly_one_bit_set(bitvector);
}


int main() {
    assert(is_permutation_of_palindrome_hashmap("Tact Coa"));
    assert(is_permutation_of_palindrome_hashmap("Taoct Coa"));
    assert(!is_permutation_of_palindrome_hashmap("Tacit Coa"));
    assert(!is_permutation_of_palindrome_hashmap("Ract Coa"));
    assert(is_permutation_of_palindrome_hashmap(""));
    assert(is_permutation_of_palindrome_hashmap(" "));
    assert(is_permutation_of_palindrome_hashmap("a"));
    assert(is_permutation_of_palindrome_hashmap("aa"));
    assert(!is_permutation_of_palindrome_hashmap("ia"));

    assert(is_permutation_of_palindrome_bitvector("Tact Coa"));
    assert(is_permutation_of_palindrome_bitvector("Taoct Coa"));
    assert(!is_permutation_of_palindrome_bitvector("Tacit Coa"));
    assert(!is_permutation_of_palindrome_bitvector("Ract Coa"));
    assert(is_permutation_of_palindrome_bitvector(""));
    assert(is_permutation_of_palindrome_bitvector(" "));
    assert(is_permutation_of_palindrome_bitvector("a"));
    assert(is_permutation_of_palindrome_bitvector("aa"));
    assert(!is_permutation_of_palindrome_bitvector("ia"));

    return 0;
}

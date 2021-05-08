#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

bool is_permutation_map(const string& s1, const string& s2) {
    if (s1.length() != s2.length())
        return false;

    unordered_map<int, int> m;
    for (int i = 0; i < s1.length(); ++i) {
        int val = s1[i];
        if (m.find(val) == m.end())
            m.insert(pair<int, int>(val, 1));
        else
            ++m[val];
    }

    for (int i = 0; i < s2.length(); ++i) {
        int val = s2[i];
        if (m.find(val) == m.end())
            return false;
        else {
            --m[val];
            if (m[val] < 0)
                return false;
        }
    }

    /** Checking for letters present in s1 and not present in s2
     *  not required seperately because we have already checked
     *  that s1 and s2 both have same length. So, if all chars in
     *  s2 are present in s1 then reverse is also true.
     */

    return true;
}

bool is_permutation_charset(const string& s1, const string& s2) {
    int m = s1.length(), n = s2.length();
    if (m != n) return false;

    int cnt[128] = {0};
    for (int i = 0; i < n; ++i)
        ++cnt[s1[i]];

    for (int i = 0; i < n; ++i) {
        int val = s2[i];
        if (--cnt[val] < 0)
            return false;
    }

    return true;
}

bool is_permutation_sort(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1.compare(s2) == 0;

}

int main() {
    assert(is_permutation_map("", ""));
    assert(is_permutation_map("abcdefsa", "abcdefas"));
    assert(!is_permutation_map("abcads", "abcdss"));
    assert(!is_permutation_map("aa", "ab"));

    assert(is_permutation_charset("", ""));
    assert(is_permutation_charset("abcdefsa", "abcdefas"));
    assert(!is_permutation_charset("abcads", "abcdss"));
    assert(!is_permutation_charset("aa", "ab"));
    assert(!is_permutation_charset("potatoman", "poootanam"));

    assert(is_permutation_sort("", ""));
    assert(is_permutation_sort("abcdefsa", "abcdefas"));
    assert(!is_permutation_sort("abcads", "abcdss"));
    assert(!is_permutation_sort("aa", "ab"));
    assert(!is_permutation_sort("potatoman", "poootanam"));

    return 0;
}

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool one_away(const string& str1, const string& str2) {
    int m = str1.length(), n = str2.length();
    int diff = m >= n? m-n : n-m;

    if (diff >= 2)
        return false;

    int i = 0, j = 0;

    while (i < m && j < n) {
        if (str1[i] != str2[j]) {
            if (diff == -1) {
                return false;
            } else if (diff == 1) {
                if (m > n)
                    ++i;
                else
                    ++j;
                diff = -1;
            } else {
                diff = -1;
            }
        }
        ++i; ++j;
    }

    return true;
}


int main() {
    assert(one_away("pale", "ple"));
    assert(one_away("pales", "pale"));
    assert(one_away("pale", "bale"));
    assert(!one_away("pale", "bake"));

    return 0;
}

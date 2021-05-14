#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string compress_string(const string& str) {
    if(str.length() == 0) return str;

    string res = "";
    char cur = str[0];
    int cnt = 1;

    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == cur) {
            ++cnt;
        } else {
            res.push_back(cur);
            res.append(to_string(cnt));
            cur = str[i];
            cnt = 1;
        }
    }

    res.push_back(cur);
    res.append(to_string(cnt));

    if (res.length() < str.length())
        return res;
    else
        return str;
}


int main() {
    assert(compress_string("aabbbccccdaaa") == "a2b3c4d1a3");
    assert(compress_string("a") == "a");
    assert(compress_string("aaaaab") == "a5b1");

    return 0;
}

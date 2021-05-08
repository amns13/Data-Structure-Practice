#include <iostream>
#include <string>

using namespace std;

void urlify(string &str, int size) {
    int space_cnt = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] == ' ')
            ++space_cnt;
    }

    int j = 2 * space_cnt + size - 1;

    for (int i = size-1; i >= 0; --i) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

int main() {
    /*
    string str;
    int n;
    getline(cin, str);
    urlify(str);
    */
    string str = "Mr John Smith    ";
    urlify(str, 13);
    cout << str << endl;

    return 0;
}

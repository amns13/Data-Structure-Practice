// Program to revere a number
// O(n)

#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        int res = 0;
        while (n) {
            res = res * 10 + (n % 10);
            n /= 10;
        }
        cout << res << endl;
    }

    return 0;
}

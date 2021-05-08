#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    long long int K, s;
    int d0, d1;

    for (int i = 0; i < T; ++i) {
        cin >> K >> d0 >> d1;
        s = d0 + d1;

        while (K > 2) {
            s += (s % 10);
            --K;
        }

        if (s % 3 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

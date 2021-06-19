#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long int D, d, P, Q;
        cin >> D >> d >> P >> Q;
        long long int n = D / d;
        long long int r = D % d;
        // long long int S = (d * n / 2) * ((2 * P) + (n - 1) * Q);
        // Above ex[resion gives error when d and D are the same.
        // in that case n/2 becomes 0 and the answer also becomes 0.
        // Wgich is wrong. Hence moving /2 to the end.
        long long int S = ((d * n) * ((2 * P) + (n - 1) * Q)) / 2;
        long long int extra = (P + n * Q) * r;
        long long int res = S + extra;
        cout << res << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;
        int res = (Xa / xa) + (Xb / xb);
        cout << res << endl;
    }

    return 0;
}

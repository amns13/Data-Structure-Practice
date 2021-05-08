#include <iostream>
using namespace std;

int main() {
    int amt;
    double bal;

    cin >> amt >> bal;

    if (amt % 5 == 0 && amt+0.50 <= bal) {
        cout << bal - amt - 0.50 <<endl;
    } else {
        cout << bal << endl;
    }

    return 0;
}

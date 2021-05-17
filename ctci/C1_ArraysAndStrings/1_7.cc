#include <iostream>

using namespace std;

void rotate_matrix_by_90(int **M, int n) {
    for (int i =0; i < n/2; ++i) {
        for (int j=i; j < n-1-i; ++j) {
            int tmp = M[i][j];
            M[i][j] = M[n-1-j][i];
            M[n-1-j][i] = M[n-1-i][n-1-j];
            M[n-1-i][n-1-j] = M[j][n-1-i];
            M[j][n-1-i] = tmp;
        }
    }
}

int main() {
    while (true) {
        int n; cin >> n;
        int **R = new int*[n];
        for (int i =0; i < n; ++i) {
            R[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                cin >> R[i][j];
            }
        }

        cout << "Before Rotation" << endl;
        cout << "=================" << endl;
        for (int i =0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << R[i][j] << " ";
            cout << endl;
        }

        rotate_matrix_by_90(R, n);
        cout << "Before Rotation" << endl;
        cout << "=================" << endl;

        for (int i =0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << R[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

void print(int **M, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void zero_matrix(int **M, int m, int n) {
    bool first_row_has_zero = false;
    bool first_col_has_zero = false;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (M[i][j] == 0) {
                if (i == 0)
                    first_row_has_zero = true;
                if (j == 0)
                    first_col_has_zero = true;
                M[0][j] = 0;
                M[i][0] = 0;
            }
        }
    }

    for (int j = 1; j < n; ++j) {
        if (M[0][j] == 0) {
            for (int k = 1; k < m; ++k) {
                M[k][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; ++i) {
        if (M[i][0] == 0) {
            for (int k = 1; k < n; ++k) {
                M[i][k] = 0;
            }
        }
    }

    if (first_row_has_zero) {
        for (int j = 0; j < n; ++j)
            M[0][j] = 0;
    }
    if (first_col_has_zero) {
        for (int i = 0; i < m; ++i)
            M[i][0] = 0;
    }
}

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;
        int **R = new int*[m];
        for (int i =0; i < m; ++i) {
            R[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                cin >> R[i][j];
            }
        }
        cout<<"================="<<endl;
        print(R, m, n);
        zero_matrix(R, m, n);
        cout<<"================="<<endl;
        print(R, m, n);
        cout<<"================="<<endl;
    }

    return 0;
}

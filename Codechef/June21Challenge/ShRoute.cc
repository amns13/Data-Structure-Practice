#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    int N, M, res;
    int A[100000], B[100000], fwd[100000], bwd[100000];

    while (T--) {
        scanf("%d", &N);
        scanf("%d", &M);

        for (int i = 0; i < N; ++i)
            scanf("%d", &A[i]);
        for (int j = 0; j < M; ++j)
            scanf("%d", &B[j]);

        if (A[0] == 1)
            fwd[0] = 0;
        else
            fwd[0] = -1;

        if (A[N-1] == 2)
            bwd[N-1] = 0;
        else
            bwd[N-1] = -1;

        for (int k = 1; k < N; ++k) {
            if (A[k] == 1)
                fwd[k] = 0;
            else if (fwd[k-1] == -1)
                fwd[k] = -1;
            else
                fwd[k] = fwd[k-1] + 1;
        }

        for (int k = N-2; k >= 0; --k) {
            if (A[k] == 2)
                bwd[k] = 0;
            else if (bwd[k+1] == -1)
                bwd[k] = -1;
            else
                bwd[k] = bwd[k+1] + 1;
        }
        /*
        printf("Debugging started\n");
        for (int i = 0; i < N; ++i) {
            printf("%d,", fwd[i]);
        }
        printf("\n");
        for (int i = 0; i < N; ++i) {
            printf("%d,", bwd[i]);
        }
        printf("Debugging stopped\n");
        */

        for (int k = 0; k < M; ++k) {
            int dest = B[k] - 1;
            if (fwd[dest] == -1 && bwd[dest] == -1)
                printf("%d ", -1);
            else if (fwd[dest] == -1)
                printf("%d ", bwd[dest]);
            else if (bwd[dest] == -1)
                printf("%d ", fwd[dest]);
            else {
                res = fwd[dest] < bwd[dest] ? fwd[dest] : bwd[dest];
                printf("%d ", res);
            }
        }
        printf("\n");
    }

    return 0;
}

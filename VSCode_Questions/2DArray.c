/* ============================================================================
 * SECTION 5: 2D ARRAYS
 * ============================================================================ */


/* ----------------------------------------------------------------------------
 * Question 1: Row and column sums
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) {
        return 0;
    }

    long long matrix[100][100];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        long long rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += matrix[i][j];
        }
        printf("%lld%s", rowSum, (i == r - 1) ? "" : " ");
    }
    printf("\n");

    for (int j = 0; j < c; j++) {
        long long colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += matrix[i][j];
        }
        printf("%lld%s", colSum, (j == c - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 2: Check matrix symmetry
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    long long matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    int symmetric = 1;
    for (int i = 0; i < n && symmetric; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    printf("%s\n", symmetric ? "YES" : "NO");
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 3: Find a saddle point
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) {
        return 0;
    }

    long long matrix[100][100];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            long long val = matrix[i][j];
            int isRowMin = 1;
            int isColMax = 1;

            for (int col = 0; col < c; col++) {
                if (matrix[i][col] < val) {
                    isRowMin = 0;
                    break;
                }
            }

            if (isRowMin) {
                for (int row = 0; row < r; row++) {
                    if (matrix[row][j] > val) {
                        isColMax = 0;
                        break;
                    }
                }
            }

            if (isRowMin && isColMax) {
                printf("%d %d %lld\n", i, j, val);
                return 0;
            }
        }
    }

    printf("None\n");
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 4: Count local peaks
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) {
        return 0;
    }

    long long matrix[100][100];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    int peaks = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            long long val = matrix[i][j];
            int isPeak = 1;

            if (i > 0 && matrix[i - 1][j] >= val) isPeak = 0;
            if (i < r - 1 && matrix[i + 1][j] >= val) isPeak = 0;
            if (j > 0 && matrix[i][j - 1] >= val) isPeak = 0;
            if (j < c - 1 && matrix[i][j + 1] >= val) isPeak = 0;

            if (isPeak) {
                peaks++;
            }
        }
    }

    printf("%d\n", peaks);
    return 0;
}
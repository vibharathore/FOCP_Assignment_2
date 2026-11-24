/* ============================================================================
 * SECTION 2: NESTED LOOPS
 * ============================================================================ */


/* ----------------------------------------------------------------------------
 * Question 1: Count pairs with a target sum
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int n;
    long long target;
    if (scanf("%d %lld", &n, &target) != 2) {
        return 0;
    }

    long long arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 2: Count relatively prime values
 * ---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b) {
    a = llabs(a);
    b = llabs(b);
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long n, m;
    if (scanf("%lld %lld", &n, &m) == 2) {
        long long count = 0;
        for (long long x = 1; x <= m; x++) {
            if (gcd(x, n) == 1) {
                count++;
            }
        }
        printf("%lld\n", count);
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 3: Pythagorean triples up to N
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    int found = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            for (int c = b + 1; c <= N; c++) {
                if ((long long)a * a + (long long)b * b == (long long)c * c) {
                    printf("%d %d %d\n", a, b, c);
                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("None\n");
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 4: Pairs with equal digit sums
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int digitSum(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    long long arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (digitSum(arr[i]) == digitSum(arr[j])) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 5: Closest pair difference
 * ---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) {
        return 0;
    }

    long long arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long minDiff = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = llabs(arr[i] - arr[j]);
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
    }

    printf("%lld\n", minDiff);
    return 0;
}
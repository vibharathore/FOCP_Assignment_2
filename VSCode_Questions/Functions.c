/* ============================================================================
 * SECTION 1: FUNCTIONS
 * ============================================================================ */


/* ----------------------------------------------------------------------------
 * Question 1: Find maximum of three integers
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int maxOfThree(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        printf("%d\n", maxOfThree(a, b, c));
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 2: Count multiples in a range
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

long long countMultiples(long long n, long long k) {
    if (n <= 0 || k <= 0) {
        return 0;
    }
    return n / k;
}

int main() {
    long long n, k;
    if (scanf("%lld %lld", &n, &k) == 2) {
        printf("%lld\n", countMultiples(n, k));
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 3: Rectangle area function
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

long long rectangleArea(long long length, long long width) {
    return length * width;
}

int main() {
    long long length, width;
    if (scanf("%lld %lld", &length, &width) == 2) {
        printf("%lld\n", rectangleArea(length, width));
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 4: Perfect square without sqrt
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int isPerfectSquare(long long n) {
    if (n < 0) {
        return 0;
    }
    for (long long i = 0; i * i <= n; i++) {
        if (i * i == n) {
            return 1;
        }
    }
    return 0;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%d\n", isPerfectSquare(n));
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 5: GCD using Euclid's algorithm
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
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", gcd(a, b));
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 6: Convert seconds
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    long long totalSeconds;
    if (scanf("%lld", &totalSeconds) == 1) {
        long long hours = totalSeconds / 3600;
        long long remaining = totalSeconds % 3600;
        long long minutes = remaining / 60;
        long long seconds = remaining % 60;
        printf("%lld %lld %lld\n", hours, minutes, seconds);
    }
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 7: Evaluate a piecewise function
 * ---------------------------------------------------------------------------- */
#include <stdio.h>

long long f(long long x) {
    if (x < 0) {
        return x * x + 2 * x + 1;
    } else if (x < 10) {
        return 3 * x + 2;
    } else {
        return 5 * x - 7;
    }
}

int main() {
    long long x;
    if (scanf("%lld", &x) == 1) {
        printf("%lld\n", f(x));
    }
    return 0;
}
/* ============================================================================
 * SECTION 4: STRINGS AND CHARACTER ARRAYS
 * ============================================================================ */


/* ----------------------------------------------------------------------------
 * Question 1: Count vowels, consonants, digits, spaces
 * ---------------------------------------------------------------------------- */
#include <stdio.h>
#include <ctype.h>

int main() {
    char line[1005];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)line[i];
        if (isalpha(ch)) {
            char lower = (char)tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(ch)) {
            digits++;
        } else if (ch == ' ') {
            spaces++;
        }
    }

    printf("%d %d %d %d\n", vowels, consonants, digits, spaces);
    return 0;
}


/* ----------------------------------------------------------------------------
 * Question 2: Run-length encode
 * ---------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];
    if (scanf("%1004s", str) != 1) {
        return 0;
    }

    int len = (int)strlen(str);
    if (len == 0) {
        return 0;
    }

    int count = 1;
    for (int i = 1; i <= len; i++) {
        if (i < len && str[i] == str[i - 1]) {
            count++;
        } else {
            printf("%c%d", str[i - 1], count);
            count = 1;
        }
    }
    printf("\n");
    return 0;
}
#include <stdio.h>

int main() {
    printf("A | B | A<->B | (A&&B)||(!A&&!B)\n");
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            int A_leftrightarrow_B = (A && B) || (!A && !B);
            int and_or_not = (A && B) || (!A && !B);
            printf("%d | %d | %d     | %d\n", A, B, A_leftrightarrow_B, and_or_not);
        }
    }
    return 0;
}


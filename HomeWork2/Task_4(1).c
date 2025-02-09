#include <stdio.h>

int main() {
    printf("A | B | A->B | !A||B\n");
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            int A_to_B = !A || B;
            int not_A_or_B = !A || B;
            printf("%d | %d | %d    | %d\n", A, B, A_to_B, not_A_or_B);
        }
    }
    return 0;
}

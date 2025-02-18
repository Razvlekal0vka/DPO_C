#include <stdio.h>

void print_squares(int a, int b) {
    for (int i = a; i <= b; i++) {
        printf("%d ", i * i);
    }
}

int main() {
    int a, b;
    //printf("Введите два целых числа a и b (a ≤ b): ");
    scanf("%d %d", &a, &b);

    if (a <= b) {
        print_squares(a, b);
    } else {
        printf("Ошибка: a должно быть меньше или равно b.\n");
    }

    return 0;
}

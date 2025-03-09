#include <stdio.h>

// Рекурсивная функция для перевода числа в двоичную систему счисления
void printBinary(int n) {
    if (n == 0) {
        return;
    }
    printBinary(n / 2);
    printf("%d", n % 2);
}

int main() {
    int N;
    //printf("Введите не отрицательное целое число: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Ошибка: введите не отрицательное целое число.\n");
        return 1;
    }

    if (N == 0) {
        printf("0\n");
        return 0;
    }

    printBinary(N);
    printf("\n");

    return 0;
}

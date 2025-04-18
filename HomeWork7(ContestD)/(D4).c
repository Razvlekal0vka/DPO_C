#include <stdio.h>

// Рекурсивная функция для вывода цифр числа в прямом порядке
void printDigits(int n) {
    if (n == 0) {
        return;
    }
    printDigits(n / 10);
    printf("%d ", n % 10);
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

    printDigits(N);
    printf("\n");

    return 0;
}

#include <stdio.h>

// Рекурсивная функция для печати чисел от 1 до N
void printNumbers(int n) {
    if (n < 1) {
        return;
    }
    printNumbers(n - 1);
    printf("%d ", n);
}

int main() {
    int N;
    //printf("Введите натуральное число: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("Ошибка: введите натуральное число больше 0.\n");
        return 1;
    }

    printNumbers(N);
    printf("\n");

    return 0;
}

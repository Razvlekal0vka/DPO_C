#include <stdio.h>

// Рекурсивная функция для вычисления суммы чисел от 1 до N
int sumNumbers(int n) {
    if (n < 1) {
        return 0;
    }
    return n + sumNumbers(n - 1);
}

int main() {
    int N;
    //printf("Введите натуральное число: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("Ошибка: введите натуральное число больше 0.\n");
        return 1;
    }

    int result = sumNumbers(N);
    //printf("Сумма чисел от 1 до %d: %d\n", N, result);
    printf("%d ", result);

    return 0;
}

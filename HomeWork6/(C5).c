#include <stdio.h>

// Функция для вычисления суммы всех чисел от 1 до N
unsigned long long sum_of_numbers(int N) {
    unsigned long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int N;

    // Ввод числа N от пользователя
    scanf("%d", &N);

    // Проверка на корректность ввода
    if (N <= 0) {
        printf("Ошибка: введите положительное число.\n");
        return 1;
    }

    unsigned long long result = sum_of_numbers(N); // Результат работы

    printf("%llu\n", result);

    return 0;
}

#include <stdio.h>

// Функция для вычисления n в степени p
long long power(int n, int p) {
    long long result = 1;
    long long base = n;

    while (p > 0) {
        if (p % 2 == 1) {
            result *= base;
        }
        base *= base;
        p /= 2;
    }

    return result;
}

int main() {
    // Объявляем переменные для хранения входных данных
    int n, p;

    // Считываем входные данные
    scanf("%d %d", &n, &p);

    // Вычисляем n в степени p
    long long result = power(n, p);

    // Выводим результат
    printf("%lld\n", result);

    return 0;
}

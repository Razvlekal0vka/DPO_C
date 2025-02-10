#include <stdio.h>

// Функция для нахождения максимального значения из трех чисел
int max_of_three(int a, int b, int c) {
    int max_ab = (a > b) ? a : b;
    return (max_ab > c) ? max_ab : c;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Используем функцию для нахождения максимума из трех чисел
    int max_value = max_of_three(a, b, c);

    printf("%d\n", max_value);

    return 0;
}
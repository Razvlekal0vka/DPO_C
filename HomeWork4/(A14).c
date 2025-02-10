#include <stdio.h>

// Функция для нахождения максимального значения из трех чисел
int max_of_three(int a, int b, int c) {
    int max_ab = (a > b) ? a : b;
    return (max_ab > c) ? max_ab : c;
}

int main() {
    int number;
    scanf("%d", &number);

    // Проверка, что число трехзначное
    if (number < 100 || number > 999) {
        printf("Ошибка: введите трехзначное число.\n");
        return 1;
    }

    // Находим цифры числа
    int hundreds = number / 100;
    int tens = (number / 10) % 10;
    int units = number % 10;

    // Используем функцию для нахождения максимума из трех чисел
    int max_value = max_of_three(hundreds, tens, units);

    printf("%d\n", max_value);

    return 0;
}
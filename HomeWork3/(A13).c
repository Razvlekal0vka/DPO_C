#include <stdio.h>

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

    int p = hundreds * tens * units;

    // Выводим результат
    printf("%d\n", p);

    return 0;
}

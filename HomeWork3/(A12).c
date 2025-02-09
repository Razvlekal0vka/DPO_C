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

    // Считаем сумму цифр
    int sum = hundreds + tens + units;

    // Выводим результат
    printf("%d\n", sum);

    return 0;
}

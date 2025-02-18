#include <stdio.h>

int main() {
    int number, sum = 0, digit;

    // Ввод числа
    //printf("Введите целое число: ");
    scanf("%d", &number);

    // Проверка на отрицательное число
    if (number < 0) {
        number = -number; // Работаем только с положительными числами
    }

    // Вычисление суммы цифр
    while (number > 0) {
        digit = number % 10; // Получаем последнюю цифру
        sum += digit;        // Добавляем цифру к сумме
        number /= 10;        // Удаляем последнюю цифру
    }

    // Вывод результата
    //printf("Сумма цифр: %d\n", sum);
    printf("%d ", sum);

    return 0;
}

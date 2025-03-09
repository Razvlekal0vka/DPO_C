#include <stdio.h>
#include <stdlib.h>

int main() {
    // Объявляем переменную для хранения входного числа
    int inputNumber;

    // Считываем входное число
    scanf("%d", &inputNumber);

    // Вычисляем модуль числа
    int result = abs(inputNumber);

    // Выводим результат
    printf("%d\n", result);

    return 0;
}

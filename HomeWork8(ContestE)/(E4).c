#include <stdio.h>

int main() {
    int numbers[10]; // Объявление массива из 10 элементов
    int max1, max2;  // Переменные для хранения двух максимальных значений

    //printf("Введите 10 целых чисел через пробел: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]); // Считывание числа и сохранение его в массив
    }

    // Инициализируем первые два максимальных значения первыми двумя элементами массива
    if (numbers[0] > numbers[1]) {
        max1 = numbers[0];
        max2 = numbers[1];
    } else {
        max1 = numbers[1];
        max2 = numbers[0];
    }

    // Находим два максимальных значения в массиве
    for (int i = 2; i < 10; i++) {
        if (numbers[i] > max1) {
            max2 = max1;
            max1 = numbers[i];
        } else if (numbers[i] > max2) {
            max2 = numbers[i];
        }
    }

    // Вывод суммы двух максимальных значений
    printf("%d\n", max1 + max2);

    return 0;
}

#include <stdio.h>

int main() {
    int numbers[10]; // Объявление массива из 10 элементов
    int max, min;    // Переменные для хранения максимального и минимального значений
    int maxIndex, minIndex; // Переменные для хранения индексов максимального и минимального значений

    //printf("Введите 10 целых чисел через пробел: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]); // Считывание числа и сохранение его в массив
    }

    // Инициализируем максимальное и минимальное значение первым элементом массива
    max = numbers[0];
    min = numbers[0];
    maxIndex = 0;
    minIndex = 0;

    // Находим максимальное и минимальное значение в массиве
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            maxIndex = i;
        }
        if (numbers[i] < min) {
            min = numbers[i];
            minIndex = i;
        }
    }

    // Вывод результата
    printf("%d %d %d %d\n", maxIndex + 1, max, minIndex + 1, min);

    return 0;
}

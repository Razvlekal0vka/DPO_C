#include <stdio.h>

int main() {
    int numbers[5];
    int sum = 0;
    double average;

    //printf("Введите 5 целых не нулевых чисел через пробел: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (double)sum / 5;
    //printf("Среднее арифметическое: %.3f\n", average);
    printf("%.3f\n", average);
    return 0;
}

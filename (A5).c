#include <stdio.h>

int main() {
    int a, b, c;

    // Ввод трех целых чисел
    scanf("%d %d %d", &a, &b, &c);

    // Вычисление среднего арифметического
    double average = (a + b + c) / 3.0;

    // Вывод результата в формате %.2f
    printf("%.2f\n", average);

    return 0;
}

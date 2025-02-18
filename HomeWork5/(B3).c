#include <stdio.h>

int main() {
    int a, b;
    int sum = 0;

    // Ввод двух целых чисел a и b
    //printf("Введите два целых числа a и b (a ≤ b): ");
    scanf("%d %d", &a, &b);

    // Проверка, что a ≤ b
    if (a > b) {
        printf("Ошибка: a должно быть меньше или равно b.\n");
        return 1;
    }

    // Вычисление суммы квадратов чисел от a до b
    for (int i = a; i <= b; i++) {
        sum += i * i;
    }

    // Вывод результата
    //printf("Сумма квадратов от %d до %d: %d\n", a, b, sum);
    printf("%d ", sum);


    return 0;
}

#include <stdio.h>

int main() {
    int a, b, c;

    // Ввод трех целых чисел
    scanf("%d %d %d", &a, &b, &c);

    // Вычисление суммы
    int sum = a + b + c;

    // Вывод результата в требуемом формате
    printf("%d+%d+%d=%d\n", a, b, c, sum);

    return 0;
}

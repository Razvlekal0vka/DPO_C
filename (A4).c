#include <stdio.h>

int main() {
    int a, b, c;

    // Ввод трех целых чисел
    scanf("%d %d %d", &a, &b, &c);

    int sum = a + b + c;
    int prod = a * b * c;

    // Вывод результата в требуемом формате
    printf("%d+%d+%d=%d\n", a, b, c, sum);
    printf("%d*%d*%d=%d\n", a, b, c, prod);

    return 0;
}

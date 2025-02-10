#include <stdio.h>

int main() {
    int a, b, c;

    // Ввод данных
    scanf("%d %d %d", &a, &b, &c);

    // Проверка существования треугольника
    int exists = (a + b > c) && (a + c > b) && (b + c > a);

    printf(exists ? "YES\n" : "NO\n");

    return 0;
}

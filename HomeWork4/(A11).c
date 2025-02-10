#include <stdio.h>

// Функция для нахождения максимального минимума
int min_of_five(int a, int b, int c, int d, int e) {
    int max_ab = (a < b) ? a : b;
    int max_de = (d < e) ? d : e;
    int max_ab_de = (max_ab < max_de) ? max_ab : max_de;
    return (max_ab_de < c) ? max_ab_de : c;
}

// Функция для нахождения максимального значения
int max_of_five(int a, int b, int c, int d, int e) {
    int max_ab = (a > b) ? a : b;
    int max_de = (d > e) ? d : e;
    int max_ab_de = (max_ab > max_de) ? max_ab : max_de;
    return (max_ab_de > c) ? max_ab_de : c;
}

int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int min_value = min_of_five(a, b, c, d, e);
    int max_value = max_of_five(a, b, c, d, e);

    printf("%d\n", max_value + min_value);

    return 0;
}
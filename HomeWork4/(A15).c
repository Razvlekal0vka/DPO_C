#include <stdio.h>

// Функция для вычисления уравнения прямой по двум точкам
void calculateLineEquation(double x1, double y1, double x2, double y2, double *k, double *b) {
    if (x1 == x2) {
        // Вертикальная линия
        *k = 0;
        *b = x1;
    } else {
        // Обычная линия
        *k = (y2 - y1) / (x2 - x1);
        *b = y1 - (*k) * x1;
    }
}

int main() {
    // Входные данные
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    // Вычисление уравнения прямой
    double k, b;
    calculateLineEquation(x1, y1, x2, y2, &k, &b);


    printf("%.2f %.2f\n", k, b);

    return 0;
}

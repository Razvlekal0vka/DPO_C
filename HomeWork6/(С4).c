#include <stdio.h>
#include <limits.h> // Для использования INT_MIN

// Функция для вычисления значения функции f(x)
int f(int x) {
    if (x < -2) {
        return 4;
    } else if (x >= -2 && x < 2) {
        return x * x;
    } else {
        return x * x + 4 * x + 5;
    }
}

int main() {
    // Объявляем переменные для хранения входных данных и результата
    int x;
    int max_f = INT_MIN; // Переменная для хранения максимального значения функции

    // Считываем входные данные до тех пор, пока не встретим 0
    while (1) {
        scanf("%d", &x);
        if (x == 0) {
            break;
        }

        // Вычисляем значение функции
        int current_f = f(x);

        // Обновляем максимальное значение функции
        if (current_f > max_f) {
            max_f = current_f;
        }
    }

    // Выводим максимальное значение функции
    printf("%d\n", max_f);

    return 0;
}

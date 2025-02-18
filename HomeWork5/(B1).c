#include <stdio.h>

int main() {
    int n;

    // Ввод числа от пользователя
    //printf("Введите натуральное число (не более 100): ");
    scanf("%d", &n);

    // Проверка, что число не превосходит 100
    if (n > 100 || n <= 0) {
        printf("Ошибка: введите число от 1 до 100.\n");
        return 1;
    }

    // Вывод квадратов и кубов чисел от 1 до n
    for (int i = 1; i <= n; i++) {
        int square = i * i;
        int cube = i * i * i;
        printf("%d %d %d\n", i, square, cube);
    }

    return 0;
}

#include <stdio.h>

int main() {
    int number;

    // Ввод целого числа
    //printf("Введите целое число: ");
    scanf("%d", &number);

    // Проверка, содержит ли число ровно три цифры
    if (number >= 100 && number <= 999) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

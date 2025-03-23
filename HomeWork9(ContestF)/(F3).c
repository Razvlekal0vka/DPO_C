#include <stdio.h>
#include <string.h>

void count_digits(const char* number) {
    int digit_count[10] = {0}; // Массив для подсчета количества каждой цифры

    // Подсчитываем количество каждой цифры
    for (int i = 0; i < strlen(number); i++) {
        int digit = number[i] - '0';
        digit_count[digit]++;
    }

    // Выводим цифры и их количество в порядке возрастания
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > 0) {
            printf("%d %d\n", i, digit_count[i]);
        }
    }
}

int main() {
    char number[1001]; // Массив для хранения числа до 1000 цифр
    //printf("Введите число: ");
    scanf("%1000s", number); // Считываем число

    count_digits(number); // Вызываем функцию для подсчета и вывода цифр

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_digit(char s[]) {
    int digit_count[10] = {0}; // Массив для подсчета количества каждой цифры

    // Проходим по строке и подсчитываем количество каждой цифры
    for (int i = 0; i < strlen(s); i++) {
        if (isdigit(s[i])) {
            int digit = s[i] - '0';
            digit_count[digit]++;
        }
    }

    // Выводим цифры и их количество в порядке возрастания
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > 0) {
            printf("%d %d\n", i, digit_count[i]);
        }
    }
}

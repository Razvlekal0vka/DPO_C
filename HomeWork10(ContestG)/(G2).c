#include <stdio.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int N;
    if (fscanf(inputFile, "%d", &N) != 1 || N <= 0 || N > 26 || N % 2 != 0) {
        fprintf(stderr, "Invalid input value for N\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Формируем строку
    char result[27] = {0}; // Массив для хранения результата
    int digit = 2;

    for (int i = 0; i < N; i += 2) {
        result[i] = 'A' + (i / 2); // Заглавные буквы на нечетных позициях
        result[i + 1] = '0' + digit; // Четные цифры на четных позициях
        digit += 2;
        if (digit > 8) {
            digit = 2; // Сброс цифры, если превышает 8
        }
    }

    // Записываем результат в файл
    fprintf(outputFile, "%s", result);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

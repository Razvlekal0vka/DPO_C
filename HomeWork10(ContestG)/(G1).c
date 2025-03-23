#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char line[101]; // Массив для хранения строки до 100 символов
    if (fgets(line, sizeof(line), inputFile) != NULL) {
        // Удаляем незначащие переносы строк
        line[strcspn(line, "\n")] = 0;

        // Записываем строку три раза и количество символов
        fprintf(outputFile, "%s, %s, %s %lu", line, line, line, strlen(line));
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

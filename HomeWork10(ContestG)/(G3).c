#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char line[1001]; // Массив для хранения строки до 1000 символов
    if (fgets(line, sizeof(line), inputFile) != NULL) {
        // Удаляем незначащие переносы строк
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        if (len == 0) {
            // Если строка пустая, записываем пустой результат
            fclose(inputFile);
            fclose(outputFile);
            return 0;
        }

        char lastChar = line[len - 1];
        int first = 1; // Флаг для отслеживания первого совпадения

        // Проходим по строке и ищем совпадения с последним символом, кроме последнего
        for (size_t i = 0; i < len - 1; i++) {
            if (line[i] == lastChar) {
                if (!first) {
                    fprintf(outputFile, " ");
                }
                fprintf(outputFile, "%zu", i); // Номера символов с 1
                first = 0;
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

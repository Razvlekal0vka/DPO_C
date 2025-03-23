#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1001

void replaceCharacters(const char *input, FILE *outputFile) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'a') {
            fputc('b', outputFile);
        } else if (input[i] == 'A') {
            fputc('B', outputFile);
        } else if (input[i] == 'b') {
            fputc('a', outputFile);
        } else if (input[i] == 'B') {
            fputc('A', outputFile);
        } else {
            fputc(input[i], outputFile);
        }
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Ошибка открытия файла");
        return EXIT_FAILURE;
    }

    char line[MAX_LENGTH];

    if (fgets(line, sizeof(line), inputFile) == NULL) {
        fprintf(stderr, "Ошибка чтения данных из файла\n");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    replaceCharacters(line, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 101

void findUniqueChars(const char *word1, const char *word2, FILE *outputFile) {
    int count1[26] = {0};
    int count2[26] = {0};

    // Подсчет символов в первом слове
    for (int i = 0; word1[i] != '\0'; i++) {
        count1[word1[i] - 'a']++;
    }

    // Подсчет символов во втором слове
    for (int i = 0; word2[i] != '\0'; i++) {
        count2[word2[i] - 'a']++;
    }

    // Поиск символов, которые встречаются в обоих словах только один раз
    for (int i = 0; i < 26; i++) {
        if (count1[i] == 1 && count2[i] == 1) {
            fprintf(outputFile, "%c ", 'a' + i);
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

    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];

    if (fscanf(inputFile, "%s %s", word1, word2) != 2) {
        fprintf(stderr, "Ошибка чтения данных из файла\n");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    findUniqueChars(word1, word2, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}

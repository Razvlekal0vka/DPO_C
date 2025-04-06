#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"

void printHelp() {
    printf("Usage: temp_app [options]\n");
    printf("Options:\n");
    printf("  -h            Display this help message\n");
    printf("  -f <file>    Input CSV file for processing\n");
    printf("  -m <month>   Display statistics for the specified month\n");
    printf("Interactive commands:\n");
    printf("  add <year> <month> <day> <hour> <minute> <temperature>  Add a temperature record\n");
    printf("  delete <index>                                           Delete a temperature record by index\n");
    printf("  sort                                                    Sort temperature records\n");
    printf("  print                                                   Print all temperature records\n");
    printf("  stats month <month>                                     Print monthly statistics\n");
    printf("  stats year                                             Print yearly statistics\n");
    printf("  help                                                   Display this help message\n");
    printf("  exit                                                   Exit the program\n");
}

void loadFromFile(const char *filename, TemperatureData temps[], int *size) {
    // Здесь можно добавить код для чтения данных из CSV файла
    // В данном примере просто выводим сообщение
    printf("Loading data from file: %s\n", filename);
}

int main(int argc, char *argv[]) {
    TemperatureData temps[100];
    int size = 0;
    int month = 0;
    char command[256];

    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printHelp();
            return 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            loadFromFile(argv[i + 1], temps, &size);
            i++;
        } else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            month = atoi(argv[i + 1]);
            i++;
        } else {
            printf("Unknown option: %s\n", argv[i]);
            printHelp();
            return 1;
        }
    }

    if (month > 0) {
        float avgTemp;
        int minTemp, maxTemp;
        calculateMonthlyStatistics(temps, size, month, &avgTemp, &minTemp, &maxTemp);
        printMonthlyStatistics(month, avgTemp, minTemp, maxTemp);
        return 0;
    }

    printf("Welcome to the Temperature Data Manager!\n");

    while (1) {
        printf("\nEnter command: ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = 0; // Удаление символа новой строки

        if (strcmp(command, "help") == 0) {
            printHelp();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else if (strncmp(command, "add ", 4) == 0) {
            int year, month, day, hour, minute, temperature;
            if (sscanf(command + 4, "%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &temperature) == 6) {
                addRecord(temps, &size, (TemperatureData){year, month, day, hour, minute, temperature});
                printf("Record added.\n");
            } else {
                printf("Invalid add command.\n");
            }
        } else if (strncmp(command, "delete ", 7) == 0) {
            int index;
            if (sscanf(command + 7, "%d", &index) == 1) {
                deleteRecord(temps, &size, index);
                printf("Record deleted.\n");
            } else {
                printf("Invalid delete command.\n");
            }
        } else if (strcmp(command, "sort") == 0) {
            sortRecords(temps, size);
            printf("Records sorted.\n");
        } else if (strcmp(command, "print") == 0) {
            printRecords(temps, size);
        } else if (strncmp(command, "stats month ", 12) == 0) {
            int month;
            if (sscanf(command + 12, "%d", &month) == 1) {
                float avgTemp;
                int minTemp, maxTemp;
                calculateMonthlyStatistics(temps, size, month, &avgTemp, &minTemp, &maxTemp);
                printMonthlyStatistics(month, avgTemp, minTemp, maxTemp);
            } else {
                printf("Invalid stats month command.\n");
            }
        } else if (strcmp(command, "stats year") == 0) {
            float avgTemp;
            int minTemp, maxTemp;
            calculateYearlyStatistics(temps, size, &avgTemp, &minTemp, &maxTemp);
            printYearlyStatistics(avgTemp, minTemp, maxTemp);
        } else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }

    printf("Exiting the program.\n");
    return 0;
}

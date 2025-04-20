#include "temp_api.h"
#include <string.h>
#include <dirent.h>  // Для работы с директориями

// Функция добавления записи
void addRecord(TemperatureRecord** records, int* size, TemperatureRecord record) {
    *records = realloc(*records, (*size + 1) * sizeof(TemperatureRecord));
    (*records)[*size] = record;
    (*size)++;
}

// Функция удаления записи
void deleteRecord(TemperatureRecord** records, int* size, int index) {
    if (index < 0 || index >= *size) return;
    for (int i = index; i < *size - 1; i++) {
        (*records)[i] = (*records)[i + 1];
    }
    *records = realloc(*records, (*size - 1) * sizeof(TemperatureRecord));
    (*size)--;
}

// Функция сортировки записей
void sortRecords(TemperatureRecord* records, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (records[j].year > records[j + 1].year ||
                (records[j].year == records[j + 1].year && records[j].month > records[j + 1].month) ||
                (records[j].year == records[j + 1].year && records[j].month == records[j + 1].month && records[j].day > records[j + 1].day) ||
                (records[j].year == records[j + 1].year && records[j].month == records[j + 1].month && records[j].day == records[j + 1].day && records[j].hour > records[j + 1].hour) ||
                (records[j].year == records[j + 1].year && records[j].month == records[j + 1].month && records[j].day == records[j + 1].day && records[j].hour == records[j + 1].hour && records[j].minute > records[j + 1].minute)) {
                TemperatureRecord temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

// Функция печати записей
void printRecords(TemperatureRecord* records, int size) {
    for (int i = 0; i < size; i++) {
        printf("%04d-%02d-%02d %02d:%02d %d\n", records[i].year, records[i].month, records[i].day, records[i].hour, records[i].minute, records[i].temperature);
    }
}

// Функция вывода статистики по месяцу
void printMonthlyStats(TemperatureRecord* records, int size, int month) {
    int count = 0;
    int sum = 0;
    int minTemp = 99;
    int maxTemp = -99;

    for (int i = 0; i < size; i++) {
        if (records[i].month == month) {
            sum += records[i].temperature;
            count++;
            if (records[i].temperature < minTemp) minTemp = records[i].temperature;
            if (records[i].temperature > maxTemp) maxTemp = records[i].temperature;
        }
    }

    if (count > 0) {
        printf("Monthly stats for month %02d:\n", month);
        printf("Average temperature: %d\n", sum / count);
        printf("Minimum temperature: %d\n", minTemp);
        printf("Maximum temperature: %d\n", maxTemp);
    } else {
        printf("No data for month %02d\n", month);
    }
}

// Функция вывода статистики за год
void printYearlyStats(TemperatureRecord* records, int size) {
    int sum = 0;
    int minTemp = 99;
    int maxTemp = -99;

    for (int i = 0; i < size; i++) {
        sum += records[i].temperature;
        if (records[i].temperature < minTemp) minTemp = records[i].temperature;
        if (records[i].temperature > maxTemp) maxTemp = records[i].temperature;
    }

    if (size > 0) {
        printf("Yearly stats:\n");
        printf("Average temperature: %d\n", sum / size);
        printf("Minimum temperature: %d\n", minTemp);
        printf("Maximum temperature: %d\n", maxTemp);
    } else {
        printf("No data available\n");
    }
}

// Функция загрузки данных из CSV файла
void loadFromCSV(TemperatureRecord** records, int* size, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[100];
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        TemperatureRecord record;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &record.year, &record.month, &record.day, &record.hour, &record.minute, &record.temperature) == 6) {
            addRecord(records, size, record);
        } else {
            printf("Error in line %d: Invalid format\n", lineNumber);
        }
    }

    fclose(file);
}

// Функция сохранения данных в CSV файл
void saveToCSV(TemperatureRecord* records, int size, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d;%d;%d;%d;%d;%d\n", records[i].year, records[i].month, records[i].day, records[i].hour, records[i].minute, records[i].temperature);
    }

    fclose(file);
    printf("Data saved to %s\n", filename);
}

// Функция вывода справки
void printHelp() {
    printf("Available commands:\n");
    printf("  load <filename>     Load data from a CSV file\n");
    printf("  save <filename>     Save data to a CSV file\n");
    printf("  add <yyyy> <mm> <dd> <hh> <mm> <temp>  Add a new record\n");
    printf("  delete <index>      Delete a record by index\n");
    printf("  print               Print all records\n");
    printf("  stats year          Print yearly statistics\n");
    printf("  stats month <month> Print monthly statistics for the specified month\n");
    printf("  stats all           Print statistics for all data\n");
    printf("  list                List all files in the current directory\n");
    printf("  help                Print this help message\n");
    printf("  exit                Exit the program\n");
}

// Функция для отображения всех файлов в текущей директории
void listFiles() {
    DIR* dir = opendir(".");
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent* entry;
    printf("Files in the current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Проверяем, что это файл
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

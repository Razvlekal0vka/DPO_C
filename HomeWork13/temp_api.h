#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <stdlib.h>

// Структура для хранения данных о температуре
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureRecord;

// Прототипы функций
void addRecord(TemperatureRecord** records, int* size, TemperatureRecord record);
void deleteRecord(TemperatureRecord** records, int* size, int index);
void sortRecords(TemperatureRecord* records, int size);
void printRecords(TemperatureRecord* records, int size);
void printMonthlyStats(TemperatureRecord* records, int size, int month);
void printYearlyStats(TemperatureRecord* records, int size);
void loadFromCSV(TemperatureRecord** records, int* size, const char* filename);
void saveToCSV(TemperatureRecord* records, int size, const char* filename);
void printHelp();
void listFiles();

#endif // TEMP_API_H

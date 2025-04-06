#ifndef TEMP_API_H
#define TEMP_API_H

// Определение структуры для хранения данных о температуре
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureData;

// Прототипы функций
void calculateMonthlyStatistics(TemperatureData temps[], int size, int month, float *avgTemp, int *minTemp, int *maxTemp);
void calculateYearlyStatistics(TemperatureData temps[], int size, float *avgTemp, int *minTemp, int *maxTemp);

#endif // TEMP_API_H

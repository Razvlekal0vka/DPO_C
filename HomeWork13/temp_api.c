#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>

void calculateMonthlyStatistics(TemperatureData temps[], int size, int month, float *avgTemp, int *minTemp, int *maxTemp) {
    int count = 0;
    int sum = 0;
    *minTemp = 99;
    *maxTemp = -99;

    for (int i = 0; i < size; i++) {
        if (temps[i].month == month) {
            sum += temps[i].temperature;
            count++;
            if (temps[i].temperature < *minTemp) {
                *minTemp = temps[i].temperature;
            }
            if (temps[i].temperature > *maxTemp) {
                *maxTemp = temps[i].temperature;
            }
        }
    }

    if (count > 0) {
        *avgTemp = (float)sum / count;
    }
}

void calculateYearlyStatistics(TemperatureData temps[], int size, float *avgTemp, int *minTemp, int *maxTemp) {
    int sum = 0;
    *minTemp = 99;
    *maxTemp = -99;

    for (int i = 0; i < size; i++) {
        sum += temps[i].temperature;
        if (temps[i].temperature < *minTemp) {
            *minTemp = temps[i].temperature;
        }
        if (temps[i].temperature > *maxTemp) {
            *maxTemp = temps[i].temperature;
        }
    }

    if (size > 0) {
        *avgTemp = (float)sum / size;
    }
}

void printMonthlyStatistics(int month, float avgTemp, int minTemp, int maxTemp) {
    printf("Month %d Statistics:\n", month);
    printf("Average Temperature: %.2f\n", avgTemp);
    printf("Minimum Temperature: %d\n", minTemp);
    printf("Maximum Temperature: %d\n", maxTemp);
}

void printYearlyStatistics(float avgTemp, int minTemp, int maxTemp) {
    printf("Yearly Statistics:\n");
    printf("Average Temperature: %.2f\n", avgTemp);
    printf("Minimum Temperature: %d\n", minTemp);
    printf("Maximum Temperature: %d\n", maxTemp);
}

void addRecord(TemperatureData **temps, int *size, TemperatureData newRecord) {
    *temps = realloc(*temps, (*size + 1) * sizeof(TemperatureData));
    if (*temps == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    (*temps)[*size] = newRecord;
    (*size)++;
}

void deleteRecord(TemperatureData **temps, int *size, int index) {
    if (index >= 0 && index < *size) {
        for (int i = index; i < *size - 1; i++) {
            (*temps)[i] = (*temps)[i + 1];
        }
        (*temps) = realloc(*temps, (*size - 1) * sizeof(TemperatureData));
        if (*temps == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        (*size)--;
    }
}

void sortRecords(TemperatureData temps[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (temps[j].year > temps[j + 1].year ||
                (temps[j].year == temps[j + 1].year && temps[j].month > temps[j + 1].month) ||
                (temps[j].year == temps[j + 1].year && temps[j].month == temps[j + 1].month && temps[j].day > temps[j + 1].day) ||
                (temps[j].year == temps[j + 1].year && temps[j].month == temps[j + 1].month && temps[j].day == temps[j + 1].day && temps[j].hour > temps[j + 1].hour) ||
                (temps[j].year == temps[j + 1].year && temps[j].month == temps[j + 1].month && temps[j].day == temps[j + 1].day && temps[j].hour == temps[j + 1].hour && temps[j].minute > temps[j + 1].minute)) {
                TemperatureData temp = temps[j];
                temps[j] = temps[j + 1];
                temps[j + 1] = temp;
            }
        }
    }
}

void printRecords(TemperatureData temps[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d-%d-%d %d:%d: Temperature = %d\n",
               temps[i].year, temps[i].month, temps[i].day, temps[i].hour, temps[i].minute, temps[i].temperature);
    }
}

void freeRecords(TemperatureData **temps) {
    free(*temps);
    *temps = NULL;
}

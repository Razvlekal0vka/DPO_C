#include "temp_api.h"

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

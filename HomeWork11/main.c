#include <stdio.h>
#include "temp_api.h"

int main() {
    // Пример использования функций
    TemperatureData temps[] = {
        {2023, 1, 1, 12, 0, 20},
        {2023, 1, 2, 12, 0, 22},
        {2023, 2, 1, 12, 0, 18},
    };

    int size = sizeof(temps) / sizeof(temps[0]);
    float avgTemp;
    int minTemp, maxTemp;

    calculateMonthlyStatistics(temps, size, 1, &avgTemp, &minTemp, &maxTemp);
    printf("January Statistics: Avg = %.2f, Min = %d, Max = %d\n", avgTemp, minTemp, maxTemp);

    calculateYearlyStatistics(temps, size, &avgTemp, &minTemp, &maxTemp);
    printf("Yearly Statistics: Avg = %.2f, Min = %d, Max = %d\n", avgTemp, minTemp, maxTemp);

    return 0;
}

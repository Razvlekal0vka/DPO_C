#include "temp_api.h"
#include <string.h>
#include <ctype.h>  // Добавляем заголовочный файл для isdigit

int main() {
    TemperatureRecord* records = NULL;
    int size = 0;
    char command[50];
    char filename[100];
    int month;
    int index;
    TemperatureRecord newRecord;

    printHelp();

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "load") == 0) {
            scanf("%s", filename);
            loadFromCSV(&records, &size, filename);
            printf("Data loaded from %s\n", filename);
        } else if (strcmp(command, "save") == 0) {
            scanf("%s", filename);
            saveToCSV(records, size, filename);
        } else if (strcmp(command, "add") == 0) {
            scanf("%d %d %d %d %d %d", &newRecord.year, &newRecord.month, &newRecord.day, &newRecord.hour, &newRecord.minute, &newRecord.temperature);
            addRecord(&records, &size, newRecord);
            printf("Record added\n");
        } else if (strcmp(command, "delete") == 0) {
            scanf("%d", &index);
            deleteRecord(&records, &size, index);
            printf("Record deleted\n");
        } else if (strcmp(command, "print") == 0) {
            printRecords(records, size);
        } else if (strcmp(command, "stats") == 0) {
            char statsType[10];
            scanf("%s", statsType);
            if (strcmp(statsType, "year") == 0) {
                printYearlyStats(records, size);
            } else if (strcmp(statsType, "month") == 0) {
                scanf("%d", &month);
                printMonthlyStats(records, size, month);
            } else if (strcmp(statsType, "all") == 0) {
                printYearlyStats(records, size);
            } else {
                printf("Unknown stats type: %s\n", statsType);
            }
        } else if (strcmp(command, "list") == 0) {
            listFiles();
        } else if (strcmp(command, "help") == 0) {
            printHelp();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    // Освобождение памяти
    free(records);

    return 0;
}

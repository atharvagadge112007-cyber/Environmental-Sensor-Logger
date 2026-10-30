
#include <stdio.h>
#include "file_handler.h"
#include "validation.h"

// Check whether an ID already exists
static int idExists(const SensorReading readings[], int count, int id) {

    for (int i = 0; i < count; i++) {
        if (readings[i].id == id) {
            return 1;
        }
    }

    return 0;
}

// Check whether a reading contains valid data
static int isValidReading(const SensorReading *reading) {

    if (reading == NULL || reading->id <= 0) {
        return 0;
    }

    return validateTemperature(reading->temperature) &&
           validateHumidity(reading->humidity) &&
           validateAQI(reading->aqi) &&
           validateLightIntensity(reading->lightIntensity);
}

// Save sensor readings to a CSV file
int saveReadingsToFile(const char *filename,
                       const SensorReading readings[],
                       int count) {

    if (filename == NULL || readings == NULL ||
        count < 0 || count > MAX_READINGS) {
        return 0;
    }

    // Validate all records before saving
    for (int i = 0; i < count; i++) {

        if (!isValidReading(&readings[i]) ||
            idExists(readings, i, readings[i].id)) {
            return 0;
        }
    }

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Could not open file for saving.\n");
        return 0;
    }

    fprintf(file, "id,temperature,humidity,aqi,lightIntensity\n");

    for (int i = 0; i < count; i++) {

        if (fprintf(file, "%d,%.2f,%.2f,%d,%.2f\n",
                    readings[i].id,
                    readings[i].temperature,
                    readings[i].humidity,
                    readings[i].aqi,
                    readings[i].lightIntensity) < 0) {

            fclose(file);
            return 0;
        }
    }

    if (fclose(file) != 0) {
        return 0;
    }

    printf("Readings saved successfully.\n");

    return 1;
}

// Load sensor readings from a CSV file
int loadReadingsFromFile(const char *filename,
                         SensorReading readings[],
                         int maxReadings) {

    if (filename == NULL || readings == NULL ||
        maxReadings <= 0 || maxReadings > MAX_READINGS) {
        return -1;
    }

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file for loading.\n");
        return -1;
    }

    char line[256];

    // Skip the CSV header
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return -1;
    }

    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {

        SensorReading reading;
        int consumed = 0;

        int fields = sscanf(line, " %d,%f,%f,%d,%f %n",
                            &reading.id,
                            &reading.temperature,
                            &reading.humidity,
                            &reading.aqi,
                            &reading.lightIntensity,
                            &consumed);

        // Check whether all five fields were read
        if (fields != 5 || line[consumed] != '\0') {
            fclose(file);
            return -1;
        }

        // Check array capacity
        if (count >= maxReadings) {
            fclose(file);
            return -1;
        }

        // Validate the reading
        if (!isValidReading(&reading)) {
            fclose(file);
            return -1;
        }

        // Reject duplicate IDs
        if (idExists(readings, count, reading.id)) {
            fclose(file);
            return -1;
        }

        readings[count] = reading;
        count++;
    }

    if (ferror(file)) {
        fclose(file);
        return -1;
    }

    fclose(file);

    printf("Readings loaded successfully.\n");

    return count;
}

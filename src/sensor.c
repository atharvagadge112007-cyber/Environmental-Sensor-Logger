
#include <stdio.h>
#include "sensor.h"
#include "validation.h"

// Add a new sensor reading
int addReading(SensorReading readings[], int *count,
               SensorReading newReading) {

    // Check whether the array and count are valid
    if (readings == NULL || count == NULL) {
        return 0;
    }

    // Check array capacity and count
    if (*count < 0 || *count >= MAX_READINGS) {
        return 0;
    }

    // Sensor ID must be positive
    if (newReading.id <= 0) {
        return 0;
    }

    // Check for duplicate ID
    if (searchReadingById(readings, *count, newReading.id) != -1) {
        return 0;
    }

    // Validate sensor values
    if (!validateTemperature(newReading.temperature) ||
        !validateHumidity(newReading.humidity) ||
        !validateAQI(newReading.aqi) ||
        !validateLightIntensity(newReading.lightIntensity)) {
        return 0;
    }

    // Store the reading
    readings[*count] = newReading;

    // Increase reading count
    (*count)++;

    return 1;
}

// Display all sensor readings
void displayReadings(const SensorReading readings[], int count) {

    if (readings == NULL || count <= 0) {
        printf("\nNo sensor readings available.\n");
        return;
    }

    printf("\n========== SENSOR READINGS ==========\n");

    printf("%-8s %-15s %-12s %-8s %-15s\n",
           "ID", "Temperature", "Humidity", "AQI", "Light");

    for (int i = 0; i < count; i++) {

        printf("%-8d %-15.2f %-12.2f %-8d %-15.2f\n",
               readings[i].id,
               readings[i].temperature,
               readings[i].humidity,
               readings[i].aqi,
               readings[i].lightIntensity);
    }

    printf("=====================================\n");
}

// Search for a reading using its ID
int searchReadingById(const SensorReading readings[],
                      int count, int id) {

    if (readings == NULL || count <= 0) {
        return -1;
    }

    for (int i = 0; i < count; i++) {

        if (readings[i].id == id) {
            return i;
        }
    }

    return -1;
}

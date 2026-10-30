
#include <stdio.h>
#include "report.h"

// Calculate average temperature
float calculateAverageTemperature(
    const SensorReading readings[], int count) {

    if (readings == NULL || count <= 0) {
        return 0.0f;
    }

    float total = 0.0f;

    for (int i = 0; i < count; i++) {
        total += readings[i].temperature;
    }

    return total / count;
}

// Calculate average humidity
float calculateAverageHumidity(
    const SensorReading readings[], int count) {

    if (readings == NULL || count <= 0) {
        return 0.0f;
    }

    float total = 0.0f;

    for (int i = 0; i < count; i++) {
        total += readings[i].humidity;
    }

    return total / count;
}

// Calculate average AQI
float calculateAverageAQI(
    const SensorReading readings[], int count) {

    if (readings == NULL || count <= 0) {
        return 0.0f;
    }

    float total = 0.0f;

    for (int i = 0; i < count; i++) {
        total += readings[i].aqi;
    }

    return total / count;
}

// Classify AQI
AQICategory getAQICategory(int aqi) {

    if (aqi <= 50) {
        return GOOD;
    }
    else if (aqi <= 100) {
        return MODERATE;
    }
    else if (aqi <= 150) {
        return UNHEALTHY_FOR_SENSITIVE_GROUPS;
    }
    else if (aqi <= 200) {
        return VERY_UNHEALTHY;
    }
    else {
        return HAZARDOUS;
    }
}

// Return the name of an AQI category
const char *getAQICategoryName(AQICategory category) {

    switch (category) {

        case GOOD:
            return "GOOD";

        case MODERATE:
            return "MODERATE";

        case UNHEALTHY_FOR_SENSITIVE_GROUPS:
            return "UNHEALTHY FOR SENSITIVE GROUPS";

        case VERY_UNHEALTHY:
            return "VERY UNHEALTHY";

        case HAZARDOUS:
            return "HAZARDOUS";

        default:
            return "UNKNOWN";
    }
}

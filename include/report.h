
#ifndef REPORT_H
#define REPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensor.h"

// Calculates average temperature.
float calculateAverageTemperature(
    const SensorReading readings[],
    int count
);

// Calculates average humidity.
float calculateAverageHumidity(
    const SensorReading readings[],
    int count
);

// Calculates average AQI.
float calculateAverageAQI(
    const SensorReading readings[],
    int count
);

// Represents different air quality categories.
typedef enum {
    GOOD,
    MODERATE,
    UNHEALTHY_FOR_SENSITIVE_GROUPS,
    VERY_UNHEALTHY,
    HAZARDOUS
} AQICategory;

// Returns the AQI category.
AQICategory getAQICategory(int aqi);

// Returns the category name as a string.
const char *getAQICategoryName(AQICategory category);

#ifdef __cplusplus
}
#endif

#endif

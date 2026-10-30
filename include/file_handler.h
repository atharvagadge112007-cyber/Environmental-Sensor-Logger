
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensor.h"

// Saves sensor readings to a CSV file.
// Returns 1 if successful, 0 if unsuccessful.
int saveReadingsToFile(
    const char *filename,
    const SensorReading readings[],
    int count
);

// Loads sensor readings from a CSV file.
// Returns the number of readings loaded, or -1 on error.
int loadReadingsFromFile(
    const char *filename,
    SensorReading readings[],
    int maxReadings
);

#ifdef __cplusplus
}
#endif

#endif
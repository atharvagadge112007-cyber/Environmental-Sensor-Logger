
#ifndef SENSOR_H
#define SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_READINGS 100

// Structure to store one environmental sensor reading
typedef struct {
    int id;
    float temperature;
    float humidity;
    int aqi;
    float lightIntensity;
} SensorReading;

// Adds a new reading.
// Returns 1 if successful, 0 if unsuccessful.
int addReading(
    SensorReading readings[],
    int *count,
    SensorReading newReading
);

// Displays all stored readings.
void displayReadings(
    const SensorReading readings[],
    int count
);

// Searches for a reading by ID.
// Returns the index if found, otherwise -1.
int searchReadingById(
    const SensorReading readings[],
    int count,
    int id
);

#ifdef __cplusplus
}
#endif

#endif

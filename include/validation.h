
#ifndef VALIDATION_H
#define VALIDATION_H

#ifdef __cplusplus
extern "C" {
#endif

// Validates temperature (-50 to 60 Celsius).
int validateTemperature(float temperature);

// Validates humidity (0 to 100 percent).
int validateHumidity(float humidity);

// Validates AQI (0 to 500).
int validateAQI(int aqi);

// Validates light intensity (0 or greater).
int validateLightIntensity(float lightIntensity);

#ifdef __cplusplus
}
#endif

#endif

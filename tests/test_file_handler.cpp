
#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

extern "C" {
#include "file_handler.h"
}

// Helper function to create a valid sensor reading
SensorReading createReading(int id) {
    SensorReading reading;

    reading.id = id;
    reading.temperature = 28.5f;
    reading.humidity = 65.0f;
    reading.aqi = 45;
    reading.lightIntensity = 300.0f;

    return reading;
}

// Helper function to create a CSV file for testing
void createCSVFile(const char *filename, const char *content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

// Test 1: Successfully save readings to a file
TEST(FileHandlerTest, SaveReadingsSuccessfully) {
    const char *filename = "test_save.csv";

    SensorReading readings[2];

    readings[0] = createReading(1);
    readings[1] = createReading(2);

    int result = saveReadingsToFile(filename, readings, 2);

    EXPECT_EQ(result, 1);

    std::remove(filename);
}

// Test 2: Successfully load readings from a file
TEST(FileHandlerTest, LoadReadingsSuccessfully) {
    const char *filename = "test_load.csv";

    createCSVFile(
        filename,
        "id,temperature,humidity,aqi,lightIntensity\n"
        "1,28.5,65.0,45,300.0\n"
        "2,30.0,70.0,85,450.0\n"
    );

    SensorReading readings[MAX_READINGS];

    int count = loadReadingsFromFile(
        filename, readings, MAX_READINGS
    );

    ASSERT_EQ(count, 2);
    EXPECT_EQ(readings[0].id, 1);
    EXPECT_EQ(readings[1].id, 2);

    std::remove(filename);
}

// Test 3: Load an empty CSV file
TEST(FileHandlerTest, LoadEmptyFile) {
    const char *filename = "test_empty.csv";

    createCSVFile(
        filename,
        "id,temperature,humidity,aqi,lightIntensity\n"
    );

    SensorReading readings[MAX_READINGS];

    int count = loadReadingsFromFile(
        filename, readings, MAX_READINGS
    );

    EXPECT_EQ(count, 0);

    std::remove(filename);
}

// Test 4: Handle a file that does not exist
TEST(FileHandlerTest, HandleMissingFile) {
    SensorReading readings[MAX_READINGS];

    int count = loadReadingsFromFile(
        "file_that_does_not_exist.csv",
        readings,
        MAX_READINGS
    );

    EXPECT_EQ(count, -1);
}

// Test 5: Reject invalid CSV data
TEST(FileHandlerTest, RejectInvalidCSVData) {
    const char *filename = "test_invalid.csv";

    createCSVFile(
        filename,
        "id,temperature,humidity,aqi,lightIntensity\n"
        "1,invalid,65.0,45,300.0\n"
    );

    SensorReading readings[MAX_READINGS];

    int count = loadReadingsFromFile(
        filename, readings, MAX_READINGS
    );

    EXPECT_EQ(count, -1);

    std::remove(filename);
}

// Test 6: Reject duplicate IDs in the CSV file
TEST(FileHandlerTest, RejectDuplicateIDs) {
    const char *filename = "test_duplicate.csv";

    createCSVFile(
        filename,
        "id,temperature,humidity,aqi,lightIntensity\n"
        "1,28.5,65.0,45,300.0\n"
        "1,30.0,70.0,85,450.0\n"
    );

    SensorReading readings[MAX_READINGS];

    int count = loadReadingsFromFile(
        filename, readings, MAX_READINGS
    );

    EXPECT_EQ(count, -1);

    std::remove(filename);
}

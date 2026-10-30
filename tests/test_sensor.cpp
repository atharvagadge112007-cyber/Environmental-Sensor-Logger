
#include <gtest/gtest.h>

extern "C" {
#include "sensor.h"
}

// Helper function to create a valid reading.
static SensorReading createValidReading(int id)
{
    SensorReading reading = {
        id,
        28.5f,
        65.0f,
        45,
        300.0f
    };

    return reading;
}

// ================================
// ADD READING TESTS
// ================================

TEST(SensorTest, AddValidReading)
{
    SensorReading readings[MAX_READINGS] = {};
    int count = 0;

    SensorReading newReading = createValidReading(1);

    EXPECT_EQ(addReading(readings, &count, newReading), 1);
    EXPECT_EQ(count, 1);
    EXPECT_EQ(readings[0].id, 1);
}

TEST(SensorTest, RejectInvalidReading)
{
    SensorReading readings[MAX_READINGS] = {};
    int count = 0;

    SensorReading newReading = createValidReading(1);
    newReading.temperature = 100.0f;

    EXPECT_EQ(addReading(readings, &count, newReading), 0);
    EXPECT_EQ(count, 0);
}

TEST(SensorTest, RejectDuplicateID)
{
    SensorReading readings[MAX_READINGS] = {};
    int count = 0;

    SensorReading first = createValidReading(1);
    SensorReading second = createValidReading(1);

    EXPECT_EQ(addReading(readings, &count, first), 1);
    EXPECT_EQ(addReading(readings, &count, second), 0);

    EXPECT_EQ(count, 1);
}

TEST(SensorTest, RejectReadingWhenArrayIsFull)
{
    SensorReading readings[MAX_READINGS] = {};
    int count = MAX_READINGS;

    SensorReading newReading = createValidReading(101);

    EXPECT_EQ(addReading(readings, &count, newReading), 0);
    EXPECT_EQ(count, MAX_READINGS);
}

// ================================
// SEARCH READING TESTS
// ================================

TEST(SensorTest, FindExistingReading)
{
    SensorReading readings[MAX_READINGS] = {};

    readings[0] = createValidReading(10);
    readings[1] = createValidReading(20);

    int index = searchReadingById(readings, 2, 20);

    EXPECT_EQ(index, 1);
}

TEST(SensorTest, ReturnMinusOneForMissingID)
{
    SensorReading readings[MAX_READINGS] = {};

    readings[0] = createValidReading(10);
    readings[1] = createValidReading(20);

    int index = searchReadingById(readings, 2, 99);

    EXPECT_EQ(index, -1);
}

TEST(SensorTest, SearchEmptyArray)
{
    SensorReading readings[MAX_READINGS] = {};

    int index = searchReadingById(readings, 0, 10);

    EXPECT_EQ(index, -1);
}

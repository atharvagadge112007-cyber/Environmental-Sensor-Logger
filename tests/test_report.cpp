
#include <gtest/gtest.h>

extern "C" {
#include "report.h"
}

// Helper function to create sensor readings.
static SensorReading createReading(
    int id,
    float temperature,
    float humidity,
    int aqi,
    float light)
{
    SensorReading reading = {
        id,
        temperature,
        humidity,
        aqi,
        light
    };

    return reading;
}

// ================================
// AVERAGE TEMPERATURE TESTS
// ================================

TEST(ReportTest, CalculateAverageTemperature)
{
    SensorReading readings[] = {
        createReading(1, 20.0f, 60.0f, 40, 100.0f),
        createReading(2, 30.0f, 70.0f, 80, 200.0f),
        createReading(3, 40.0f, 80.0f, 120, 300.0f)
    };

    EXPECT_FLOAT_EQ(
        calculateAverageTemperature(readings, 3),
        30.0f
    );
}

TEST(ReportTest, AverageTemperatureWithNoReadings)
{
    SensorReading readings[1] = {};

    EXPECT_FLOAT_EQ(
        calculateAverageTemperature(readings, 0),
        0.0f
    );
}

// ================================
// AVERAGE HUMIDITY TESTS
// ================================

TEST(ReportTest, CalculateAverageHumidity)
{
    SensorReading readings[] = {
        createReading(1, 20.0f, 50.0f, 40, 100.0f),
        createReading(2, 30.0f, 60.0f, 80, 200.0f),
        createReading(3, 40.0f, 70.0f, 120, 300.0f)
    };

    EXPECT_FLOAT_EQ(
        calculateAverageHumidity(readings, 3),
        60.0f
    );
}

// ================================
// AVERAGE AQI TESTS
// ================================

TEST(ReportTest, CalculateAverageAQI)
{
    SensorReading readings[] = {
        createReading(1, 20.0f, 50.0f, 30, 100.0f),
        createReading(2, 30.0f, 60.0f, 60, 200.0f),
        createReading(3, 40.0f, 70.0f, 90, 300.0f)
    };

    EXPECT_FLOAT_EQ(
        calculateAverageAQI(readings, 3),
        60.0f
    );
}

TEST(ReportTest, AverageAQIWithNoReadings)
{
    SensorReading readings[1] = {};

    EXPECT_FLOAT_EQ(
        calculateAverageAQI(readings, 0),
        0.0f
    );
}

// ================================
// AQI CLASSIFICATION TESTS
// ================================

TEST(ReportTest, ClassifyGoodAQI)
{
    EXPECT_EQ(getAQICategory(25), GOOD);
}

TEST(ReportTest, ClassifyModerateAQI)
{
    EXPECT_EQ(getAQICategory(75), MODERATE);
}

TEST(ReportTest, ClassifySensitiveGroupsAQI)
{
    EXPECT_EQ(
        getAQICategory(125),
        UNHEALTHY_FOR_SENSITIVE_GROUPS
    );
}

TEST(ReportTest, ClassifyVeryUnhealthyAQI)
{
    EXPECT_EQ(getAQICategory(175), VERY_UNHEALTHY);
}

TEST(ReportTest, ClassifyHazardousAQI)
{
    EXPECT_EQ(getAQICategory(250), HAZARDOUS);
}

// ================================
// AQI BOUNDARY TESTS
// ================================

TEST(ReportTest, AQIBoundary50)
{
    EXPECT_EQ(getAQICategory(50), GOOD);
}

TEST(ReportTest, AQIBoundary51)
{
    EXPECT_EQ(getAQICategory(51), MODERATE);
}

TEST(ReportTest, AQIBoundary100)
{
    EXPECT_EQ(getAQICategory(100), MODERATE);
}

TEST(ReportTest, AQIBoundary101)
{
    EXPECT_EQ(
        getAQICategory(101),
        UNHEALTHY_FOR_SENSITIVE_GROUPS
    );
}

// ================================
// AQI CATEGORY NAME TEST
// ================================

TEST(ReportTest, GetAQICategoryName)
{
    EXPECT_STREQ(getAQICategoryName(GOOD), "GOOD");

    EXPECT_STREQ(
        getAQICategoryName(HAZARDOUS),
        "HAZARDOUS"
    );
}

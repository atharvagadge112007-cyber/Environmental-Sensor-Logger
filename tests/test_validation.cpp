
#include <gtest/gtest.h>

extern "C" {
#include "validation.h"
}

// ================================
// TEMPERATURE TESTS
// ================================

TEST(TemperatureTest, ValidTemperature)
{
    EXPECT_EQ(validateTemperature(25.5f), 1);
}

TEST(TemperatureTest, MinimumTemperature)
{
    EXPECT_EQ(validateTemperature(-50.0f), 1);
}

TEST(TemperatureTest, MaximumTemperature)
{
    EXPECT_EQ(validateTemperature(60.0f), 1);
}

TEST(TemperatureTest, InvalidTemperature)
{
    EXPECT_EQ(validateTemperature(100.0f), 0);
}

// ================================
// HUMIDITY TESTS
// ================================

TEST(HumidityTest, ValidHumidity)
{
    EXPECT_EQ(validateHumidity(65.5f), 1);
}

TEST(HumidityTest, MinimumHumidity)
{
    EXPECT_EQ(validateHumidity(0.0f), 1);
}

TEST(HumidityTest, MaximumHumidity)
{
    EXPECT_EQ(validateHumidity(100.0f), 1);
}

TEST(HumidityTest, InvalidHumidity)
{
    EXPECT_EQ(validateHumidity(120.0f), 0);
}

// ================================
// AQI TESTS
// ================================

TEST(AQITest, ValidAQI)
{
    EXPECT_EQ(validateAQI(100), 1);
}

TEST(AQITest, MinimumAQI)
{
    EXPECT_EQ(validateAQI(0), 1);
}

TEST(AQITest, MaximumAQI)
{
    EXPECT_EQ(validateAQI(500), 1);
}

TEST(AQITest, InvalidAQI)
{
    EXPECT_EQ(validateAQI(600), 0);
}

// ================================
// LIGHT INTENSITY TESTS
// ================================

TEST(LightTest, ValidLightIntensity)
{
    EXPECT_EQ(validateLightIntensity(300.5f), 1);
}

TEST(LightTest, ZeroLightIntensity)
{
    EXPECT_EQ(validateLightIntensity(0.0f), 1);
}

TEST(LightTest, NegativeLightIntensity)
{
    EXPECT_EQ(validateLightIntensity(-10.0f), 0);
}

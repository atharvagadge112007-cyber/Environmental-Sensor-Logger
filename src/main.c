
#include <stdio.h>
#include <string.h>

#include "sensor.h"
#include "validation.h"
#include "file_handler.h"
#include "report.h"

#define DATA_FILE "data/sensor_data.csv"

// Clears unwanted characters from the input buffer.
static void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // Discard remaining characters.
    }
}

// Displays the application menu.
static void displayMenu(void)
{
    printf("\n====================================\n");
    printf("     ENVIRONMENTAL SENSOR LOGGER\n");
    printf("====================================\n");
    printf("1. Add Sensor Reading\n");
    printf("2. Display All Readings\n");
    printf("3. Search Reading by ID\n");
    printf("4. Display Average Report\n");
    printf("5. Save Readings to File\n");
    printf("6. Load Readings from File\n");
    printf("7. Exit\n");
    printf("====================================\n");
}

// Accepts a new sensor reading.
static void handleAddReading(
    SensorReading readings[],
    int *count)
{
    SensorReading newReading;

    printf("\nEnter Reading ID: ");

    if (scanf("%d", &newReading.id) != 1)
    {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter Temperature (Celsius): ");

    if (scanf("%f", &newReading.temperature) != 1)
    {
        printf("Invalid temperature input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter Humidity (%%): ");

    if (scanf("%f", &newReading.humidity) != 1)
    {
        printf("Invalid humidity input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter AQI: ");

    if (scanf("%d", &newReading.aqi) != 1)
    {
        printf("Invalid AQI input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter Light Intensity (lux): ");

    if (scanf("%f", &newReading.lightIntensity) != 1)
    {
        printf("Invalid light intensity input.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    addReading(readings, count, newReading);
}

// Searches for a sensor reading.
static void handleSearchReading(
    const SensorReading readings[],
    int count)
{
    int id;

    printf("Enter Reading ID to search: ");

    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    int index = searchReadingById(readings, count, id);

    if (index == -1)
    {
        printf("Reading not found.\n");
    }
    else
    {
        printf("\nReading Found!\n");

        displayReadings(&readings[index], 1);
    }
}

// Displays average sensor values.
static void handleAverageReport(
    const SensorReading readings[],
    int count)
{
    if (count == 0)
    {
        printf("No readings available for report.\n");
        return;
    }

    float avgTemperature =
        calculateAverageTemperature(readings, count);

    float avgHumidity =
        calculateAverageHumidity(readings, count);

    float avgAQI =
        calculateAverageAQI(readings, count);

    printf("\n========== SENSOR REPORT ==========\n");

    printf("Total Readings: %d\n", count);

    printf("Average Temperature: %.2f C\n", avgTemperature);

    printf("Average Humidity: %.2f %%\n", avgHumidity);

    printf("Average AQI: %.2f\n", avgAQI);

    printf("Average AQI Category: %s\n",
        getAQICategoryName(getAQICategory((int)avgAQI)));

    printf("===================================\n");
}

// Loads readings using a temporary array.
// Existing readings are replaced only after successful loading.
static void handleLoadReadings(
    SensorReading readings[],
    int *count)
{
    SensorReading temporaryReadings[MAX_READINGS];

    int loadedCount = loadReadingsFromFile(
        DATA_FILE,
        temporaryReadings,
        MAX_READINGS
    );

    if (loadedCount == -1)
    {
        printf("Could not load readings. Existing data preserved.\n");
        return;
    }

    memcpy(
        readings,
        temporaryReadings,
        (size_t)loadedCount * sizeof(SensorReading)
    );

    *count = loadedCount;

    printf("%d readings loaded into the application.\n", *count);
}

int main(void)
{
    SensorReading readings[MAX_READINGS];

    int count = 0;
    int choice = 0;

    printf("Welcome to Environmental Sensor Logger!\n");

    do
    {
        displayMenu();

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid menu choice. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                handleAddReading(readings, &count);
                break;

            case 2:
                displayReadings(readings, count);
                break;

            case 3:
                handleSearchReading(readings, count);
                break;

            case 4:
                handleAverageReport(readings, count);
                break;

            case 5:
                saveReadingsToFile(DATA_FILE, readings, count);
                break;

            case 6:
                handleLoadReadings(readings, &count);
                break;

            case 7:
                printf("Thank you for using Environmental Sensor Logger!\n");
                break;

            default:
                printf("Invalid choice. Please select 1 to 7.\n");
        }

    } while (choice != 7);

    return 0;
}


# Detailed Design Document
## Environmental Sensor Logger

### 1. Project Overview

The Environmental Sensor Logger is a modular C application that collects, validates, stores, and analyzes environmental sensor readings.

The application will accept readings through the terminal. It will store temperature, humidity, air quality index (AQI), and light intensity values.

The application will use structures, functions, pointers, arrays, file handling, and modular programming.

---

### 2. System Architecture

The application is divided into five main modules.

```text
                 +------------------+
                 |     main.c       |
                 |   Menu System    |
                 +--------+---------+
                          |
          +---------------+---------------+
          |               |               |
          v               v               v
   +-------------+ +-------------+ +-------------+
   |  sensor.c   | | validation.c| |  report.c   |
   |             | |             | |             |
   | Add Reading | | Validate    | | Calculate   |
   | Search      | | Sensor Data | | Averages    |
   +------+------+ +-------------+ +-------------+
          |
          v
   +-------------+
   |file_handler.c|
   |             |
   | Save Data   |
   | Load Data   |
   +-------------+
```

### 3. Data Design

#### 3.1 Sensor Structure

A structure named `SensorReading` will store one sensor reading.

| Member | Data Type | Description |
|---|---|---|
| id | int | Unique reading ID |
| temperature | float | Temperature in Celsius |
| humidity | float | Humidity percentage |
| aqi | int | Air Quality Index |
| lightIntensity | float | Light intensity in lux |

#### 3.2 Constants

The following constants will be used:

| Constant | Value | Purpose |
|---|---:|---|
| MAX_READINGS | 100 | Maximum number of readings |
| MIN_TEMPERATURE | -50 | Minimum accepted temperature |
| MAX_TEMPERATURE | 60 | Maximum accepted temperature |
| MIN_HUMIDITY | 0 | Minimum humidity |
| MAX_HUMIDITY | 100 | Maximum humidity |
| MIN_AQI | 0 | Minimum AQI |
| MAX_AQI | 500 | Maximum AQI |
| MIN_LIGHT | 0 | Minimum light intensity |

These are educational validation limits for this project.

#### 3.3 AQI Category Enumeration

An enum named `AQICategory` will represent the air quality category.

The simplified educational categories will be:

- GOOD: 0–50
- MODERATE: 51–100
- UNHEALTHY_FOR_SENSITIVE_GROUPS: 101–150
- VERY_UNHEALTHY: 151–200
- HAZARDOUS: 201–500

These categories are for project demonstration and are not intended to represent official Indian AQI guidance.

---

### 4. Module Design

#### 4.1 main.c

**Purpose:** Controls the application and displays the menu.

Responsibilities:
- Display menu options.
- Accept the user's choice.
- Call the appropriate module functions.
- Continue running until the user exits.

Menu options:

1. Add Sensor Reading
2. Display All Readings
3. Search Reading by ID
4. Display Average Values
5. Save Readings to File
6. Load Readings from File
7. Exit

#### 4.2 sensor.c

**Purpose:** Manages sensor readings.

Functions:

- `addReading()` – Adds a new sensor reading.
- `displayReadings()` – Displays all stored readings.
- `searchReadingById()` – Searches for a reading using its ID.

#### 4.3 validation.c

**Purpose:** Checks whether sensor readings contain valid values.

Functions:

- `validateTemperature()` – Checks temperature limits.
- `validateHumidity()` – Checks humidity limits.
- `validateAQI()` – Checks AQI limits.
- `validateLightIntensity()` – Checks light intensity.

#### 4.4 file_handler.c

**Purpose:** Handles saving and loading sensor readings.

Functions:

- `saveReadingsToFile()` – Saves readings in CSV format.
- `loadReadingsFromFile()` – Loads readings from a CSV file.

#### 4.5 report.c

**Purpose:** Performs calculations and generates reports.

Functions:

- `calculateAverageTemperature()` – Calculates average temperature.
- `calculateAverageHumidity()` – Calculates average humidity.
- `calculateAverageAQI()` – Calculates average AQI.
- `getAQICategory()` – Returns the AQI category.

---

### 5. File Handling Design

The application will store data in a CSV file named:

`data/sensor_data.csv`

Example:

```csv
id,temperature,humidity,aqi,lightIntensity
1,28.5,65.0,45,300.0
2,30.0,70.0,85,450.0
3,26.5,55.0,120,250.0
```

The CSV file will allow the application to preserve readings even after it is closed.

---

### 6. Input Validation and Error Handling

The application will handle the following situations:

| Situation | Expected Handling |
|---|---|
| Temperature below -50 | Reject reading |
| Temperature above 60 | Reject reading |
| Humidity below 0 | Reject reading |
| Humidity above 100 | Reject reading |
| AQI below 0 | Reject reading |
| AQI above 500 | Reject reading |
| Negative light intensity | Reject reading |
| Duplicate reading ID | Reject reading |
| Search for unavailable ID | Display not found message |
| File does not exist | Display an appropriate error |
| No readings available | Display a suitable message |

---

### 7. Program Workflow

1. Start the application.
2. Display the main menu.
3. Ask the user to select an operation.
4. If the user selects Add Reading:
   - Accept sensor values.
   - Validate the entered values.
   - Check for duplicate IDs.
   - Store the reading if valid.
5. If the user selects Display Readings:
   - Display all stored readings.
6. If the user selects Search:
   - Ask for a reading ID.
   - Search and display the matching record.
7. If the user selects Average Report:
   - Calculate average temperature, humidity, and AQI.
   - Display the results.
8. If the user selects Save:
   - Save readings to the CSV file.
9. If the user selects Load:
   - Load readings from the CSV file.
10. Exit when the user selects the Exit option.

---

### 8. Testing Design

Google Test will be used to test the C functions.

The test cases will include:

**Positive Tests**
- Valid temperature.
- Valid humidity.
- Valid AQI.
- Valid light intensity.
- Successful reading insertion.

**Negative Tests**
- Invalid temperature.
- Invalid humidity.
- Invalid AQI.
- Negative light intensity.
- Duplicate reading ID.

**Boundary Tests**
- Minimum temperature.
- Maximum temperature.
- Minimum humidity.
- Maximum humidity.
- Minimum AQI.
- Maximum AQI.

---

### 9. Expected Outcome

The completed application should be able to:

- Accept environmental sensor readings.
- Validate input values.
- Store multiple readings.
- Search and display readings.
- Save and load readings using CSV files.
- Calculate average environmental values.
- Classify AQI using simplified educational categories.
- Pass the planned unit tests.

---

### 10. Future Enhancements

- Connect actual sensors using Arduino or other hardware.
- Display readings through a graphical interface.
- Generate reports in PDF format.
- Add date and time to every reading.
- Display historical sensor data.

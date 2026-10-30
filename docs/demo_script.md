# Project Demonstration Script
## Environmental Sensor Logger

## 1. Introduction

Good morning!

My project is called Environmental Sensor Logger.

It is an individual C programming project that allows users to record, store, search, and analyze environmental sensor readings.

The application works through a terminal-based menu.

It records four environmental parameters:
- Temperature
- Humidity
- Air Quality Index (AQI)
- Light Intensity

Currently, the sensor readings are entered manually by the user.

## 2. Project Architecture

The project is divided into multiple modules.

- main.c: Handles the menu and overall application flow.
- sensor.c: Adds, displays, and searches sensor readings.
- validation.c: Validates environmental sensor values.
- file_handler.c: Saves and loads readings using CSV files.
- report.c: Calculates averages and classifies AQI.

Each module has a corresponding header file inside the include directory.

## 3. Demonstration Steps

### Step 1: Start the Application

Run:

```bash
make run
```

Explain that the application displays a menu with different operations.

### Step 2: Add Sensor Reading

Select the Add Reading option.

Enter:
- Sensor ID
- Temperature
- Humidity
- AQI
- Light Intensity

Explain that the application validates the entered values before storing them.

### Step 3: Display Readings

Select the Display Readings option.

Explain that all stored sensor readings are displayed in a table.

### Step 4: Search for a Reading

Select the Search Reading option.

Enter an existing sensor ID.

Explain how the application searches for the requested reading.

### Step 5: Generate Report

Select the Average Report option.

Explain that the application calculates:
- Average temperature
- Average humidity
- Average AQI

It also classifies air quality based on AQI.

### Step 6: Save Readings

Select the Save Readings option.

Explain that the readings are stored in a CSV file.

### Step 7: Load Readings

Select the Load Readings option.

Explain that previously saved readings can be loaded from the CSV file.

### Step 8: Exit

Select Exit to close the application.

## 4. Google Test Demonstration

Run:

```bash
make test
```

Explain that Google Test is used to test the individual modules.

The tests cover:
- Valid inputs
- Invalid inputs
- Boundary conditions
- Sensor operations
- File handling
- Report calculations

All Google Test cases passed during project testing.

## 5. Build System Demonstration

Show the Makefile and explain these commands:

| Command | Purpose |
|---|---|
| make | Builds the application and tests |
| make run | Runs the application |
| make test | Executes Google Tests |
| make clean | Removes generated files |

## 6. Conclusion

The Environmental Sensor Logger demonstrates modular C programming, structures, functions, pointers, file handling, input validation, and automated testing using Google Test.

The project can be extended in the future by connecting real environmental sensors and collecting readings automatically.

Thank you!

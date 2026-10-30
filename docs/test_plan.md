# Test Plan – Environmental Sensor Logger

## 1. Introduction

The purpose of this test plan is to verify that the Environmental Sensor Logger works correctly.

Google Test (GTest) is used to test the individual C modules.

The tests cover normal inputs, invalid inputs, and boundary conditions.

## 2. Testing Framework

- Programming Language: C and C++
- Testing Framework: Google Test
- Build Tool: GNU Make
- Compiler: GCC and G++

## 3. Modules to Be Tested

| Module | Functions |
|---|---|
| Sensor | addReading(), displayReadings(), searchReadingById() |
| Validation | validateTemperature(), validateHumidity(), validateAQI(), validateLightIntensity() |
| File Handler | saveReadingsToFile(), loadReadingsFromFile() |
| Report | calculateAverageTemperature(), calculateAverageHumidity(), calculateAverageAQI(), getAQICategory() |

## 4. Test Cases

### 4.1 Validation Tests

| Test | Expected Result |
|---|---|
| Valid temperature | Accepted |
| Minimum temperature (-50) | Accepted |
| Maximum temperature (60) | Accepted |
| Temperature above 60 | Rejected |
| Valid humidity | Accepted |
| Humidity equal to 0 | Accepted |
| Humidity equal to 100 | Accepted |
| Humidity above 100 | Rejected |
| Valid AQI | Accepted |
| AQI equal to 0 | Accepted |
| AQI equal to 500 | Accepted |
| AQI above 500 | Rejected |
| Valid light intensity | Accepted |
| Light intensity equal to 0 | Accepted |
| Negative light intensity | Rejected |

### 4.2 Sensor Tests

| Test | Expected Result |
|---|---|
| Add valid reading | Success |
| Add invalid temperature | Failure |
| Add duplicate sensor ID | Failure |
| Add reading when array is full | Failure |
| Search existing ID | Correct index returned |
| Search missing ID | -1 returned |
| Search empty array | -1 returned |

### 4.3 Report Tests

| Test | Expected Result |
|---|---|
| Calculate average temperature | Correct average |
| Calculate average temperature with no readings | 0.0 |
| Calculate average humidity | Correct average |
| Calculate average AQI | Correct average |
| Calculate average AQI with no readings | 0.0 |
| AQI between 0 and 50 | GOOD |
| AQI between 51 and 100 | MODERATE |
| AQI between 101 and 150 | UNHEALTHY FOR SENSITIVE GROUPS |
| AQI between 151 and 200 | VERY UNHEALTHY |
| AQI between 201 and 500 | HAZARDOUS |
| AQI equal to 50 | GOOD |
| AQI equal to 51 | MODERATE |
| AQI equal to 100 | MODERATE |
| AQI equal to 101 | UNHEALTHY FOR SENSITIVE GROUPS |
| Get category name | Correct category name |

### 4.4 File Handler Tests

| Test | Expected Result |
|---|---|
| Save readings successfully | Returns 1 |
| Load readings successfully | Correct number of readings |
| Load empty CSV file | Returns 0 |
| Load missing file | Returns -1 |
| Load invalid CSV data | Returns -1 |
| Load duplicate IDs | Returns -1 |

## 5. Testing Procedure

Run the following commands from the project root directory.

### Step 1: Clean previous build files

```bash
make clean
```

### Step 2: Compile the project

```bash
make
```

### Step 3: Execute Google Tests

```bash
make test
```

### Step 4: Run the application

```bash
make run
```

## 6. Expected Results

- All valid sensor readings should be accepted.
- Invalid sensor readings should be rejected.
- Duplicate sensor IDs should not be accepted.
- Search should return the correct reading index.
- Average calculations should produce correct results.
- AQI classification should return the correct category.
- CSV files should be saved and loaded successfully.
- Invalid CSV data should be rejected.

## 7. Actual Test Results

The project was compiled successfully using the Makefile.

All Google Test cases passed during testing.

## 8. Conclusion

The testing process verifies the major functions of the Environmental Sensor Logger.

The project successfully performs sensor data validation, storage, searching, file handling, and report calculations.

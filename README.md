# Environmental Sensor Logger

## 1. Project Description

The Environmental Sensor Logger is a C programming project designed to record, store, and analyze environmental sensor readings.

The application allows users to enter environmental data manually through a terminal and generate reports based on the collected readings.

## 2. Features

- Add new environmental sensor readings.
- Display all stored readings.
- Search for readings using sensor IDs.
- Validate temperature, humidity, AQI, and light intensity.
- Save readings into CSV files.
- Load readings from CSV files.
- Calculate average temperature, humidity, and AQI.
- Classify air quality based on AQI values.
- Automated testing using Google Test.

## 3. Sensor Parameters

| Parameter | Description |
|---|---|
| Temperature | Temperature in Celsius |
| Humidity | Relative humidity in percentage |
| AQI | Air Quality Index |
| Light Intensity | Light intensity in lux |

## 4. Technologies Used

- Programming Language: C
- Testing Framework: Google Test
- Compiler: GCC and G++
- Build Tool: GNU Make
- Debugging Tool: GDB
- Version Control: Git

## 5. Project Structure

```text
Environmental-Sensor-Logger/
│
├── src/
│   ├── main.c
│   ├── sensor.c
│   ├── validation.c
│   ├── file_handler.c
│   └── report.c
│
├── include/
│   ├── sensor.h
│   ├── validation.h
│   ├── file_handler.h
│   └── report.h
│
├── tests/
│   ├── test_sensor.cpp
│   ├── test_validation.cpp
│   ├── test_report.cpp
│   └── test_file_handler.cpp
│
├── data/
│   └── sample_data.csv
│
├── docs/
│
├── build/
├── Makefile
└── README.md
```

## 6. How to Compile

First, clone the repository:

```bash
git clone YOUR_GITHUB_REPOSITORY_URL
```

Navigate to the project directory:

```bash
cd Environmental-Sensor-Logger
```

Compile the project:

```bash
make
```

## 7. How to Run

Run the application:

```bash
make run
```

To load the sample readings, copy the sample file:

```bash
cp data/sample_data.csv data/sensor_data.csv
```

Then select the Load Readings option from the application menu.

## 8. How to Run Tests

Execute all Google Tests:

```bash
make test
```

The project includes tests for:

- Sensor operations
- Data validation
- Report calculations
- File handling

## 9. AQI Classification

The project uses simplified educational AQI categories:

| AQI Range | Category |
|---|---|
| 0–50 | GOOD |
| 51–100 | MODERATE |
| 101–150 | UNHEALTHY FOR SENSITIVE GROUPS |
| 151–200 | VERY UNHEALTHY |
| 201–500 | HAZARDOUS |

These categories are simplified for educational purposes and are not official Indian CPCB AQI guidance.

## 10. Future Improvements

- Connect real environmental sensors.
- Add graphical data visualization.
- Generate daily and weekly reports.
- Store readings with timestamps.
- Implement automatic sensor data collection.

## 11. Author

Developed as an individual C programming mini-project.

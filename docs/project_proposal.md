
# Project Proposal: Environmental Sensor Logger

## 1. Project Title

Environmental Sensor Logger

## 2. Student Information

- Student Name: [Your Name]
- Roll Number: [Your Roll Number]
- Division/Batch: [Your Division]
- Project Title: Environmental Sensor Logger
- GitHub Repository: [Add Later]

## 3. Engineering Scenario

Domain: Environmental Monitoring

Environmental monitoring is important for understanding the
conditions of our surroundings.

Environmental sensors are used to measure parameters such as:
- Temperature
- Humidity
- Air Quality Index (AQI)
- Light Intensity

These measurements help us understand environmental
conditions and identify unusual changes.

However, manually maintaining sensor readings can become
difficult when the number of readings increases.

This project provides a software solution to record,
manage, validate and analyse environmental sensor readings.

## 4. Problem Statement

Environmental monitoring systems generate different types
of readings.

Without a proper management system:
- Sensor readings may be lost.
- Invalid readings may be recorded.
- Searching previous readings becomes difficult.
- Calculating average environmental conditions takes time.
- Identifying unusual environmental conditions becomes
  difficult.

Therefore, a software application is required to manage
environmental readings efficiently.

## 5. Proposed Solution

The Environmental Sensor Logger is a menu-driven application
developed using the C programming language.

The application will allow users to:

1. Add new sensor readings.
2. Validate sensor measurements.
3. Display all recorded readings.
4. Search readings using their ID.
5. Store readings in a CSV file.
6. Calculate average temperature.
7. Calculate average humidity.
8. Calculate average AQI.
9. Generate an environmental summary report.
10. Identify environmental conditions using AQI categories.

Sensor values will initially be entered manually through
the terminal to simulate actual sensor readings.

## 6. Target Users

- Environmental monitoring students.
- Laboratory assistants.
- Environmental researchers.
- Small environmental monitoring stations.

## 7. Project Scope

### In Scope

- Temperature recording.
- Humidity recording.
- Air quality recording.
- Light intensity recording.
- Input validation.
- Record searching.
- File handling.
- Average calculations.
- Report generation.
- Unit testing using Google Test.

### Out of Scope

- Physical sensor integration.
- Cloud-based monitoring.
- Mobile application.
- GPS tracking.
- Real-time internet dashboard.

## 8. Functional Requirements

FR-01: The system shall allow users to add sensor readings.

FR-02: The system shall validate sensor measurements.

FR-03: The system shall prevent duplicate reading IDs.

FR-04: The system shall display all recorded readings.

FR-05: The system shall search readings using their ID.

FR-06: The system shall save readings in a CSV file.

FR-07: The system shall load previously stored readings.

FR-08: The system shall calculate average temperature,
humidity and AQI.

FR-09: The system shall generate an environmental report.

FR-10: The system shall handle invalid inputs and file errors.

## 9. Non-Functional Requirements

- Code readability.
- Modular programming.
- Proper input validation.
- Error handling.
- Warning-free compilation.
- Unit testing using Google Test.
- Makefile-based build automation.
- Proper documentation.
- Git version control.

## 10. Initial Modules

| Module | Responsibility |
|---|---|
| main.c | Main menu and application control |
| sensor.c | Adding and searching readings |
| validation.c | Validating sensor values |
| file_handler.c | Reading and writing CSV files |
| report.c | Calculations and report generation |

## 11. Initial Architecture

User
  |
  v
Main Application
  |
  +---- Sensor Module
  |
  +---- Validation Module
  |
  +---- File Handler Module
  |
  +---- Report Module
  |
  v
CSV File Storage

## 12. High-Level Workflow

1. Start application.
2. Load existing sensor readings.
3. Display the main menu.
4. Accept the user's choice.
5. Perform the selected operation.
6. Validate input.
7. Store or retrieve readings.
8. Display results.
9. Repeat until the user exits.

## 13. Planned C Concepts

- Structures
- Enumerations
- Functions
- Arrays
- Pointers
- Strings
- Constants
- File handling
- Input validation
- Error handling

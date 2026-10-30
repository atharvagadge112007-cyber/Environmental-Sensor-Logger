# Project Reflection
## Environmental Sensor Logger

## 1. Introduction

Developing the Environmental Sensor Logger helped me understand how to apply C programming concepts to a practical project.

The project allowed me to work with multiple C source files, header files, structures, functions, pointers, and file handling.

## 2. Concepts Learned

During this project, I learned and practiced the following concepts:

- **Structures:** Used structures to store environmental sensor readings.
- **Functions:** Divided the application into smaller reusable functions.
- **Pointers:** Used pointers to update the number of stored readings.
- **Header Files:** Used header files to declare functions and share structures between modules.
- **Modular Programming:** Separated the project into independent modules.
- **File Handling:** Used CSV files to save and load sensor readings.
- **Input Validation:** Checked whether sensor values were within acceptable ranges.
- **Makefile:** Automated compilation and execution.
- **GNU Toolchain:** Used GCC and G++ to compile the application and tests.
- **Google Test:** Created automated test cases for the project modules.
- **Git:** Prepared the project for version control.

## 3. Challenges Faced

Some important areas that required attention during development were:

1. Organizing the project into multiple source and header files.
2. Understanding how C functions can be tested using C++ Google Test.
3. Managing file operations and handling invalid CSV data.
4. Preventing duplicate sensor IDs.
5. Writing Makefile rules to compile different source files.
6. Testing boundary conditions and invalid inputs.

## 4. Solutions and Improvements

To address these challenges, I divided the application into separate modules and used header files to connect them.

I implemented validation functions to reject incorrect sensor values.

I used Google Test to verify the behavior of individual functions.

I also created a Makefile to automate compilation and testing.

## 5. What I Learned About Testing

I understood the importance of testing software before considering it complete.

Google Test helped me verify:
- Correct function behavior.
- Invalid input handling.
- Boundary conditions.
- File operations.
- Average calculations.
- AQI classification.

All Google Test cases passed during my project testing.

## 6. Future Improvements

In the future, I would like to improve this project by:

- Connecting actual environmental sensors.
- Automatically collecting sensor readings.
- Adding timestamps to each reading.
- Generating graphical reports.
- Storing historical sensor readings.
- Creating daily and weekly environmental reports.

## 7. Conclusion

This project improved my understanding of modular C programming and software development practices.

It also helped me understand how compilation, automated testing, file handling, and version control work together in a real programming project.

Overall, the Environmental Sensor Logger provided practical experience in developing and testing a multi-file C application.

# Patient Movement Tracker

A C++ application that processes and analyzes patient movement data from CSV files. The project simulates a simplified wearable sensor data pipeline by loading movement readings, validating input data, and performing range-of-motion analysis.

## Features

- Object-oriented C++ design
- Patient and movement data management
- CSV file parsing and data ingestion
- Input validation and error handling
- Range-of-motion analysis:
  - Average ROM calculation
  - Highest and lowest ROM detection
  - Abnormal reading detection

## Project Structure

```csv
patient-movement-tracker/
|
├── include/
│ ├── Patient.h
│ ├── MovementReading.h
│ ├── PatientRecord.h
│ └── CSVLoader.h
|
├── src/
│ ├── main.cpp
│ ├── Patient.cpp
│ ├── MovementReading.cpp
│ ├── PatientRecord.cpp
│ └── CSVLoader.cpp
|
└── data/
└── MovementData.csv
```

## How It Works

1. Patient information is created and stored.
2. Movement data is loaded from a CSV file.
3. Each row is validated before creating a movement reading.
4. Valid readings are stored in a patient record.
5. Movement statistics can be calculated from stored data.

## Example CSV Format

```csv
Timestamp,Joint,RangeOfMotion
4:00,Wrist,20.0
4:30,Wrist,28.8
4:58,Wrist,90.9
...
```

## Build and Run

Compile:

```csv
g++ src/*.cpp -I include -o tracker
```

Run:

```csv
./tracker
```

## Technologies

- C++
- Object-Oriented Programming
- File I/O
- CSV Parsing
- Git/GitHub

#include "PatientRecord.h"
#include <iostream>

PatientRecord::PatientRecord(const Patient& patient) 
    : patient(patient)
{
}

const Patient& PatientRecord::GetPatient() const {
    return patient;
}

const std::vector<MovementReading>& PatientRecord::GetReadings() const {
    return readings;
}

void PatientRecord::AddReading(const MovementReading& reading) {
    readings.push_back(reading);
}

void PatientRecord::CheckForAbnormalReadings(float threshold) const {
    for (const MovementReading& reading : readings) {
        if (reading.GetRangeOfMotion() < threshold) {
            std::cout << "----------------------------------------------"
                << "\nWarning: Abnormal reading detected.\n";

            reading.PrintReading();
        }
    }
}

float PatientRecord::CalculateAverageROM() const {
    if (readings.empty()) {
        return 0.0;
    }

    float total = 0.0;

    for (const MovementReading& reading : readings) {
        total += reading.GetRangeOfMotion();
    }    

    return total / readings.size();
}

float PatientRecord::GetHighestROM() const{
    float highestROM = 0.0;

    for (const MovementReading& reading : readings) {
        if (reading.GetRangeOfMotion() > highestROM) {
            highestROM = reading.GetRangeOfMotion();
        }
    }

    return highestROM;
}

float PatientRecord::GetLowestROM() const {
    if (readings.empty()) {
        return 0.0;
    }

    float lowestROM = 360.0;

    for (const MovementReading& reading : readings) {
        if (reading.GetRangeOfMotion() < lowestROM) {
            lowestROM = reading.GetRangeOfMotion();
        }
    }

    return lowestROM;
}

void PatientRecord::PrintSummary() const {
    std::cout << "----------------------------------------------\n"
        << "\tPatient Record\n";

        GetPatient().PrintPatient();

        std::cout << "\n   .......................................\n";

        for (const MovementReading& reading : readings) {
            reading.PrintReading();
        }

    std::cout << "\n   .......................................\n"
        << "\nAverage ROM: " << CalculateAverageROM() 
        << "\nHighest ROM: " << GetHighestROM()
        << "\nLowest ROM: " << GetLowestROM()
        << "\n----------------------------------------------\n";
    }

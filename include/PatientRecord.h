#pragma once
#include "Patient.h"
#include "MovementReading.h"
#include <vector>


class PatientRecord {
    private:
        Patient patient;
        std::vector<MovementReading> readings;

    public:
        // constructor
        PatientRecord(const Patient& patient);

        // getters
        const Patient& GetPatient() const;
        const std::vector<MovementReading>& GetReadings() const;

        // update record
        void AddReading(const MovementReading& reading);

        // analysis
        void CheckForAbnormalReadings(float threshold) const;

        float CalculateAverageROM() const;
        float GetHighestROM() const;
        float GetLowestROM() const;

        // display view
        void PrintSummary() const;

};
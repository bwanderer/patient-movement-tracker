#pragma once
#include <string>

class MovementReading {
    private:
        // data members
        std::string timestamp;
        std::string joint;
        float rangeOfMotion;

    public:
        // constructor
        MovementReading(
            std::string timestamp = "Unknown",
            std::string joint = "Unknown",
            float rangeOfMotion = 0
        );

        // getters
        std::string GetTimestamp() const;
        std::string GetJoint() const;
        float GetRangeOfMotion() const;

        // setters
        void SetTimestamp(std::string timestamp);
        void SetJoint(std::string joint);
        void SetRangeOfMotion(float rangeOfMotion);

        void PrintReading() const;
};
#include "MovementReading.h"
#include <iostream>


MovementReading::MovementReading(
    std::string timestamp,
    std::string joint,
    float rangeOfMotion
) {
    SetTimestamp(timestamp);
    SetJoint(joint);
    SetRangeOfMotion(rangeOfMotion);
}

// getters

std::string MovementReading::GetTimestamp() const {
    return timestamp;
}

std::string MovementReading::GetJoint() const {
    return joint;
}

float MovementReading::GetRangeOfMotion() const {
    return rangeOfMotion;
}

// setters

void MovementReading::SetTimestamp(std::string timestamp) {
    if (timestamp.empty()) {
        std::cout << "\nError: Timestamp cannot be empty.\n";
        this->timestamp = "Unknown";
    }
    else {
        this->timestamp = timestamp;
    }
}

void MovementReading::SetJoint(std::string joint) {
    if (joint.empty()) {
        std::cout << "\nError: Joint cannot be empty.\n";
        this->joint = "Unknown";
    }
    else {
        this->joint = joint;
    }
}

void MovementReading::SetRangeOfMotion(float rangeOfMotion) {
    if (rangeOfMotion >= 0.0 && rangeOfMotion <= 360.0) {
        this->rangeOfMotion = rangeOfMotion;
    }
    else {
        std::cout << "\nError: Invalid range of motion.\n";
        this->rangeOfMotion = 0.0;
    }
}

void MovementReading::PrintReading() const {
    std::cout << "\nTimestamp: " << timestamp
        << "\nJoint: " << joint
        << "\nROM: " << rangeOfMotion << std::endl;
}
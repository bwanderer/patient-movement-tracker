#include "Patient.h"
#include <iostream>


Patient::Patient(
    std::string name,
    int age,
    std::string id,
    std::string condition
) {
    SetName(name);
    SetAge(age);
    SetID(id);
    SetCondition(condition);
}

// getters

std::string Patient::GetName() const {
    return name;
}

int Patient::GetAge() const {
    return age;
}

std::string Patient::GetID() const {
    return id;
}

std::string Patient::GetCondition() const {
    return condition;
}

// setters

void Patient::SetName(std::string name) {
    if (name.empty()) {
        std::cout << "\nError: Name cannot be empty.\n";
        this->name = "Unknown";
    }
    else {
        this->name = name;
    }
}

void Patient::SetAge(int age) {
    if (age >= 0) this->age = age;
    else {
        std::cout << "\nError: Invalid age input.\n";
        this->age = 0;
    }
}

void Patient::SetID(std::string id) {
    if (id.empty()) {
        std::cout << "\nError: ID cannot be empty.\n";
        this->id = "Unknown";
    }
    else {
        this->id = id;
    }
}

void Patient::SetCondition(std::string condition) {
    if (condition.empty()) {
        std::cout << "\nError: Condition cannot be empty.\n";
        this->condition = "Unknown";
    }
    else {
        this->condition = condition;
    }
}

void Patient::PrintPatient() const {
    std::cout << "\nName: " << name
        << "\nAge: " << age
        << "\nID: " << id
        << "\nCondition: " << condition << std::endl;
 }
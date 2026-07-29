#include "Patient.h"
#include <iostream>


Patient::Patient(
    std::string name,
    int age,
    std::string id,
    std::string condition
) {
    this->name = name;
    this->age = age;
    this->id = id;
    this->condition = condition;
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
    this->name = name;
}

void Patient::SetAge(int age) {
    if (age >= 0) this->age = age;
    else {
        std::cout << "Error: Invalid age input, age will be set to 0.\n";
        this->age = 0;
    }
}

void Patient::SetID(std::string id) {
    this->id = id;
}

void Patient::SetCondition(std::string condition) {
    this->condition = condition;
}

void Patient::Print() const {
    std::cout << "----------------------------------------------"
        << "\nPatient Information"
        << "\nName: " << name
        << "\nAge: " << age
        << "\nID: " << id
        << "\nCondition: " << condition 
        << "\n----------------------------------------------\n";
 }
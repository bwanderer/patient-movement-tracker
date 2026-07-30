#pragma once
#include <string>
class Patient {
    private:
        // data members
        std::string name;
        int age;
        std::string id;
        std::string condition;
        
    public:
        // constructor
        Patient(
            std::string name = "Unknown",
            int age = 0,
            std::string id = "0",
            std::string condition = "Not Defined"
        );

        // getters
        std::string GetName() const;
        int GetAge() const;
        std::string GetID() const;
        std::string GetCondition() const;

        // setters
        void SetName(std::string name);
        void SetAge(int age);
        void SetID(std::string id);
        void SetCondition(std::string condition);

        void PrintPatient() const;
};
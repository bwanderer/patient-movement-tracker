#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "PatientRecord.h"


int main(){
    std::ifstream file; // reading file

    file.open("data/MovementData.csv");

    if (!file) {
        std::cout << "Error: Unable to open file, terminating program.\n";

        return 1;
    }

    Patient p("Beatriz", 23, "PUI-1931", "Healthy");
    PatientRecord rec(p);

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {

        std::stringstream ss(line);
        std::string timestamp, joint, rom;

        std::getline(ss, timestamp, ',');
        std::getline(ss, joint, ',');
        std::getline(ss, rom);

        rec.AddReading(MovementReading(timestamp, joint, std::stof(rom)));

    }

    for (const MovementReading& reading : rec.GetReadings()) {
        reading.PrintReading();
        std::cout << std::endl;
    }




    file.close();

    return 0;
}
#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool LoadCSV(const std::string& filename, PatientRecord& rec) {
    std::ifstream file; // reading file

    file.open(filename);

    if (!file) {
        std::cout << "Error: Unable to open file, terminating program.\n";
        return false;
    }

    std::string line;
    std::getline(file, line);
    int totalCounter = 0, skipCounter = 0, currentLine = 1;

    while (std::getline(file, line)) {
        totalCounter++;
        currentLine++;

        std::stringstream ss(line);
        std::string timestamp, joint, rom;

        std::getline(ss, timestamp, ',');
        std::getline(ss, joint, ',');
        std::getline(ss, rom);

        if (timestamp.empty()) {
            std::cout << "\nWarning: Line " << currentLine << ": Data missing timestamp value, skipping line.";
            skipCounter++;
            continue;
        }

        if (joint.empty()) {
            std::cout << "\nWarning: Line " << currentLine << ": Data missing joint value, skipping line.";
            skipCounter++;
            continue;
        }

        try {
            std::size_t pos;
            float val = std::stof(rom, &pos);

            if (rom.length() != pos) {
                std::cout << "\nWarning: Line " << currentLine << ": Invalid ROM value (extra characters), skipping line.";
                skipCounter++;
                continue;
            }

            rec.AddReading(MovementReading(timestamp, joint, val));

        }
        catch (const std::invalid_argument& e) {
            std::cout << "\nWarning: Line " << currentLine << ": Invalid ROM value (not a number), skipping line.";
            skipCounter++;
            continue;
        }
        catch (const std::out_of_range& e) {
            std::cout << "\nWarning: Line " << currentLine << ": ROM value outside the range of a float, skipping line.";
            skipCounter++;
            continue;
        }
    }

    std::cout << "\n\nTotal lines: " << totalCounter
        << "\nAmount of skipped lines: " << skipCounter << std::endl;

    file.close();

    return true;
}
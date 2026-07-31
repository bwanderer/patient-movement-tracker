#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

int StringToInt(const std::string& str, const int currentLine) {
    int num;

    try {
        num = std::stoi(str);
    }
    catch(...) {
        num = -1;
        std::cout << "\nERROR: string to int failure\n";
    }

    return num;
}

bool RangeCheck(const int num, const int max, const int min) {
    if (num > max || num < min)
        return false;
    else
        return true;
}

bool ErrorMessage(const int currentLine, const std::string& msg) {
    std::cout << "\nError: Line " << currentLine << ": Invalid " << msg << ", skipping line.\n";
    return false;
}

bool IsTimestampValid(const std::string& timestamp, const int currentLine) {

    if (timestamp.empty()) {
        std::cout << "\nError: Line " << currentLine << ": Data missing timestamp value, skipping line.\n";
        return false;
    }
    
    if (timestamp.length() != 19 ||
        timestamp[2] != '/' ||
        timestamp[5] != '/' ||
        timestamp[10] != ' ' ||
        timestamp[13] != ':' ||
        timestamp[16] != ':') 
        {
            ErrorMessage(currentLine, "timestamp format");
            return false;
        }

    int monthNum = StringToInt(timestamp.substr(0, 2), currentLine);
    int dayNum = StringToInt(timestamp.substr(3, 2), currentLine);

    if (!(RangeCheck(monthNum, 12, 1))) {
        return ErrorMessage(currentLine, "range for month value");
    }
    
    if (monthNum == 2) {
        if (!(RangeCheck(dayNum, 29, 1)))
            return ErrorMessage(currentLine, "range for day value for months with max 29 days");
    }
    else if (monthNum == 9 || monthNum == 11 || monthNum == 4 || monthNum == 6) {
        if(!(RangeCheck(dayNum, 30, 1)))
            return ErrorMessage(currentLine, "range for day value for months with max 30 days");
    }
    else {
        if (!(RangeCheck(dayNum, 31, 1)))
            return ErrorMessage(currentLine, "range for day value for months with max 31 days");
    }

    int yearNum = StringToInt(timestamp.substr(6, 4), currentLine);
    if (!(RangeCheck(yearNum, 2100, 1900))) {
        return ErrorMessage(currentLine, "range for year value");
    }

    int hourNum = StringToInt(timestamp.substr(11, 2), currentLine);
    if (!(RangeCheck(hourNum, 23, 0))) {
        return ErrorMessage(currentLine, "range for hour value");
    }

    int minNum = StringToInt(timestamp.substr(14, 2), currentLine);
    if (!(RangeCheck(minNum, 59, 0))) {
        return ErrorMessage(currentLine, "range for minute value");
    }

    int secNum = StringToInt(timestamp.substr(17, 2), currentLine);
    if (!(RangeCheck(secNum, 59, 0))) {
        return ErrorMessage(currentLine, "range for seconds value");
    }

    return true;
}

bool LoadCSV(const std::string& filename, PatientRecord& rec) {
    std::ifstream file; // reading file

    file.open(filename);

    if (!file) {
        std::cout << "\nError: Unable to open file, terminating program.\n";
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
            std::cout << "\nError: Line " << currentLine << ": Data missing timestamp value, skipping line.\n";
            skipCounter++;
            continue;
        }

        if (!(IsTimestampValid(timestamp, currentLine))) {
            skipCounter++;
            continue;
        }

        if (joint.empty()) {
            std::cout << "\nError: Line " << currentLine << ": Data missing joint value, skipping line.\n";
            skipCounter++;
            continue;
        }

        try {
            std::size_t pos;
            float val = std::stof(rom, &pos);

            if (rom.length() != pos) {
                std::cout << "\nError: Line " << currentLine << ": Invalid ROM value (extra characters), skipping line.\n";
                skipCounter++;
                continue;
            }

            rec.AddReading(MovementReading(timestamp, joint, val));

        }
        catch (const std::invalid_argument& e) {
            std::cout << "\nError: Line " << currentLine << ": Invalid ROM value (not a number), skipping line.\n";
            skipCounter++;
            continue;
        }
        catch (const std::out_of_range& e) {
            std::cout << "\nError: Line " << currentLine << ": ROM value outside the range of a float, skipping line.\n";
            skipCounter++;
            continue;
        }
    }

    std::cout << "\n\nTotal lines: " << totalCounter
        << "\nAmount of skipped lines: " << skipCounter << std::endl;

    file.close();

    return true;
}
#pragma once
#include <string>
#include "PatientRecord.h"

bool LoadCSV(const std::string& filename, PatientRecord& rec);
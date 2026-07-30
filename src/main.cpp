#include "Patient.h"
#include "PatientRecord.h"
#include "CSVLoader.h"


int main(){

    Patient p("Beatriz", 23, "PUI-1931", "Healthy");
    PatientRecord rec(p);

    if (!(LoadCSV("data/MovementData.csv", rec))) {
        return 1;
    }

    rec.PrintSummary();

    return 0;
}
#include <iostream>
#include "PatientRecord.h"

int main(){
    Patient p("Beatriz", 23, "190031", "Healthy");

    MovementReading data1("4:00", "Wrist", 20.0);
    MovementReading data2("4:30", "Wrist", 28.8);
    MovementReading data3("4:58", "Wrist", 90.9);

    PatientRecord rec(p);

    rec.GetPatient().Print();

    rec.PrintSummary();

    rec.AddReading(data1);

    rec.PrintSummary();

    rec.AddReading(data2);

    rec.AddReading(data3);

    rec.PrintSummary();



    return 0;
}
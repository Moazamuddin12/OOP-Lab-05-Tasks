#include <iostream>
#include <string>
using namespace std;

class MedicationEntry{
private:
    string drugName;
    string dose;
    string timeGiven;
public:
    MedicationEntry(string d, string ds, string t){
        drugName = d;
        dose = ds;
        timeGiven = t;
    }

    void display(){
        cout << "Drug: " << drugName << endl;
        cout << "Dose: " << dose << endl;
        cout << "Time Given: " << timeGiven << endl;
    }
};

class VitalSignsCheck{
private:
    float temperature;
    int heartRate;
    string timeChecked;
public:
    VitalSignsCheck(float temp, int hr, string t){
        temperature = temp;
        heartRate = hr;
        timeChecked = t;
    }

    void display(){
        cout << "Temperature: " << temperature << endl;
        cout << "Heart Rate: " << heartRate << endl;
        cout << "Time Checked: " << timeChecked << endl;
    }
};

class DiagnosisNote{
private:
    string noteText;
    string doctorName;
    string date;
public:
    DiagnosisNote(string n, string d, string dt){
        noteText = n;
        doctorName = d;
        date = dt;
    }

    void display(){
        cout << "Diagnosis: " << noteText << endl;
        cout << "Doctor: " << doctorName << endl;
        cout << "Date: " << date << endl;
    }
};

class PatientRecord{
private:
    int patientId;
    string patientName;
    string dob;

    MedicationEntry* med;
    VitalSignsCheck* vital;
    DiagnosisNote* diag;

public:
    PatientRecord(int id, string name, string d){
        patientId = id;
        patientName = name;
        dob = d;

        med = new MedicationEntry("Paracetamol", "500mg", "10:00 AM");
        vital = new VitalSignsCheck(98.6, 72, "10:05 AM");
        diag = new DiagnosisNote("Viral Fever", "Dr. Ahmed", "20-02-2026");
    }

    ~PatientRecord(){
        delete med;
        delete vital;
        delete diag;
    }

    void displayRecord(){
        cout << "Patient ID: " << patientId << endl;
        cout << "Name: " << patientName << endl;
        cout << "DOB: " << dob << endl;
        cout << endl;

        med->display();
        cout << endl;

        vital->display();
        cout << endl;

        diag->display();
    }
};

int main(){
    PatientRecord p1(101, "Lily Smith", "01-01-2000");
    p1.displayRecord();
    return 0;
}





#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
    string patientName;
    string disease;
    string doctorAssigned;
    bool admitted;

public:
    // Constructor
    Patient(string patientName, string disease, string doctorAssigned) {
        this->patientName = patientName;
        this->disease = disease;
        this->doctorAssigned = doctorAssigned;
        this->admitted = false; // Initialize as not admitted
    }

    // Method to admit the patient
    void admitPatient() {
        if (!admitted) {
            cout << patientName << " admitted for treatment of " << disease << " under Dr. " << doctorAssigned << "." << endl;
            admitted = true;
        } else {
            cout << patientName << " is already admitted." << endl;
        }
    }

    // Method to treat the patient
    void treatPatient() {
        if (admitted) {
            cout << "Treating " << patientName << " for " << disease << "." << endl;
        } else {
            cout << patientName << " is not admitted. Please admit the patient first." << endl;
        }
    }

    // Method to discharge the patient
    void dischargePatient() {
        if (admitted) {
            cout << patientName << " discharged." << endl;
            admitted = false;
        } else {
            cout << patientName << " is not admitted." << endl;
        }
    }
};

int main() {
    // Example usage of the Patient class
    Patient patient1("John Doe", "Fever", "Smith");

    // Admit the patient
    patient1.admitPatient();

    // Treat the patient
    patient1.treatPatient();

    // Discharge the patient
    patient1.dischargePatient();

    return 0;
}

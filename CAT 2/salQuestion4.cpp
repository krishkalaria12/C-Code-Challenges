#include<iostream>
using namespace std;

class Fit{
    protected:
        string exercise_type;
        int yoga_time, exercise_time;
    public:
        Fit() {
            exercise_type = "";
            yoga_time = 0;
            exercise_time = 0;
        }

        Fit(string type, int yt, int et) {
            exercise_type = type;
            yoga_time = yt;
            exercise_time = et;
        }

        void healthReport(){
            if (yoga_time >= 15 && exercise_time > 30 && exercise_type == "running")
            {
                cout << "Fitness report: You are healthy and fit!" << endl;
            }
            else if((yoga_time >= 10 || yoga_time < 15) && (exercise_time <= 30 || exercise_time > 10) && exercise_type == "running")
            {
                cout << "Fitness report: You are average" << endl;
            }
            else {
                cout << "Fitness report: You are not fit!" << endl;
            }
        }
};

class Yoga : private Fit {
    private:
        int meditation;
    public:
        Yoga() : meditation(0) {}

        Yoga(int time) : meditation(time) {}

        void MeditationNature(){
            if (yoga_time >=15 && (meditation >= 2 || meditation <= 3))
            {
                cout << "Meditation is good" << endl;
            }
            else if((yoga_time < 15 || yoga_time >= 7) && (meditation < 2 || meditation >= 1))
            {
                cout << "Meditation is average" << endl;
            }
            else{
                cout << "Meditation is bad" << endl;
            }
    }
};

int main() {
    int yt, et, mt;
    string type;
    
    cout << "Enter the yoga time: ";
    cin >> yt;
    cout << "Enter the exercise time: ";
    cin >> et;
    cout << "Enter the exercise type: ";
    cin >> type;
    cout << "Enter the meditation time: ";
    cin >> mt;

    Fit fit(type,yt,et);
    Yoga yoga(mt);

    fit.healthReport();
    yoga.MeditationNature();
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    string movieName;
    string director;
    int duration; // Duration in minutes
    bool playing;

public:
    // Constructor
    Movie(string movieName, string director, int duration) {
        this->movieName = movieName;
        this->director = director;
        this->duration = duration;
        this->playing = false; // Initialize as not playing
    }

    // Method to start the movie
    void startMovie() {
        if (!playing) {
            cout << "Starting movie: " << movieName << " directed by " << director << " (" << duration << " minutes)" << endl;
            playing = true;
        } else {
            cout << "Movie is already playing." << endl;
        }
    }

    // Method to pause the movie
    void pauseMovie() {
        if (playing) {
            cout << "Movie paused." << endl;
            playing = false;
        } else {
            cout << "Movie is not currently playing." << endl;
        }
    }

    // Method to stop the movie
    void stopMovie() {
        if (playing) {
            cout << "Stopping movie." << endl;
            playing = false;
        } else {
            cout << "Movie is not currently playing." << endl;
        }
    }
};

int main() {
    // Example usage of the Movie class
    Movie movie1("Inception", "Christopher Nolan", 148);

    // Start the movie
    movie1.startMovie();

    // Pause the movie
    movie1.pauseMovie();

    // Stop the movie
    movie1.stopMovie();

    return 0;
}

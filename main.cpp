// lab 32 | ali saeed | comsc-210
//ide used: vs code
//pretty easy assignment( if i did it right)

#include "Car.h"
#include <iostream>
#include <array>
#include <deque>

using namespace std;

const int INITIAL = 3;
const int PAYS = 46;
const int JOINS = 39;
const int SHIFTS = 15;
const int BOOTHS = 4;
const int TRIALS = 20;

void outputDeque(deque<Car>&);

int main() {
    srand(time(0));

    array<deque<Car>, BOOTHS> tollBooths;

    for (int i = 0; i < BOOTHS; i++) {
        int populate = rand() % 3 + 1;
        for (int j = 0; j < populate; j++) {
            tollBooths[i].push_back(Car());
        }
    }

    cout << "Initial queue:\n";

    //outputDeque(carDeque);

    //num of trials
    for (int i = 0; i < TRIALS; i++) {
        cout << "Time: " << i + 1 << endl;
        //go thru all toll booths
        for (int j = 0; j < BOOTHS; j++) {
            if (tollBooths[j].empty() && TRIALS != 19) {
                //if the lane is empty and it still has trials after
                //then add new car under 50/50 probability
                if (rand() % 100 < 50) {
                    Car new_addition = Car();
                    tollBooths[j].push_back(new_addition);
                    cout << "\tLane " << j + 1 << " Joined (Empty Queue): \n";
                    //fix output so i can print the car that 
                }
            }

            int rng = rand() % 100;
            //pays(leaves), joins, and shifts lanes at the end
            if (rng < PAYS) {
                cout << "Lane: " << j + 1 << " Paid: ";
                //print the car from the front
            }

        }
    }

    return 0;
}

void outputDeque(deque<Car>& carDeque) {
    if (carDeque.empty()) {
        cout << "\tEmpty\n";
    }
    for (Car& temp : carDeque) {
        cout << "\t";
        temp.print();
    }
    cout << "\n";
}
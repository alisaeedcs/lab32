// lab 33 | ali saeed | comsc-210
//ide used: vs code
//slight more difficult

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
const int ADDED_TO_EMPTY = 50;

void outputBooths(array<deque<Car>, BOOTHS>);

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

    outputBooths(tollBooths);

    //num of trials
    for (int i = 0; i < TRIALS; i++) {
        cout << "Time: " << i + 1 << endl;
        //go thru all toll booths
        for (int j = 0; j < BOOTHS; j++) {
            if (tollBooths[j].empty()) {
                //if the lane is empty and it still has trials after
                //then add new car under 50/50 probability
                if (rand() % 100 < ADDED_TO_EMPTY) {
                    Car new_addition = Car();
                    tollBooths[j].push_back(new_addition);
                    cout << "Lane " << j + 1 << " Joined (Empty Queue): ";
                    new_addition.print();
                }
                else {
                    cout << "Lane: " << j + 1 << " Remains Empty\n";
                }
            }
            else { // was not working because it was executing all of this when it should not ahve if it was empty
                int rng = rand() % 100;
                //pays(leaves), joins, and shifts lanes at the end
                //prob for paying and leaving
                if (rng < PAYS) {
                    cout << "Lane: " << j + 1 << " Paid: ";
                    tollBooths[j].front().print();
                    tollBooths[j].pop_front(); //eliminate from teh queue
                }
                //prob for joining, works since the first check
                else if (rng < PAYS + JOINS) {
                    Car new_car = Car();
                    tollBooths[j].push_back(new_car);
                    cout << "Lane: " << j + 1 << " Joined: ";
                    new_car.print();
                }
                //prob for shifting lanes
                else {
                    //make sure not empty
                    if (!tollBooths[j].empty()) {
                        Car lane_changer = tollBooths[j].back();
                        tollBooths[j].pop_back();

                        int new_lane = j;

                        //make sure its a different lane, dont wanna stay in the same
                        while (new_lane == j) {
                            new_lane = rand() % BOOTHS;
                        }

                        tollBooths[new_lane].push_back(lane_changer);
                        cout << "Lane " << j + 1 << " Switched: ";
                        lane_changer.print();
                        //doesnt need any more output (based on example output)
                    }
                }
            }

        }
        //output status end of each trial
        outputBooths(tollBooths);
    }

    return 0;
}

void outputBooths(array<deque<Car>, BOOTHS> tollBooths) {
    for (int i = 0; i < BOOTHS; i++) {
        cout << "\tLane " << i + 1 << " Queue:";
        if (tollBooths[i].empty()) {
            cout << " empty\n";
        }
        else {
            cout << endl;
            for (Car& temp : tollBooths[i]) {
                cout << "\t\t";
                temp.print();
    }
        }
    }
}
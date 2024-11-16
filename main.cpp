// lab 32 | ali saeed | comsc-210
//ide used: vs code
//pretty easy assignment( if i did it right)

#include "Car.h"
#include <iostream>
#include <deque>

using namespace std;

const int INITIAL = 2;

void outputDeque(deque<Car>&);

int main() {
    srand(time(0));

    deque<Car> carDeque;

    for (int i = 0; i < INITIAL; i++) {
        carDeque.push_back(Car());
    }
    cout << "Initial queue:\n";

    outputDeque(carDeque);

    int count = 0;
    while (!carDeque.empty()) {
        count++;

        int num = rand() % 100;
        
        //55 percent car leave
        if (num < 55) {
            cout << "Time " << count << " Operation: Car paid: ";
            carDeque.front().print();
            carDeque.pop_front();
        }
        // 45 percent is the other like if it is above or equal to 55
        else {
            Car addedCar = Car();
            carDeque.push_back(addedCar);
            cout << "Time " << count << " Operation: Joined lane: ";
            addedCar.print();
        }

        cout << "Queue:\n";
        outputDeque(carDeque);
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
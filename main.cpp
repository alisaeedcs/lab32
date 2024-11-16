#include "Car.h"
#include <iostream>
#include <deque>

using namespace std;

const int INITIAL = 2;

int main() {
    srand(time(0));

    deque<Car> carDeque;

    for (int i = 0; i < INITIAL; i++) {
        carDeque.push_back(Car());
    }

    cout << "Initial queue"


    return 0;
}

void outputDeque(const deque<Car>& carDeque) {

}
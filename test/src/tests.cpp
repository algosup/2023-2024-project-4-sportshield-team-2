#include <iostream>
using namespace std;

// test to check the ledPin
const int trueLedPin = 11;
const int falseLedPin = 10;

void allTests() {
    if (trueLedPin == 11) {
        cout << "The expected true led pin is 11" << endl;
    } else {
        cout << "The expected true led pin is not 11" << endl;
    }
    if (falseLedPin == 11){
        cout << "The expected false led pin is 11" << endl;
    }
    else {
        cout << "The expected false led pin is not 11" << endl;
    }
}

// main function, where we call the test function
int main() {
    allTests();
}
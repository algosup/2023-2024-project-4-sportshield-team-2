#include <iostream>
using namespace std;

// test to check the ledPin
bool ledPinTest(const int ledPin){
    if (ledPin == 11) { // expectation
        return true; // return true if corresponding to the expectation
    } else {
        return false; // return false if not corresponding to the expectation
    }
}


void allTests() {
    // the template should be reused each time we add another test
    cout << "[==========] Running unit tests" << endl; // visuals regarding tests and actions
    const int ledPin = 11; // you just have to change the variables to check multiple cases.
    cout << "[----------] Run in Linux server" << endl;  // *** COPY PASTE THE TEMPLATE FROM HERE ***
    cout << "[ RUN      ] Run from ledPinTest" << endl; // name of the test 
    cout << "[          ] " << endl; 
    cout << "[  Results ] Display the results" << endl; 
    if (ledPinTest(ledPin) == true){ // call the test and print the result depending on the expectation
        cout << "[  PASSED  ]" << endl;
    } 
    else{
        cout << "[  FAILED  ]" << endl;
    }
    // other test of the same function
    const int incorrectLedPin = 10;
    cout << "[----------]" << endl; 
    cout << "[ RUN      ] Run from ledPinTest" << endl; // name of the test 
    cout << "[          ] " << endl; 
    cout << "[  Results ] Display the results" << endl; 
    if (ledPinTest(incorrectLedPin) == true){ 
        cout << "[  PASSED  ]" << endl;
    } 
    else{
        cout << "[  FAILED  ]" << endl;
    }
    // here come the other tests regarding the same function
    cout << "[----------] 2 test from ledPinTest" << endl; // the number of tests from the function
    cout << "" << endl; // put this at the end of the test regarding a function (when you switch to another function)
    // here come other tests
    cout << "[==========] End unit tests" << endl; // visuals regarding tests and actions
}

// main function, where we call the test function
int main() {
    allTests();
}
//
// Created by adrig on 26/05/2026.
//

#include <iostream>
#include "mathlib/basic.h"
#include "mathlib/stats.h"
#include "mathlib/trig.h"


using namespace std;

void print_menu() {
    cout << "1 - Basic operations\n";
    cout << "2 - Statistics\n";
    cout << "3 - Trigonometry\n";
    cout << "q - Quit\n";
};

void print_menu_basic( char & string) {
    cout << "1 - Addition (+)\n";
    cout << "2 - Substraction (-)\n";
    cout << "3 - Multiplication (*)\n";
    cout << "4 - Division (/)\n";
    cout << "5 - Module (%)\n";
    char response {'a'};
    cin >> response;
    while (response != '1' && response != '2' && response != '3' && response != '4' && response != '5') {
        cout << "Input a valid operation (1-5)";
        cin >> response;
    }
};

void print_menu_stats( char & string) {
    cout << "1 - Mean \n";
    cout << "2 - Median \n";
    cout << "3 - Standard deviation \n";

    char response {'a'};
    cin >> response;
    while (response != '1' && response != '2' && response != '3' ) {
        cout << "Input a valid operation (1-3)";
        cin >> response;
    }
};

void print_menu_trig( char & string) {
    cout << "1 - Sin \n";
    cout << "2 - Cos \n";
    cout << "3 - Tan \n";

    char response {'a'};
    cin >> response;
    while (response != '1' && response != '2' && response != '3' ) {
        cout << "Input a valid operation (1-3)";
        cin >> response;
    }
};


void askForDouble(double & operator1, const char * str) {
    cout << "Input a value for " << str << ":\n";
    double response ;

    bool valid = false;
    do {
        cin >> response;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, try again\n";
        } else {
            valid = true;
            operator1 = response;
        }
    } while (!valid);
};

int askForInt(const char * str) {
    cout << "Input a value for " << str << ":\n";
    int response ;

    bool valid = false;
    do {
        cin >> response;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, try again\n";
        } else {
            valid = true;
        }
    } while (!valid);
    return response;
};

void askForDoubles(const int n, const char * str, double * values) {
    cout << "Input a value for " << str << ":\n";

    for (int i = 0; i < n; ++i) {
        string title = "Value " + std::to_string(i+1);
        askForDouble(values[i], title.c_str());
    }
};

int main() {


    // program variables
    char input {'a'};
    char operation {'a'};
    print_menu();
    cin >> input;

    while (input != 'q') {

        //basic operations
        if (input == '1') {
            print_menu_basic(operation);

            double operator1;
            double operator2;
            askForDouble(operator1, "Operator 1");
            askForDouble(operator2, "Operator 2");

            return 1;
        }
        // statistics
        else if (input == '2') {
            print_menu_stats(operation);

            int n = askForInt( "number of values for the operation");
            double values[n];
            askForDoubles(n, "values for statistic calculation", values);

            return 2;
        }
        //trigonometry
        else if (input == '3') {
            print_menu_trig(operation);
            return 3;
        }


        print_menu();
        cin >> input;
    }

    return 0;
}

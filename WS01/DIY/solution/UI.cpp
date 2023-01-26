#include <iostream>
#include <sstream>

using namespace std;

namespace sdds {

    pair<char, double> getGpaAndOperation() {
        string input;
        char operation;
        double gpa;
        bool valid = false;

        while (!valid) {
            cout << "? ";
            getline(cin, input);
            istringstream iss(input);
            iss >> operation;
            if (operation == '>' || operation == '~' || operation == '<' || operation == '!') {
                iss >> gpa;
                valid = true;
            } else {
                cout << "Syntax error: ? [Op][value]";
                // Wait for user to press [ENTER]
                cin.get();
                cout << endl;
                cout << "Op: [>,<,~,!]" << endl;
                cout << "value: GPA value" << endl;
                cout << endl;
            }
        }

        return make_pair(operation, gpa);
    }

}
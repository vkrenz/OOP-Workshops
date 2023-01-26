/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * 
 * Name: Victor Krenzel
 * Stu. Id: 102446176
 * Email: vkrenzel@myseneca.ca
 * Date: 01/25/2023
 * 
*/

#include <iostream>
#include <sstream>

using namespace std;

namespace sdds {

    pair<char, double> getGpaAndOperation() {
        string input;
        char operation;
        double gpa;
        bool valid = false;
        cout << endl << "Enter GPA Query..." << endl;
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
                cout << "Op: [>,<,~,!]" << endl;
                cout << "value: GPA value" << endl;
                cout << endl;
            }
        }

        return make_pair(operation, gpa);
    }

}
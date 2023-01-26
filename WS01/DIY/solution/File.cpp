/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * 
 * Name: Victor Krenzel
 * Stu. Id: 102446176
 * Email: vkrenzel@myseneca.ca
 * Date: 01/25/2023
 * 
*/

#include "File.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

namespace sdds {

    ifstream* openFile(string fileName) {
        ifstream* file = new ifstream(fileName);
        if (!file->is_open()) {
            return file;
            // cout << "Error: Could not open file: " << fileName << endl;
        }
        // cout << "Success: File: " << fileName << " opened successfully" << endl;
        return file;
    }

    vector<GPA> findGpa(ifstream& file, double gpa, char op) {
        vector<GPA> students;
        GPA student;
        string line;
        while (file >> line) {
            istringstream iss(line);
            char name[116] = "";
            int stno = 0;
            double studentGpa = 0.0;
            iss >> name >> stno >> studentGpa;
            if ((op == '<' && studentGpa < gpa) || (op == '>' && studentGpa > gpa) || (op == '~' && studentGpa == gpa)) {
                strcpy(student.name, name);
                student.stno = stno;
                student.gpa = studentGpa;
                students.push_back(student);
            } else if (op == '!') {
                char response = 'N';
                cout << "Exit the program? (Y)es/(N)o: ";
                cin >> response;
                if (response == 'Y' || response == 'y') {
                    cout << "Goodbye!";
                    exit(0);
                }
                
            }
        }
        return students;
    }

    void closeFile(ifstream& file) {
        file.close();
        cout << "File closed successfully." << endl; 
    }

}
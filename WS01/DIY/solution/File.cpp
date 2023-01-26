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
            cout << "Error: Could not open file: " << fileName << endl;
        }
        cout << "Success: File: " << fileName << " opened successfully" << endl;
        return file;
    }

    vector<GPA> findGpa(ifstream& file, double gpa, char op) {
        vector<GPA> students;
        GPA student;
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            char name[116];
            int stno;
            double studentGpa;
            iss >> name >> stno >> studentGpa;
            if ((op == '<' && studentGpa < gpa) || (op == '>' && studentGpa > gpa) || (op == '~' && studentGpa == gpa)) {
                strcpy(student.name, name);
                student.stno = stno;
                student.gpa = studentGpa;
                students.push_back(student);
            } else if (op == '!') {
                char response;
                cout << "Exit the program? (Y)es/(N)o: ";
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
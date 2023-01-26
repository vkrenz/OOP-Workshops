#include "GPAlist.h"
#include "File.h"
#include "UI.h"
#include <iostream>
#include <fstream>
#include <tuple>

using namespace std;

namespace sdds {

    bool gpaQuery(const char* filename) {
        ifstream* file = openFile(filename);
        if (file->is_open()) {
            int count = 0;
            char op;
            double gpa_value;
            auto result = getGpaAndOperation();
            op = get<0>(result);
            gpa_value = get<1>(result);
            vector<GPA> filtered_students = findGpa(file, gpa_value, op);
            // Print filtered_students
            for (auto& student : filtered_students) {
                count++;
                cout << "[" << count << "] " << student.stno << ": " << student.gpa << " " << "(" << student.name << ")" << endl;
            }

            closeFile(file);
            return true;
        }
        return false;
    }

}
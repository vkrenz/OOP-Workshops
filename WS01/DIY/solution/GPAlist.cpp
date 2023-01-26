/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * 
 * Name: Victor Krenzel
 * Stu. Id: 102446176
 * Email: vkrenzel@myseneca.ca
 * Date: 01/25/2023
 * 
*/

#include "GPAlist.h"
#include "File.h"
#include "UI.h"
#include <iostream>
#include <fstream>
#include <tuple>
#include <algorithm>

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
            vector<GPA> filtered_students = findGpa(*file, gpa_value, op);
            //sort vector by stno in ascending order
            sort(filtered_students.begin(), filtered_students.end(), [](const GPA& a, const GPA& b) {
                return a.stno < b.stno;
            });
            // Print filtered_students
            for (auto& student : filtered_students) {
                count++;
                cout << "[" << count << "] " << student.stno << ": " << student.gpa << " " << "(" << student.name << ")" << endl;
            }

            closeFile(*file);
            return true;
        }
        return false;
    }

}
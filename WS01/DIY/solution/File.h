/**
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 * 
 * Name: Victor Krenzel
 * Stu. Id: 102446176
 * Email: vkrenzel@myseneca.ca
 * Date: 01/25/2023
 * 
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "GPA.h"
#include <string>
#include <vector>

namespace sdds {

    std::ifstream* openFile(std::string fileName);
    std::vector<GPA> findGpa(std::ifstream& file, double gpa, char op);
    void closeFile(std::ifstream& file);

}

#endif
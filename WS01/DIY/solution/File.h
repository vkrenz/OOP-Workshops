#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "GPA.h"
#include <string>
#include <vector>

namespace sdds {

    std::ifstream* openFile(std::string fileName);
    std::vector<GPA> findGpa(std::ifstream& file, float gpa, char op);
    void closeFile(std::ifstream& file);

}

#endif
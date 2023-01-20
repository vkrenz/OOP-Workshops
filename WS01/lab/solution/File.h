#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include <ostream>

namespace sdds {

    FILE* fptr;

    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);

}

#endif
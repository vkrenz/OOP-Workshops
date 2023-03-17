/** 
* Name: Victor Krenzel
* Student Number: 102446176
* Student Email: vkrenzel@myseneca.ca
* Date: 03/10/2023
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
namespace sdds {
    const int MAX_FILE_NAME = 255;

    class Numbers {
        double* collection = nullptr;
        char file_name[MAX_FILE_NAME + 1];
        unsigned int collection_size = 0;
        bool is_original = false;
        bool is_added = false;
        void setEmpty();
        unsigned int countLines(const char* filename);
        void sort(double* collectionPtr, unsigned int size);
    public:
        Numbers(const char* filename);
        Numbers();
        Numbers(const Numbers& other);
        bool isEmpty() const;
        double average() const;
        double max() const;
        double min() const;
        void sort();
        /** 
        * Display Function
        * 
        * Inserts the file name, the Collection numbers and the largest, smallest and average values into the ostream reference argument in the following format:
        *   - if the object is empty, insert: "Empty list".
        *   - if the object is not empty
        *       - set the precision to print two digits after the decimal point.
        *       - if the Numbers object is not original insert "Copy Of "
        *       - insert the file name
        *       - New line
        *       - insert all the number in the Collection comma separated like the following example:
        *         1.99, 99.99, 5.12
        *       - New line
        *       - insert a line with 76 dashes (-).
        *       - insert the Collection information exactly as the following example:
        *         Total of 99 number(s), Largest: 99.99, Smallest: 99.99, 
        *         Average: 99.99
        *       - New line
        *       - insert a line with 76 assignment signs (=).
        *   - return the reference of the ostream.
        * */
        ostream& display(ostream& ostr) const;
        bool load();
        void save() const;
        void resize(size_t new_size);
        Numbers& operator=(const Numbers& other);
        size_t size() const;
        double operator[](size_t index) const;
        Numbers& operator+=(double value);
        ~Numbers();

        // Helper Functions
        friend ostream& operator<<(ostream&, const Numbers&);
        friend istream& operator>>(istream&, Numbers&);
        
   };

}
#endif // !SDDS_NUMBERS_H_


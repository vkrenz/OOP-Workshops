/**
* Name: Victor Krenzel
* Student Number: 102446176
* Student Email: vkrenzel@myseneca.ca
* Date: 03/10/2023
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "Numbers.h"
using namespace std;
namespace sdds {

    ostream& operator<<(ostream& os, const Numbers& obj) {
        obj.display(os);
        return os;
    }

    void Numbers::sort(double* nums, unsigned int size) {
        unsigned int i, j;
        double temp;
        for(i = size - 1; size && i > 0; i--) {
            for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
            }
        }
    }

    std::istream& operator>>(istream& is, Numbers& obj)
    {
        int i = obj.collection_size;
        obj.resize(obj.collection_size + 1);
        is >> obj.collection[i];
        obj.is_added = true;
        return is;
    }

   void Numbers::setEmpty() {
       collection = nullptr;
       file_name[0] = '\0';
       collection_size = 0;
       is_original = false;
       is_added = false;
   }

    unsigned int Numbers::countLines(const char* filename) {
        unsigned int lines = 0u;
        ifstream nums(filename);
        while(nums) {
            lines += (nums.get() == '\n');
        }
        return lines;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        if (filename != nullptr && filename[0] != '\0') {
            strcpy(file_name, filename);
        }
        load();
    }

    Numbers::Numbers() {
        setEmpty();
    }

    Numbers::Numbers(const Numbers& other) {
        setEmpty();
        if (other.file_name != nullptr) {
            strcpy(file_name, "Copy of ");
            strcat(file_name, other.file_name);
        }
        if (other.collection != nullptr) {
            collection = new double[other.collection_size];
            for (size_t i = 0; i < other.collection_size; i++) {
                collection[i] = other.collection[i];
            }
            collection_size = other.collection_size;
        }
    }

    void Numbers::resize(size_t new_size) {
        if (new_size == 0) {
            delete[] collection;
            collection = nullptr;
            collection_size = 0;
        }
        else {
            double* temp = new double[new_size];
            for (size_t i = 0; i < collection_size; i++) {
                temp[i] = collection[i];
            }
            delete[] collection;
            collection = temp;
            collection_size = new_size;
        }
    }

    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) {
            if (other.file_name != '\0') {
                strcpy(file_name, other.file_name);
            }
            resize(other.collection_size);
            if (other.collection != nullptr) {
                for (size_t i = 0; i < other.collection_size; i++) {
                    collection[i] = other.collection[i];
                }
            }
        }
        return *this;
    }

    Numbers& Numbers::operator+=(double value) {
        if (collection_size == 0) {
            collection = new double[1];
            collection[0] = value;
            collection_size = 1;
        }
        else {
            double* temp = new double[collection_size + 1];
            for (size_t i = 0; i < collection_size; i++) {
                temp[i] = collection[i];
            }
            temp[collection_size] = value;
            delete[] collection;
            collection = temp;
            collection_size++;
        }
        return *this;
    }

    size_t Numbers::size() const {
        return collection_size;
    }

    double Numbers::operator[](size_t index) const {
        return collection[index];
    }

    Numbers::~Numbers() {
        save();
        delete[] collection;
    }

    bool Numbers::isEmpty() const {
        return collection == nullptr;
    }

    double Numbers::min() const {
        double min_value = collection[0];
        for (unsigned int i = 1; i < collection_size; i++) {
            // If any value is less than `collection[0]` then update `min_value`
            if (collection[i] < min_value) {
                min_value = collection[i];
            }
        }

        return min_value;
    }

    void Numbers::sort() {
        is_original = false;
        sort(collection, collection_size);
    }

    double Numbers::average() const {
        double sum = 0;

        for (unsigned int i = 0; i < collection_size; i++) {
            sum += collection[i];
        }

        return sum / collection_size;
    }

    double Numbers::max() const {
        double max_value = collection[0];
        for (unsigned int i = 1; i < collection_size; i++) {
            // If any value is greather than `collection[0]` then update `max_value`
            if (collection[i] > max_value) {
                max_value = collection[i];
            }
        }

        return max_value;
    }

    ostream& Numbers::display(ostream& ostr = cout) const {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << std::fixed << std::setprecision(2);
            if (!is_original) {
                //ostr << "Copy Of ";
            }
            ostr << file_name << std::endl;
            for (size_t i = 0; i < size(); i++) {
                ostr << collection[i];
                if (i != size() - 1) {
                    ostr << ", ";
                }
            }
            ostr << std::endl;
            for (int i = 0; i < 76; i++) {
                ostr << "-";
            }
            ostr << std::endl;
            ostr << "Total of " << size() << " number(s), Largest: " << max() << ", Smallest: " << min() << ", Average: " << average() << std::endl;
            for (int i = 0; i < 76; i++) {
                ostr << "=";
            }
        }

        return ostr;
    }

    void Numbers::save() const {
        if (is_original || is_added) {
            ofstream file(file_name);
            file << fixed << setprecision(2);
            for (size_t i = 0; i < collection_size; i++) {
                file << collection[i] << '\n';
            }
        }
    }

   bool Numbers::load() {
       delete[] collection;
       int numLines = countLines(file_name);

       if (numLines > 0) {
           collection = new double[numLines];
           size_t numRead = 0;
           std::ifstream file(file_name);

           while (file && numRead < (size_t)numLines) {
               file >> collection[numRead++];
           }

           if (numRead != (size_t)numLines) {
               delete[] collection;
               collection = nullptr;
               collection_size = 0;
               is_original = false;
               return false;
           }

           collection_size = numRead;
           is_original = true;
           return true;
       }

       collection = nullptr;
       collection_size = 0;
       is_original = false;
       return false;
   }

}
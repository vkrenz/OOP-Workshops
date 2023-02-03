/**
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Victor Krenzel
Seneca Email: vkrenzel@myseneca.ca
Student Id: 102446176
Date: 02/01/2023
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // Read Functions

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    bool read(Customers& rec) {
        string user_name;
        cout << " Enter User name: ";
        read(rec.user_name, 21);


        if (strlen(rec.user_name) == 0) {
            return false;
        }

        // strCpy(rec.user_name, user_name.c_str());

        cout << " Enter likes_count: ";
        cin >> rec.likes_count;
        cout << " Enter retweets_count: ";
        cin >> rec.retweets_count;
        cout << " Enter replies_count: ";
        cin >> rec.replies_count;
        cout << " Enter share videos (y/n): ";
        cin >> rec.share_videos;

        return true;
    }

    // Add Customer Function

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        Customers* temp_ptr_rec = new Customers[t_rec.noOfRecords + 1];
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            temp_ptr_rec[i] = t_rec.ptr_rec[i];
        }

        temp_ptr_rec[t_rec.noOfRecords] = c_rec;

        delete[] t_rec.ptr_rec;
        t_rec.ptr_rec = temp_ptr_rec;
        t_rec.noOfRecords++;
    }

    // Display Functions

    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", ";
        cout << c_rec.likes_count << ", ";
        cout << c_rec.retweets_count << ", ";
        cout << c_rec.replies_count << ", ";
        cout << c_rec.share_videos << endl;
    }
    
    void display(const CustomersRecord& t_rec) {
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
            cout << endl;
        }
    }

    // EmptyRecord Functions
   
    void EmptyRecord(Customers &c) {
        strCpy(c.user_name, "");
        c.retweets_count = 0;
        c.likes_count = 0;
        c.replies_count = 0;
        c.share_videos = 'n';
    }

    void EmptyRecord(CustomersRecord &cr) {
        cr.ptr_rec = nullptr;
        cr.noOfRecords = 0;
    }

  }


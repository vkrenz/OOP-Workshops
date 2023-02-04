/** SOLUTION */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    // Function Implementations

    void Department::updateName(const char* newname) {
        // Check if the name provided exists and is not empty
        if (newname != nullptr && strlen(newname) > 0) {
            // Deallocate the previous department name
            delete[] name;
            // Dynamically allocate memory for the new name
            name = new char[strlen(newname) + 1];
            // Copy over the data
            strcpy(name, newname);
        }
    }

    

}
/**
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*
* Name: Victor Krenzel
* Seneca Email: vkrenzel@myseneca.ca
* Studnet Number: 102446176
* Date: 02/03/2023
*/

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

    void Department::updateBudget(double change) {
        // Update budget by adding a new change to it
        budget += change;
    }

    bool Department::addProject(Project& newproject) {
        // Calculate the total cost and the new total cost
        double total_cost = 0.0;
        if (num_of_projects > 0) {
            for (int i = 0; i < num_of_projects; i++) {
                total_cost += projects[i].m_cost;
            }
        }
        double new_total_cost = total_cost + newproject.m_cost;
        // Check if the new_total_cost doesnt not exceed the budget
        if (new_total_cost <= budget) {
            // Check the number of projects currently in progress
            if (num_of_projects == 0) {
                // If there are no projects currently in progress:
                // Create a new project and save the data inside it
                projects = new Project[1];
                strcpy(projects[0].m_topic, newproject.m_topic);
                projects[0].m_cost = newproject.m_cost;
                num_of_projects = 1;
                return true;
            } else {
                // If there are projects currently in progress:
                // Allocate a temp array of projects with new size = old size + 1
                Project* temp = new Project[num_of_projects + (long long)1];
                // Copy all projects from old array to the new one
                for (int i = 0; i < num_of_projects; i++) {
                    strcpy(temp[i].m_topic, projects[i].m_topic);
                    temp[i].m_cost = projects[i].m_cost;
                }
                // Add new data to the last position of the temp array
                strcpy(temp[num_of_projects].m_topic, newproject.m_topic);
                temp[num_of_projects].m_cost = newproject.m_cost;
                // Wipe out the old array
                delete[] projects;
                // set old array pointer to point to where temp points
                projects = temp;
                // Increase num_of_projects
                num_of_projects++;
                // Project added successfully
                return true;
            }
        }
        // new_total_cost exceeds budget
        return false;
    }

    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

    Project* Department::fetchProjects() const {
        return this->projects;
    }

    int Department::fetchNumProjects() const {
        return num_of_projects;
    }

    double Department::fetchBudget() const {
        return budget;
    }

    char* Department::fetchName() const {
        return name;
    }

    double Department::totalexpenses() {
        double total = 0;
        // Calculate the total expenses
        for (int i = 0; i < num_of_projects; i++) {
            total += projects->m_cost;
        }
        // Return the total expenses
        return total;
    }

    double Department::remainingBudget() {
        // Calculate and return the remaining budget of a department by subtracting the total expenses from the budget.
        return budget - totalexpenses();
    }

    void Department::clearDepartment() {
        // Deallocate memory for name and projects
        delete[] name;
        name = nullptr;
        delete[] projects;
        projects = nullptr;
        // Return Department to clean state
        num_of_projects = 0;
        budget = 0.0;
    }

}
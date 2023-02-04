/** SOLUTION */

#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here
	
	class Department {
        char* name;
        Project* project;
        int num_of_projects;
        double budget;
    public:
        // If the provided name is valid (exists and is not empty), this function will set the name of the department. If the department is already set, it will deallocate the name. It will create enough memory for the name of the department to match the new name and then copies the data of the new name. If the new name is not valid, the department's current name will not change.
        void updateName(const char* newname);
        // This function will update the budget of the department by adding a new change to it.
        void updateBudget(double change);
        /** 
         * This function will add a new project to the department as long as the total cost does not exceed the allocated budget. If the new project cost in addition to the total cost of the current project does not exceed the budget this function will add the new project to the department list of projects by doing the following steps:
         * - if there are no projects currently in progress:
         *      > creates a new Project and saves the data inside it.
         * - if there are projects currently in progress:
         *      > allocates a temp array of projects with new size = old size + 1.
         *      > copy all projects from the old array to the new one
         *      > add new data to the last position of the temp array
         *      > wipe out the old array
         *      > increase the number of the project by one
         *      > allocate projects with the new size
         *      > copy all projects from the temp array to projects
         *      > wipe out the temp array
        */
        bool addProject(Project& newproject);
        // This function will use functions updateName, addProject and updateBudget to set the name of the department, add a project to it and update its budget.
        void createDepartment(const char* newname, Project& newproject, double change);
        // This function will return the list of projects a department is currently working on.
        Project* fetchProjects() const;
        // This function will return the number of projects a department is currently working on.
        int fetchNumProjects() const;
        // This function will return the current budget of a department.
        double fetchBudget() const;
        // This function will return the name of a department.
        char* fetchName() const;
        // This function will calculate and return the expenses of a department. The total expenses of a department is the total cost of all its current projects.
        double totalexpenses();
        // This function will calculate and return the remaining budget of a department by subtracting the total expenses from the budget.
        double remainingBudget();
        // This function will clear all the dynamic memory allocation in a department.
        void clearDepartment();
    };
	
	
	
	//helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_
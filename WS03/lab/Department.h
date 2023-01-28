#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here
	
	
	
	
	
	//helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_
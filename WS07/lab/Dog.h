#ifndef SDDS_DOG_H
#define SDDS_DOG_H
#include "Pet.h"

using namespace std;
namespace sdds {

	class Dog : public Pet {
		int m_numWalks;
	public:
		Dog(const char* name, int age = 0);
		Dog& operator++();
		Dog& operator=(Dog& dog);
		friend ostream& operator<<(ostream& os, const Dog& dog);
	};

}

#endif
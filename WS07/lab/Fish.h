#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include <iostream>
#include "Pet.h"

using namespace std;
namespace sdds {

	class Fish : public Pet {
	public:
		Fish(const char* name, int age = 0);
		void feed();
		void reSpawn();
		Fish& operator++();
		Fish& operator=(const Fish& other);
		friend ostream& operator<<(ostream& os, Fish& fish);
	};

}

#endif
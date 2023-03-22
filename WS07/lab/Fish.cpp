#include <iostream>
#include "Fish.h"

using namespace std;
namespace sdds {

	Fish::Fish(const char* name, int age = 0) : Pet(name, age, getCostBase()) {

	}

	void Fish::feed() {

	}

	void Fish::reSpawn() {

	}

	Fish& Fish::operator++() {
		if (isAlive()) {
			// Invoke the operator on the base class
			Pet::operator++(1);
		}
		return *this;
	}

	Fish& Fish::operator=(const Fish& other){
		if (this != &other) {
			// Invoke the operator on the base class
			Pet::operator=(other);
			// Add cloning fee for a fish based on fee schedule
			double cloningFee = getCreate 
		}

		return *this;
	}

	ostream& operator<<(ostream& os, Fish& fish) {
		os << "** Generic Fish **";
		fish.outputData(os);
		return os;
	}
}
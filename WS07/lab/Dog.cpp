#include <iostream>
#include "Dog.h"

namespace sdds {

	Dog::Dog(const char* name, int age = 0) : Pet(name, age, getCostBase()) {
		m_numWalks = 0;
	}

	Dog& Dog::operator++() {
		if (isAlive()) {
			double healthDelta = 0;
			healthDelta += 0.15 * (getHugs() - 1);
			healthDelta += 0.10 * (getFeeds() - 2);
			healthDelta += 0.10 * (getGrooms() - 1);
			healthDelta += 0.20 * (m_numWalks - 2);
			
			setHealth(getHealth() + healthDelta);
			
			Pet::operator++(1);
		}

		return *this;
	}

	Dog& Dog::operator=(Dog& dog) {
		if (this != &dog) {
			// Invoke operator= of the base class
			// To copy over the common attributes
			Pet::operator=(dog);

			m_numWalks = dog.m_numWalks;
		}

		return *this;
	}

	ostream& operator<<(ostream& os, const Dog& dog) {
		os << "** Generic Dog **" << endl;
		os << "Walks: " << dog.m_numWalks << endl;
		dog.outputData(os);
		return os;
	}

}
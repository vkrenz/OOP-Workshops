/**
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*
* Name: Victor Krenzel
* Student Number: 102446176
* Student Email: vkrenzel@myseneca.ca
* Date: 2/17/2023
*/

#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H

#include <iostream>

using namespace std;

namespace sdds {
	// These weights are in Grams. (1000 Grams is one Kilo)
	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;

	class EggCarton {
		int size;
		int noOfEggs;
		bool jumboSize;
		void setBroken();
	public:
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		ostream& display(std::ostream& ostr) const;
		istream& read(std::istream& istr);
		operator bool() const;
		operator int() const;
		operator double() const;
		EggCarton& operator--();
		EggCarton operator--(int);
		EggCarton& operator++();
		EggCarton operator++(int);
		EggCarton& operator=(int value);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;
	};

	int operator+(int left, const EggCarton& right);
	ostream& operator<<(ostream& ostr, const EggCarton& right);
	istream& operator>>(istream& istr, EggCarton& right);
}

#endif

/** 
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*
* Name: Victor Krenzel
* Student Number: 102446176
* Student Email: vkrenzel@myseneca.ca
* Date: 2/17/2023
*/

#include <iostream>
#include "EggCarton.h"
using namespace std;

namespace sdds {

	void EggCarton::setBroken() {
		this->size = -1;
		this->noOfEggs = -1;
	}

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
		if ((size % 6 == 0) && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size) {
			this->size = size;
			this->noOfEggs = noOfEggs;
			this->jumboSize = jumboSize;
		}
		else {
			setBroken();
		}
    }

    ostream& EggCarton::display(std::ostream& ostr) const {
		if (*this) {
			int cartonWidth = this->size == 6 ? 3 : 6;
			cout << "[";
			for (int i = 0; i < this->size; i++) {
				ostr << ((i < this->noOfEggs) ? (this->jumboSize ? 'O' : 'o') : ' ');
				if ((i + 1) % cartonWidth == 0) {
					ostr << "]" << endl;
					if (i + 1 < this->size) cout << "[";
				}
				else {
					cout << "|";
				}
			}
		}
		else {
			ostr << "Broken Egg Carton!" << endl;
		}
		return ostr;
    }

	istream& EggCarton::read(std::istream& istr) {
		char type;
		istr >> type;

		this->jumboSize = (type == 'j');

		istr.ignore();
		istr >> this->size;
		istr.ignore();
		istr >> this->noOfEggs;

		if (!((this->size % 6 == 0) && this->size >= 6 && this->size <= 36 && this->noOfEggs >= 0 && this->noOfEggs <= this->size)) {
			setBroken();
		}

		return istr;
	}

	EggCarton::operator bool() const {
		return this->size > 0;
	}

	EggCarton::operator int() const
	{
		int r = -1;
		if (*this) {
			r = this->noOfEggs;
		}
		return r;
	}

	EggCarton::operator double() const {
		double r = -1.0;
		if (*this) {
			if (this->jumboSize) {
				r = ((double)this->noOfEggs * JumboEggWieght) / 1000.0;
			}
			else {
				r = (this->noOfEggs * RegularEggWieght) / 1000.0;
			}
		}
		return r;
	}

	EggCarton& EggCarton::operator--() {
		if (*this && this->noOfEggs > 0) {
			this->noOfEggs--;
		}
		return*this;
	}

	EggCarton EggCarton::operator--(int) {
		EggCarton temp = *this;
		operator--();
		return temp;
	}

	EggCarton& EggCarton::operator++() {
		if (*this) {
			this->noOfEggs++;
		}
		if (this->noOfEggs > this->size) {
			setBroken();
		}
		return *this;
	}

	EggCarton EggCarton::operator++(int) {
		EggCarton temp = *this;
		operator++();
		return temp;
	}

	EggCarton& EggCarton::operator=(int value) {
		this->noOfEggs = value;
		if (this->noOfEggs > this->size) {
			setBroken();
		}
		return *this;
	}

	EggCarton& EggCarton::operator+=(int value) {
		if (*this) {
			this->noOfEggs += value;
		}
		if (this->noOfEggs > this->size) {
			setBroken();
		}
		return *this;
	}

	EggCarton& EggCarton::operator+=(EggCarton& right) {
		if (*this) {
			// same as -> m_noOfEggs += int(right);
			this->noOfEggs += right.noOfEggs;
			if (this->noOfEggs > this->size) {
				right.noOfEggs = this->noOfEggs - this->size;
				this->noOfEggs = this->size;
			}
			else {
				right.noOfEggs = 0;
			}
		}
		return *this;
	}

	bool EggCarton::operator==(const EggCarton& right) const {
		bool ret = false;
		double diff = double(*this) - double(right);
		if (diff > -0.001 && diff < 0.001) {
			ret = true;
		}
		return ret;
	}

	int operator+(int left, const EggCarton& right) {
		if (right) {
			left += int(right);
		}
		return left;
	}

	ostream& operator<<(ostream& ostr, const EggCarton& right) {
		return right.display(ostr);
	}

	istream& operator>>(istream& istr, EggCarton& right) {
		return right.read(istr);
	}

}
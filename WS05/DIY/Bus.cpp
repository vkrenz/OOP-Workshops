/** 
* Name: Victor Krenzel
* Student Number: 102446176
* Student Email: vkrenzel@myseneca.ca
* Date: 02/23/2023
*/

#include <iostream>
#include <iomanip>
#include "Bus.h"

using namespace std;

namespace sdds {

	void Bus::setBroken() {
		this->numberOfSeats = -1;
		this->numberOfPassengers = -1;
	}

	Bus::Bus() {
		this->numberOfSeats = 20;
		this->numberOfPassengers = 0;
	}

	Bus::Bus(int Seats = 20) {
		if ((Seats % 2 == 0) && Seats >= 10 && Seats <= 40) {
			this->numberOfSeats = Seats;
			this->numberOfPassengers = 0;
		}
		else {
			setBroken();
		}
	}

	Bus::Bus(int Seats = 20, int Passengers = 0) {
		if ((Seats % 2 == 0) && Seats >= 10 && Seats <= 40 && Passengers >= 0 && Passengers <= Seats) {
			this->numberOfSeats = Seats;
			this->numberOfPassengers = Passengers;
		}
		else {
			setBroken();
		}
	}

	void drawBus(ostream& ostr, int seats, int psng) {
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;

		ostr << "Total Fare Price: " << setprecision(2) << fixed << psng * BusTicket << "\n";
	}

	ostream& Bus::display(std::ostream& ostr) const {
		if (*this) {
			drawBus(ostr, this->numberOfSeats, this->numberOfPassengers);
		}
		else {
			ostr << "Out of service!" << endl;
		}

		return ostr;
	}

	istream& Bus::read(std::istream& istr) {
		istr >> this->numberOfSeats;
		istr.ignore();
		istr >> this->numberOfPassengers;

		if (!((this->numberOfSeats % 2 == 0) && this->numberOfSeats >= 10 && this->numberOfSeats <= 40 && this->numberOfPassengers >= 0 && this->numberOfPassengers <= this->numberOfSeats)) {
			setBroken();
		}
		return istr;
	}

	Bus::operator bool() const {
		return this->numberOfPassengers >= 0 && this->numberOfPassengers <= this->numberOfSeats;
	}

	Bus::operator int() const {
		int r = -1;
		if (*this) {
			r = this->numberOfPassengers;
		}
		return r;
	}

	Bus::operator double() const {
		double r = 0;
		if (*this) {
			r = ((double)BusTicket * (double)numberOfPassengers);
		}
		return r;
	}

	Bus Bus::operator--() {
		if (this->numberOfPassengers <= 0) {
			this->numberOfPassengers = -1;
			Bus temp = *this;
			this->numberOfPassengers = 0;
			return temp;
		}
		if (*this) {
			this->numberOfPassengers--;
		}
		return *this;
	}

	Bus Bus::operator--(int){
		if (this->numberOfPassengers <= 0) {
			this->numberOfPassengers = -1;
			Bus temp = *this;
			this->numberOfPassengers = 0;
			return temp;
		}
		if (*this) {
			this->numberOfPassengers--;
		}
		return *this;
	}

	Bus Bus::operator++() {
		if (this->numberOfPassengers >= this->numberOfSeats) {
			this->numberOfPassengers = this->numberOfSeats + 1;
			Bus temp = *this;
			this->numberOfPassengers = this->numberOfSeats;
			return temp;
		}
		if (*this) {
			this->numberOfPassengers++;
		}
		return *this;
	}

	Bus Bus::operator++(int) {
		if (this->numberOfPassengers >= this->numberOfSeats) {
			this->numberOfPassengers = this->numberOfSeats + 1;
			Bus temp = *this;
			this->numberOfPassengers = this->numberOfSeats;
			return temp;
		}
		if (*this) {
			this->numberOfPassengers++;
		}
		return *this;
	}

	Bus& Bus::operator=(int value) {
		if (*this) {
			this->numberOfPassengers = value;
		}
		return *this;
	}

	Bus& Bus::operator+=(int value) {
		if (*this){
			if (this->numberOfSeats >= this->numberOfPassengers + value) {
				this->numberOfPassengers = this->numberOfPassengers + value;
			}
			else {
				this->numberOfPassengers = this->numberOfSeats;
			}
		}
		return *this;
	}

	Bus& Bus::operator+=(Bus& right) {
		if (*this) {
			if (this->numberOfSeats >= (this->numberOfPassengers + right.numberOfPassengers)) {
				this->numberOfPassengers = this->numberOfPassengers + right.numberOfPassengers;
			}
			else {
				int temp = this->numberOfPassengers + right.numberOfPassengers;
				this->numberOfPassengers = this->numberOfSeats;
				right.numberOfPassengers = temp - this->numberOfSeats;
			}
		}
		return *this;
	}

	bool Bus::operator==(const Bus& right) const {
		bool ret = false;
		double diff = double(*this) - double(right);
		if (diff > -0.001 && diff < 0.001) {
			ret = true;
		}
		return ret;
	}

	int operator+(int left, const Bus& right) {
		if (right) {
			left += int(right);
		}
		return left;
	}

	ostream& operator<<(ostream& ostr, const Bus& right)
	{
		return right.display(ostr);
	}

	istream& operator>>(istream& istr, Bus& right)
	{
		return right.read(istr);
	}

}
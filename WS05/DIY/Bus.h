/**
* Name: Victor Krenzel
* Student Number: 102446176
* Student Email: vkrenzel@myseneca.ca
* Date: 02/23/2023
*/

#ifndef SDDS_BUS_H
#define SDDS_BUS_H

using namespace std;

namespace sdds {

	const double BusTicket = 125.34;

	class Bus {
		int numberOfSeats;
		int numberOfPassengers;
		void setBroken();
	public:
		Bus();
		Bus(int);
		Bus(int, int);
		ostream& display(std::ostream& ostr) const;
		istream& read(std::istream& istr);
		operator bool() const;
		operator int() const;
		operator double() const;
		Bus operator--();
		Bus operator--(int);
		Bus operator++();
		Bus operator++(int);
		Bus& operator=(int value);
		Bus& operator+=(int value);
		Bus& operator+=(Bus& right);
		bool operator==(const Bus& right) const;
	};

	int operator+(int left, const Bus& right);
	ostream& operator<<(ostream& ostr, const Bus& right);
	istream& operator>>(istream& istr, Bus& right);
}

#endif
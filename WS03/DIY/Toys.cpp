/** 
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* 
* Name: Victor Krenzel
* Student Number: 102446176
* Student Email: vkrenzel@myseneca.ca
* 
* Date: 05/02/2023
* 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include "Toys.h"

using namespace std;

namespace sdds {

	void Toys::addToys(const char* tname, int sku, double price, int age) {
		// Check for validity
		if (isValid(tname, sku, price, age)) {
			// Set the received values to data members
			strcpy(m_tname, tname);
			m_sku = sku;
			m_price = price;
			m_age = age;
			m_onSale = false;
		} else {
			setEmpty();
		}
	}

	void Toys::isSale(bool sale) {
		m_onSale = sale;
	}

	bool Toys::isSale() const {
		return m_onSale;
	}

	void Toys::calSale() {
		// If on sale...
		// Reduce price by 20%
		if (m_onSale) m_price *= 0.8;
	}

	void Toys::display() const {
		if (isValid(m_tname, m_sku, m_price, m_age)) {
			cout << setfill(' ') << left << setw(15) << m_tname
				 << setfill(' ') << right << setw(10) << m_sku
				 << setfill(' ') << right << setw(6) << m_age
				 << setfill(' ') << right << setw(12) << fixed << setprecision(2) << m_price;
			m_onSale ? cout << right << setw(11) << "On Sale " : cout << "        ";
			cout << endl;
		} else {
			cout << "Invalid Toy" << endl;
		}
	}

	int Toys::getSku() const {
		return m_sku;
	}

	bool Toys::isValid(const char* tname, int sku, double price, int age) const {
		if (tname == nullptr || age <= 0 || price <= 0 || strlen(tname) < 3) {
			return false;
		}

		if (to_string(sku).length() != 8) {
			return false;
		}

		return true;
	}

	void Toys::setEmpty() {
		m_tname[0] = '\0';
		m_sku = 0;
		m_price = 0.0;
		m_age = 0;
		m_onSale = false;
	}

}
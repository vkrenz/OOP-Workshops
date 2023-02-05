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
#include <string.h>
#include <iomanip>
#include "Store.h"

using namespace std;

namespace sdds {

	void Store::setStore(const char* sName, int no) {
		if (sName == nullptr || no < 0 || no > MAX_NUM_TOYS) {
			// Invalid values...
			// Set the values to an empty state
			m_sName[0] = '\0';
			m_noOfToys = 0;
			m_addToys = 0;
		} else {
			// Set the store name and the number of toys that could be added to the store
			strncpy(m_sName, sName, MAX_SNAME - 1);
			m_sName[MAX_SNAME - 1] = '\0';
			m_noOfToys = no;
			m_addToys = 0;
		}
	}

	void Store::setToys(const char* tname, int sku, double price, int age) {
		if (m_noOfToys < MAX_NUM_TOYS && m_addToys < m_noOfToys) {
			if (m_toy[m_addToys].isValid(tname, sku, price, age)) {
				m_toy[m_addToys].addToys(tname, sku, price, age);
				m_addToys++;
			}
		}
	}

	void Store::display()const {
		if (m_noOfToys <= 0) {
			cout << "Invalid Store" << endl;
			return;
		}
		cout << setfill('*') << setw(60) << "*" << endl;
		cout << m_sName << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
		cout << "list of the toys" << endl;
		cout << setfill(' ') << right << setw(30) << "SKU"
			 << setfill(' ') << right << setw(10) << "Age"
		     << setfill(' ') << right << setw(11) << "Price"
		     << setfill(' ') << right << setw(10) << "Sale"
			 << endl;
		for (int i = 0; i < m_noOfToys; i++) {
			cout << "Toy[" << i + 1 << "] :";
			m_toy[i].display();
		}
	}

	void Store::find(int sku) {
		for (auto& toy : m_toy) {
			if (toy.getSku() == sku) {
				if (!toy.isSale()) {
					toy.isSale(true);
					toy.calSale();
				}
			}
		}
	}

	void Store::setEmpty() {
		m_sName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
		for (auto &toy : m_toy) {
			toy.setEmpty();
		}
	}

}
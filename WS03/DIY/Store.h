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

#ifndef SDDS_STORE_H
#define SDDS_STORE H

#include "Toys.h"

namespace sdds {
	// The maximum number of toys that could be added. 
	const int MAX_NUM_TOYS = 10;
	// The maximum length of a store name 
	const int MAX_SNAME = 31;
	
	class Store {
		// Store name, up to MAX_SNAME size
		char m_sName[MAX_SNAME] = "";
		// No of toys
		int m_noOfToys = 0;
		// No of toys added
		int m_addToys = 0;
		// Statically array of toys with size MAX_NUM_TOYS
		Toys m_toy[MAX_NUM_TOYS];
	public:
		// This will set the store name and the number of toys that could be added to the store. For invalid value, it will set the values to an empty state.
		void setStore(const char* sName, int no);
		// This will add the toys one at a time to the m_toy array and will keep track of the number of toys added. Toys will be added until num of added toys is less than m_noOfToys
		void setToys(const char* tname, int sku, double price, int age);
		/** 
		* If a Store object is valid:
		*		a) prints "*" with width 60 and fill with "*", then print m_sName and a new line.
		*		b) prints "*" with width 60 and fill with "*", then prints "list of the toys" and a new line.
		*		c) prints "SKU" with width 30 and fill with empty spaces
		*		d) prints "Age" with width 10 and fill with empty spaces
		*		e) prints "Price" with width 11 and fill with empty spaces
		*		f) prints "Sale" with width 10 and fill with empty spaces then a new line
		*		g) prints all the toys information. For details see the sample output.
		* otherwise prints, "Invalid Store" then a new line. */
		void display()const;
		// This method will go through the arrays of toys. It will match the received SKU number with the stored toys' SKU number to find out if the toys are on sale or not. If the number matches then it will pass true to the appropriate Toys method. After that, it will call the calSale() of the toys class to know the sale value.
		void find(int sku);
		// set the store to an empty state
		void setEmpty();
	};
}

#endif

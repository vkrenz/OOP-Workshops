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

#ifndef SDDS_TOYS_H
#define SDDS_TOYS H

namespace sdds {
	// The maximum length of a Toy name
	const int MAX_TNAME = 31;

	class Toys {
		// Toy name, up to MAX_TNAME size
		char m_tname[MAX_TNAME] = "";
		// SKU number, maximum 8 digits long
		int m_sku = 0;
		// Toy price
		double m_price = 0.0;
		// Toy according to age group
		int m_age = 0;
		// Keep track, if toys are on sale or not
		bool m_onSale = false;
	public:
		// After checking the validity, this method will set the received values to the appropriate data members. Otherwise will be set to an empty state.
		void addToys(const char* tname, int sku, double price, int age);
		// It will assign the received value to the data member m_onSale.
		void isSale(bool sale);
		bool isSale() const;
		// It will decrease the toys price to 20 % then the original price.
		void calSale();
		/**
		* If a Toy object is valid:
		*		a) prints m_tname with width 15, left justified and filled with empty spaces.
		*		b) prints m_sku with width 10
		*		c) prints m_age with width 6
		*		d) prints m_price with width 12 and after the decimal point 2 digits.
		*		e) If the toy is on sale it will print "On Sale" with width 10. Otherwise, print empty spaces with width 8.
		* otherwise prints, "Invalid Toy". */
		void display() const;
		// Get the sku of a toy
		int getSku() const;
		// Check if member variables of a toy are valid
		bool isValid(const char* tname, int sku, double price, int age) const;
		// Set the toy to an empty state
		void setEmpty();
	};
}

/** 

CORRECT OUTPUT:

Printing invalid list of Toys
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
						   SKU       Age      Price      Sale
Toy[1] :Invalid Toy
Toy[2] :Invalid Toy

Printing valid list of Toys
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
						   SKU       Age      Price      Sale
Toy[1] :Racing Car       11223344     8       40.99
Toy[2] :Teddy Bear       33772346     6       25.99
Toy[3] :Airplane         44453466    16       60.99
Toy[4] :Doll             55887896     5       45.99
Toy[5] :Drone            99221388    18       90.99
Toy[6] :Lego             88224596    10       65.99

Searching for toys and printing the list with sale price
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
						   SKU       Age      Price      Sale
Toy[1] :Racing Car       11223344     8       40.99
Toy[2] :Teddy Bear       33772346     6       20.79   On Sale
Toy[3] :Airplane         44453466    16       60.99
Toy[4] :Doll             55887896     5       45.99
Toy[5] :Drone            99221388    18       72.79   On Sale
Toy[6] :Lego             88224596    10       52.79   On Sale

*/

#endif
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include "NameTag.h"

using namespace std;

namespace sdds {

	// Constructors & Destructor

	NameTag::NameTag() {
		name = new char[1];
		name[0] = '\0';
		ext = -1;
		noExt = true;
	}

	NameTag::NameTag(const char* name) {
		if (name == nullptr) {
			this->name = new char[1];
			this->name[0] = '\0';
		}
		else {
			this->name = new char[MAX_NAME_LEN + 1];
			strncpy(this->name, name, MAX_NAME_LEN);
			this->name[MAX_NAME_LEN] = '\0';
		}
		ext = -1;
		noExt = true;
	}

	NameTag::NameTag(const char* name, const int ext) {
		if (name == nullptr) {
			this->name = new char[1];
			this->name[0] = '\0';
		}
		else {
			this->name = new char[MAX_NAME_LEN + 1];
			strncpy(this->name, name, MAX_NAME_LEN);
			this->name[MAX_NAME_LEN] = '\0';
		}
		this->ext = isValidExt(ext) ? ext : -1;
		noExt = !ext ? true : false;
	}

	NameTag::~NameTag() {
		delete[] name;
	}

	// Member Functions

	// @return true if `name` isn't empty
	bool NameTag::isValidName(const char* name) const {
		if (name == nullptr || name[0] == '\0') return false;
		for (char c : string(name)) {
			if (!isalpha(c)) return false;
		}
		return true;
	}

	// @returns true if: `ext` is 5 numbers long.
	bool NameTag::isValidExt(const int ext) const {
		return ((ext >= 10000 && ext <= 99999) || noExt);
	}
	
	/** 
	* Here are couple of examples:
	
	(Name: "Fred Soley", extension 12345):

	1. +----------------------+
	2. |                      |
	3. | Fred Soley           |
	4. |                      |
	5. | Extension: 12345     |
	6. |                      |
	7. +----------------------+

	(Name: "David Wright Mason Gilmour Waters Rogers Nick", extension not available):

	1. +------------------------------------------+
	2. |                                          |
	3. | David Wright Mason Gilmour Waters Rogers |
	4. |                                          |
	5. | Extension: N/A                           |
	6. |                                          |
	7. +------------------------------------------+

	If the data provided are invalid, (name being null or extensions being more or less than 5 digits) the printout will be:

	"EMPTY NAMETAG!"
	*/
	ostream& NameTag::print() const {
		if (this->name == nullptr || this->name[0] == '\0') {
			cout << "EMPTY NAMETAG!" << endl;
			return cout;
		}

		if (!isValidExt(this->ext)) {
			cout << "EMPTY NAMETAG!" << endl;
			return cout;
		}

		string nameStr(this->name, MAX_NAME_LEN + 1);

		const int NAME_LEN = nameStr.length();
		// Field Widths
		const int MAX_FIELD_LEN = 40;
		const int MIN_FIELD_LEN = 20;
		const int FIELD_WIDTH = NAME_LEN < MIN_FIELD_LEN ? MIN_FIELD_LEN : (NAME_LEN > MAX_FIELD_LEN ? MAX_FIELD_LEN : NAME_LEN);
		// Box Widths
		const int BOX_WIDTH = FIELD_WIDTH + 2;

		// Print first line
		cout << "+";
		for (int i = 0; i < BOX_WIDTH; i++) {
			cout << "-";
		}
		cout << "+" << endl;

		// Print second line
		cout << "|";
		for (int i = 0; i < BOX_WIDTH; i++) {
			cout << " ";
		}
		cout << "|" << endl;

		// Print third line
		cout << "| ";
		cout << setw(BOX_WIDTH - (long long)2) << left << setfill(' ');
		cout << this->name;
		cout << " |" << endl;

		// Print fourth line
		cout << "|";
		for (int i = 0; i < BOX_WIDTH; i++) {
			cout << " ";
		}
		cout << "|" << endl;

		// Print fifth line
		cout << "| ";
		if (isValidExt(this->ext)) {
			if (!this->noExt) {
				cout << setw(BOX_WIDTH - (long long)11) << left << setfill(' ') << "Extension: ";
				cout << setw(10) << left << this->ext;
			}
			else {
				cout << setw(BOX_WIDTH - 1) << left << setfill(' ') << "Extension: N/A";
			}
			cout << "|" << endl;
		}

		// Print sixth line
		cout << "|";
		for (int i = 0; i < BOX_WIDTH; i++) {
			cout << " ";
		}
		cout << "|" << endl;
		
		// Print seventh line
		cout << "+";
		for (int i = 0; i < BOX_WIDTH; i++) {
			cout << "-";
		}
		cout << "+" << endl;

		cout.clear();
		return cout;
	}

	/**
		do {
			cout << "Only (Y) or (N) are acceptable, try agin: ";
			cin >> choice;
			choice = tolower(choice);
		} while (choice != 'y' && choice != 'n');
	*/

	// A function called read that receives the name and then the extension number from consoleand returns the reference of the current object(NameTag&).
	// Read function should read the name up to the maximum of 40 characters and ignore the rest and then set the name of the NameTag to the entered name.
	// (This may overwrite an already existing name in the NameTag)
	// Then it should give an option to the user to enter the extension number or not.If the user chooses to enter the extension it should enforce the user to enter a 5 digit integer and if user does not comply, it should print one of the following messages based on the type of the error :
	// Bad integer value, try again:
	// Invalid value [10000<=value<=99999]: 
	NameTag& NameTag::read() {
		this->name = new char[MAX_NAME_LEN + 1];
		cout << "Please enter the name: ";

		for (int i = 0; i < MAX_NAME_LEN; i++) {
			char c = cin.get();
			if (c == '\n') {
				this->name[i] = '\0';
				break;
			}
			this->name[i] = c;
			if (i == MAX_NAME_LEN - 1) {
				if (cin.peek() != '\n') {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
		}

		char choice = '\0';
		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		
		while (true) {
			cin.get(choice);
			choice = tolower(choice);
			if (choice == 'y' || choice == 'n') {
				break;
			}
			else {
				cout << "Only (Y) or (N) are acceptable, try agin: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		if (choice == 'y') {
			int ext = -1;
			bool validExt = false;
			cout << "Please enter a 5 digit phone extension: ";
			while (!validExt) {
				if (!(cin >> ext)) {
					cout << "Bad integer value, try again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (!isValidExt(ext)) {
					cout << "Invalid value [10000<=value<=99999]: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					noExt = false;
					this->ext = ext;
					validExt = true;
				}
			}
		}
		else {
			this->ext = -1;
			noExt = true;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return *this;
	}
}
#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H

#include <iostream>

namespace sdds {
	const int MAX_NAME_LEN = 40;

	class NameTag {
		char *name = '\0';
		int ext = -1;
		bool noExt = false;
	public:
		NameTag();
		NameTag(const char* name);
		NameTag(const char* name, const int ext);
		~NameTag();
		bool isValidName(const char* name) const;
		bool isValidExt(int ext) const;
		std::ostream& print() const;
		NameTag& read();
	};

}

#endif

#include <iostream>
#include "Media.h"
using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& os, const sdds::Media& media) {
		return media.play(os);
	}

	std::istream& operator>>(std::istream& is, sdds::Media& media) {
		media.load(is);
		return is;
	}

}
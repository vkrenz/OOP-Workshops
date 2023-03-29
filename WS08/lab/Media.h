#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>
namespace sdds {

	class Media {
	public:
		virtual ~Media() {};
		virtual void load(std::istream& is) = 0;
		virtual std::ostream& play(std::ostream& os) const = 0;
	};

	// Helper Functions
	std::ostream& operator<<(std::ostream& os, const sdds::Media& media);
	std::istream& operator>>(std::istream& is, sdds::Media& media);
}


#endif // !SDDS_MEDIA_H

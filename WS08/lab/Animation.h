#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include <istream>
#include "Video.h"

namespace sdds {

	class Animation : public Video {
		int m_dimension;
	public:
		Animation();
		Animation(int length, int dimension);
		void load(istream& ist);
		void play() const;
		bool empty() const;
		void setEmpty();
	};

}

#endif // !SDDS_ANIMATION_H

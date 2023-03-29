#include <iostream>
#include "Animation.h"

using namespace std;

namespace sdds {

	Animation::Animation() : Video(), m_dimension(0) {}

	Animation::Animation(int length, int dimension) : Video(length), m_dimension(dimension) {
		if (m_dimension != 2 && m_dimension != 3) {
			Animation::setEmpty();
		}
	}

	void Animation::load(istream& ist) {
		Video::load(ist);
		ist >> m_dimension;
		ist.ignore(numeric_limits<streamsize>::max(), '\n');

		if (m_dimension != 2 && m_dimension != 3) {
			Video::setEmpty();
		}
	}

	void Animation::play() const {
		if (!empty()) {
			cout << "Animation is in " << m_dimension << "-D" << endl;
			cout << "Video Length = " << get() << endl;
		}
	}

	bool Animation::empty() const{
		return Video::empty() || m_dimension == 0;
	}

	void Animation::setEmpty() {
		m_dimension = 0;
		Video::setEmpty();
	}

}
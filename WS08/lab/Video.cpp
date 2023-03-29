#include <iostream>
#include "Video.h"

using namespace std;

namespace sdds {

	int Video::get() const {
		return m_length;
	}

	Video::Video() : m_length{ 0 } {}

	Video::Video(int length) {
		if (length < 0) {
			m_length = 0;
		}
		else {
			m_length = length;
		}
	}

	bool Video::empty() const {
		return m_length <= 0;
	}

	void Video::setEmpty() {
		m_length = 0;
	}

	Video::~Video() {}

}
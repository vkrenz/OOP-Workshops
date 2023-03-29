#include <iostream>
#include <cstring>
#include "VRVideo.h"

using namespace std;

namespace sdds {

	VRVideo::VRVideo() : Video(), m_equipment(nullptr) {}

	VRVideo::VRVideo(const char* filename, const char* equipment) : Video(filename, nullptr), m_equipment(0) {
		if (equipment != nullptr && strlen(equipment) > 0) {
			m_equipment = new char[strlen(equipment) + 1];
			strcpy(m_equipment, equipment);
		}

		if (!empty()) {
			if (m_equipment == nullptr || strlen(m_equipment) == 0) {
				delete[] equipment;
				m_equipment = nullptr;
				empty();
			}
		}
	}

	VRVideo::~VRVideo() {
		delete[] m_equipment;
		m_equipment = nullptr;
	}

	void VRVideo::load(std::istream& is) {
		Video::load(is);
		char delimiter;
		is >> delimiter;
		if (delimiter == ',') {
			delete[] m_equipment;
			m_equipment = nullptr;
			is.getline(nullptr, 0, '\n');
			char* equipment = new char[1000];
			is.getline(equipment, 1000, '\n');
			if (strlen(equipment) > 0) {
				m_equipment = new char[strlen(equipment) + 1];
				strcpy(m_equipment, equipment);
			}
			delete[] equipment;
		}
		else {
			is.setstate(ios::failbit);
		}
	}

	ostream& VRVideo::play(ostream& os) const {
		if (!empty()) {
			os << "VR";
			if (m_equipment != nullptr && strlen(m_equipment) > 0) {
				os << " (" << m_equipment << ")";
			}
			os << ": ";
			play(os);
		}
		return os;
	}
		
}
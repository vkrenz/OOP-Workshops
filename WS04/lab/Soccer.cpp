/**

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Victor Krenzel
Student Number: 102446176
Student Email: vkrenzel@myseneca.ca
Date: 02/10/2023

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "Soccer.h"

using namespace std;

namespace sdds {

	void SoccerTeam::setTeam(const SoccerTeam& team) {
		if (isValid(team.m_teamName, team.m_fines, team.m_noFouls)) {
			setName(team.m_teamName);
			setFouls(team.m_noFouls);
			setFine(team.m_fines, team.m_noFouls);
		}
	}

	void SoccerTeam::setName(const char* tname) {
		int len = strlen(tname);
		if (tname != nullptr && len <= 40) {
			strncpy(m_teamName, tname, len);
			m_teamName[len] = '\0';
		} else {
			m_teamName[0] = '\0';
		}
	}

	void SoccerTeam::setFouls(int noFouls) {
		if (noFouls >= 0) {
			m_noFouls = noFouls;
		}
	}

	void SoccerTeam::setFine(double fines, int foul) {
		if (fines >= 0.0 && foul >= 0) {
			m_fines = fines;
			m_noFouls = foul;
		} else {
			setEmpty();
		}
	}

	void SoccerTeam::setEmpty() {
		m_teamName[0] = '\0';
		m_noFouls = -1;
		m_fines = -1;
		m_goals = 0;
	}

	bool SoccerTeam::isEmpty() const {
		return m_teamName[0] != '\0' && m_fines > 0 && m_noFouls > 0;
	}

	void SoccerTeam::calFines() {
		m_fines *= 1.2;
	}

	int SoccerTeam::fouls() const {
		return m_noFouls;
	}

	SoccerTeam::SoccerTeam() : m_noFouls(0), m_fines(0), m_goals(0) {
		m_teamName[0] = '\0';
	}

	SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
		if (!tname) {
			m_teamName[0] = '\0';
		} else {
			strncpy(m_teamName, tname, 40);
			m_teamName[40] = '\0';
		}
		m_fines = fines;
		m_noFouls = foul;
		m_goals = 0;
	};

	ostream& SoccerTeam::display() const {
		ostream& os = cout;
		if (isValid(m_teamName, m_fines, m_noFouls)) {
			os << left << setw(30) << m_teamName
			   << right << fixed << setprecision(2) << setw(6) << m_fines
			   << setw(6) << m_noFouls
			   << setw(10) << m_goals;
			if (m_goals > 0) {
				os << "w\n";
			} else {
				os << " \n";
			}
		} else {
			os << "Invalid Team";
			return os;
		}
		// Return the reference of the ostream object.
		return os;
	}

	int SoccerTeam::isValid(const char* tname, double fines, int foul) const {
		return tname != nullptr && strlen(tname) != 0 && fines >= 0 && foul >= 0 && foul <= MAX_FOUL;
	}

}
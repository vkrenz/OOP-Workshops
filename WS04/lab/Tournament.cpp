/**

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Victor Krenzel
Student Number: 102446176
Student Email: vkrenzel@myseneca.ca
Date: 02/10/2023

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Tournament.h"

using namespace std;

namespace sdds {

	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		if (name != nullptr && noOfteam > 0 && soccer != nullptr) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_num = noOfteam;
			m_soccer = new SoccerTeam[m_num];
			for (int i = 0; i < m_num; i++) {
				m_soccer[i] = soccer[i];
			}
		}
	}

	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		if (isValid(name, noOfteam, soccer)) {
			strncpy(m_name, name, 40);
			m_name[40] = '\0';
			m_num = noOfteam;
			m_soccer = new SoccerTeam[m_num];
			for (int i = 0; i < m_num; i++) {
				m_soccer[i] = soccer[i];
			}
		} else {
			setEmpty();
		}
	}

	void Tournament::setEmpty() {
		delete[] m_name;
		m_name = nullptr;
		m_num = 0;
		delete[] m_soccer;
		m_soccer = nullptr;
	}

	bool Tournament::isEmpty() const {
		if (m_name == nullptr || m_soccer == nullptr || m_num <= 0) {
			return false;
		} else {
			return true;
		}
	}

	Tournament& Tournament::match(const SoccerTeam* ls) {
		// Check if `ls` is a valid pointer
		if (!ls) return *this;

		// Find all the valid teams in `ls`
		int numTeams = 0;
		while (ls[numTeams].isValid(ls[numTeams].m_teamName, ls[numTeams].m_fines, ls[numTeams].m_noFouls)) numTeams++;

		// Loop through all of the teams in `ls`
		for (int i = 0; i < numTeams; i++) {
			if (ls[i].fouls() < ls[i + 1].fouls()) {
				m_soccer[i + 1].m_noFouls *= 2;
				m_soccer[i + 1].calFines();
				m_soccer[i].m_goals++;
				if (m_soccer[i + 1].fouls() > MAX_FOUL) {
					// cout << "MAX_FOUL EXCEEDED (2nd TEAM): " << m_soccer[i + 1].fouls() << endl;
					m_soccer[i + 1].setFouls(-1);
				}
			}
		}
		
		// Return a reference to the current object
		return *this;
	}

	ostream& Tournament::display() const {
		ostream& os = cout;
		if (!isValid(m_name, m_num, m_soccer)) {
			os << "Invalid Tournament";
			return os;
		}
		os << "Tournament name: " << m_name << '\n';
		os << "list of the teams\n";
		os << right << setw(45) << "Fines" << setw(10) << "Fouls" << setw(11) << "Goals\n";
		for (int i = 0; i < m_num; i++) {
			os << "Team[" << i + 1 << "] :";
			m_soccer[i].display();
		}
		return os;
	}

	int Tournament::isValid(const char* name, int noOfteam, const SoccerTeam* soccer) const {
		return name != nullptr && noOfteam > 0 && soccer != nullptr;
	}

	Tournament::~Tournament() {
		delete[] m_name;
		m_name = nullptr;
		m_num = 0;
		delete[] m_soccer;
		m_soccer = nullptr;
	}
}
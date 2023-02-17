/**

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Victor Krenzel
Student Number: 102446176
Student Email: vkrenzel@myseneca.ca
Date: 02/10/2023

*/

#ifndef SDDS_TOURNAMENT_H
#define SDDS_TOURNAMENT_H

#include "Soccer.h"

namespace sdds {

	class Tournament {
		// Points to a dynamically allocated Cstring
		char* m_name = nullptr;
		// Size of the dynamically allocated array of soccer team. It should be more then zero.
		int m_num = 0;
		// Pointer to the dynamically allocated array of soccerTeam
		SoccerTeam* m_soccer = nullptr;
	public:
		// Default Constructor
		Tournament() = default;
		// Constructor (3 arguments)
		Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		/** 
		* > First, it will check the validity of all the received arguments. Tournament name should be valid and non-empty Cstring. Number of teams should be greater than zero.
		* > It will set m_num to the corresponding argument value.
		* > Then it will dynamically allocate memory for tournament name in the tournament name pointer attribute and then copies the content of the tournament name argument into the newly allocated memory.
		* > It will dynamically allocate an array of soccer team pointed by m_soccer member variable. The length of this array will be m_num.
		* > Lastly, add all the teams to the dynamically allocated array of m_soccer.
		* > If any of the arguments are not valid it will set the Tournament to an empty state.
		*/
		void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		// Sets the Tournamnet object to an Empty State. Do this by setting the m_name and m_soccer to null and m_num to 0.
		void setEmpty();
		// Returns true if m_name and m_soccer is not null and m_num is grater than 0.
		bool isEmpty() const;
		/** 
		* This function will find out the winner between 2 soccer teams by having matches. It will loop through all the teams.
		*		- First it will check which team is having more no of fouls.
		*		- If first team is having less fouls then second team then, second team`s no of foul will increase by double and fine will be increased by 20%
		*		- First team`s goal will be increased by 1.
		*		- If seconds team`s no of foul exceed the MAX_FOUL then this team will become a invalid team. You can do this by setting the number to foul to an invalid value.
		*		- At the end it will return the reference of the current object.
		*/
		Tournament& match(const SoccerTeam* ls);
		/**
		* 1. If Tournament object is valid:
		*		- a) prints "Tournament name: " then tournament name
		*		- b) prints "list of the teams" after that a newline
		*		- c) prints "Fines" with width 45 and fill with empty spaces.
		*		- d) prints "Fouls" with width 10 and fill with empty spaces.
		*		- e) prints "Goals" with width 10 and fill with empty spaces.
		*		- f) prints all the soccer teams information. For details see the sample output.
		* 2. otherwise prints, "Invalid Tournament".
		* 3. At the end return the reference of the ostream object.
		*/
		std::ostream& display() const;
		// Check if Tournament object is valid
		int isValid(const char* name, int noOfteam, const SoccerTeam* soccer) const;
		// Destructor
		~Tournament();
	};

}

#endif
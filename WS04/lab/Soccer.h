/**

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Victor Krenzel
Student Number: 102446176
Student Email: vkrenzel@myseneca.ca
Date: 02/10/2023

*/

#ifndef SDDS_SOCCERTEAM_H
#define SDDS_SOCCERTEAM_H

namespace sdds {
	// Maximum number of fouls
	const int MAX_FOUL = 4;

	struct SoccerTeam {
		// A statically allocated Cstring with size 41. Remember, name could be maximum 40 characters long and 1 byte is for the null byte.
		char m_teamName[41];
		// Number of fouls, it can be zero or more but cannot be a negative number
		int m_noFouls;
		// It can be equal to and more than zero.
		double m_fines;
		// Can be zero or more
		int m_goals;
		// It will set the team name, fine and fouls of the team.
		void setTeam(const SoccerTeam& team);
		// If the received name pointer is valid and not null it will copy the received name to the data member m_teamName
		void setName(const char* tname);
		// This function will set the number of fouls
		void setFouls(int noFouls);
		// It will receive the information about fines and no of foul. After checking the validity it will set the values to the appropriate data members. Fine and foul should be grater than and equal to zero. Otherwise, it will set the soccerTeam object to an empty state.
		void setFine(double fines, int foul);
		// Sets the soccerTeam object to an Empty State. Do this by setting the m_teamName to an empty Cstring, m_noFoul and m_fines to a negative number and m_goals to 0.
		void setEmpty();
		// Returns true if m_teamName is not null, m_fines and m_noFouls is grater than 0.
		bool isEmpty() const;
		// If this function is called it will increases the fine by 20% of the old fine value.
		void calFines();
		// It will return the m_noFoul
		int fouls() const;
		// By default a soccerTeam is set to the empty state(as in setEmpty())
		SoccerTeam();
		// After checking the validity it will set the team`s name,fine and no of fouls to the appropriate data members or else it will set the team to the empty state. (reuse your setter fucntions)
		SoccerTeam(const char* tname, double fines, int foul);
		/**
		* 1. If a soccerTeam object is valid:
		*		a) prints m_teamName with width 30, left justified and fill with empty spaces.
		*		b) prints m_fines with width 6 and after the decimal point 2 digits.
		*		c) prints m_noFoul with width 6
		*		d) prints m_fines with width 6
		*		e) prints m_golas with width 10. If number of goals are greater than zero then it will print "w" besides the number.
		* 2. otherwise prints, "Invalid Team".
		* 3. At the end return the reference of the ostream object. */
		std::ostream& display() const;
		// Check if SoccerTeam object is valid
		int isValid(const char* tname, double fines, int foul) const;
	};
}

#endif

/** Correct Output 

-----------------------------------------------------------------
|> T1: Checking Constructors of Soccer Team
-----------------------------------------------------------------
1. Invalid Team
2. Invalid Team
3. Invalid Team
-----------------------------------------------------------------
|> T2: Checking Constructors of Tournament
-----------------------------------------------------------------
1. Invalid Tournament
2. Invalid Tournament
3. Invalid Tournament
-----------------------------------------------------------------
|> T3: Checking valid Tournament with valid Teams
-----------------------------------------------------------------
Tournament name: Soccer Tournament
list of the teams
										Fines     Fouls     Goals
Team[1] :Scarborough Soccer Team         0.00     0         0
Team[2] :North York Soccer Team        100.00     1         0


*****First match between two Teams*****
-----------------------------------------------------------------
|> T4:Updated list with the winner
-----------------------------------------------------------------
Tournament name: Soccer Tournament
list of the teams
										Fines     Fouls     Goals
Team[1] :Scarborough Soccer Team         0.00     0         1w
Team[2] :North York Soccer Team        120.00     2         0

*****Second match between two Teams*****
-----------------------------------------------------------------
|> T5:Updated list with the winner
-----------------------------------------------------------------
Tournament name: Soccer Tournament
list of the teams
										Fines     Fouls     Goals
Team[1] :Scarborough Soccer Team         0.00     0         2w
Team[2] :North York Soccer Team        144.00     4         0

*****Third match between two Teams*****
-----------------------------------------------------------------
|> T6:Updated list with the winner
-----------------------------------------------------------------
Tournament name: Soccer Tournament
list of the teams
										Fines     Fouls     Goals
Team[1] :Scarborough Soccer Team         0.00     0         3w
Team[2] :Invalid Team

*/

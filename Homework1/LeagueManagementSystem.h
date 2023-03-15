// done by Zeynep Su Uçan 22103044 Section 3

#ifndef LeaugeManagementSystem_h
#define LeaugeManagementSystem_h

#include <stdio.h>
#include <string>
#include "Team.h"

using namespace std;
class LeagueManagementSystem
{
private:
    Team *teamArray;
    int teamNum;

public:
    LeagueManagementSystem();
    ~LeagueManagementSystem();

    void addTeam(const string name, const int year);

    void removeTeam(const string name);

    void addPlayer(const string teamName, const string playerName,
                   const int jersey, const int salary);

    void removePlayer(const string teamName, const string playerName);

    void transferPlayer(const string playerName,
                        const string departTeamName, const string arriveTeamName);

    void showAllTeams() const;

    void showTeam(const string name) const;

    void showPlayer(const string name) const; 
};
#endif /* LeaugeManagementSystem_hpp */
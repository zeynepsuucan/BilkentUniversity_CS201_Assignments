// done by Zeynep Su Uçan 22103044 Section 3

#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Team.h"
#include "LeagueManagementSystem.h"

LeagueManagementSystem::LeagueManagementSystem()
{
    teamArray = nullptr;
    teamNum = 0;
}
LeagueManagementSystem::~LeagueManagementSystem()
{
    delete[] teamArray;
}

void LeagueManagementSystem::addTeam(const string name, const int year)
{
    for (int i = 0; i < teamNum; i++)
    {
        if (teamArray[i].getName() == name)
        {
            cout << "Cannot add team. Team " << name << " already exists." << endl;
            return;
        }
    }
    Team *resized = new Team[teamNum + 1];
    for (int i = 0; i < teamNum; i++)
    {
        resized[i] = Team(teamArray[i].getName(), teamArray[i].getYear());
    }
    for (int i = 0; i < teamNum; i++)
    {
        if (teamArray[i].getPlayerNum() != 0)
        {
            resized[i].playerArr = new Player[teamArray[i].getPlayerNum()];
            for (int j = 0; j < teamArray[i].getPlayerNum(); j++)
            {
                resized[i].playerArr[j] = Player(teamArray[i].playerArr[j].getName(), teamArray[i].playerArr[j].getJerseyNo(), teamArray[i].playerArr[j].getSalary());
                resized[i].playerNum++;
            }
        }
    }
    Team t1 = Team(name, year);
    resized[teamNum] = t1;
    delete[] teamArray;
    teamArray = resized;
    teamNum++;
    cout << "Added team " << name << endl;
}

void LeagueManagementSystem::removeTeam(const string name)
{
    int ind = -1;
    bool check = true;
    for (int i = 0; i < teamNum; i++)
    {
        if (teamArray[i].getName() == name)
        {
            ind = i;
        }
    }
    if (ind < 0)
    {
        cout << "Cannot remove team. Team " << name << " does not exist." << endl;
        check = false;
    }
    if(check){
    Team *resized2 = new Team[teamNum - 1];
    for (int i = 0; i < ind; i++)
    {
        resized2[i] = Team(teamArray[i].getName(), teamArray[i].getYear());
        if (teamArray[i].getPlayerNum() != 0)
        {
            resized2[i].playerArr = new Player[teamArray[i].getPlayerNum()];
            for (int j = 0; j < teamArray[i].getPlayerNum(); j++)
            {
                resized2[i].playerArr[j] = Player(teamArray[i].playerArr[j].getName(), teamArray[i].playerArr[j].getJerseyNo(), teamArray[i].playerArr[j].getSalary());
                resized2[i].playerNum++;
            }
        }
    }
    for (int i = ind; i < teamNum-1; i++)
    {
        resized2[i] = Team(teamArray[i + 1].getName(), teamArray[i + 1].getYear());
        if (teamArray[i + 1].getPlayerNum() != 0)
        {
            resized2[i].playerArr = new Player[teamArray[i + 1].getPlayerNum()];
            for (int j = 0; j < teamArray[i + 1].getPlayerNum(); j++)
            {
                resized2[i].playerArr[j] = Player(teamArray[i + 1].playerArr[j].getName(), teamArray[i + 1].playerArr[j].getJerseyNo(), teamArray[i + 1].playerArr[j].getSalary());
                resized2[i].playerNum++;
            }
        }
    }
    delete[] teamArray;
    teamArray = resized2;
    cout << "Removed team " << name << endl;
    teamNum--;
}
}

void LeagueManagementSystem::addPlayer(const string teamName, const string playerName, const int jersey, const int salary)
{
    int ind;
    bool check = false;
    for (int i = 0; i < teamNum; i++)
    {
        if (teamArray[i].getName() == teamName)
        {
            ind = i;
            check = true;
        }
    }
    if (!check)
    {
        cout << "Cannot add player. Team " << teamName << " does not exist." << endl;
    }
    else
    {
        teamArray[ind].addPlayerTeam(playerName, jersey, salary);
    }
}

void LeagueManagementSystem::removePlayer(const string teamName, const string playerName)
{
    int ind = 0;
    bool check = false;
    for (int i = 0; i < teamNum; i++)
    {
        if (teamArray[i].getName() == teamName)
        {
            ind = i;
            check = true;
        }
    }
    if (!check)
    {
        cout << "Cannot remove player. Team " << teamName << " does not exist." << endl;
    }
    else
    {
        teamArray[ind].removePlayerTeam(playerName);
    }
}

void LeagueManagementSystem::transferPlayer(const string playerName, const string departTeamName, const string arriveTeamName)
{
    bool checkDep = false;
    bool checkArr = false;
    int indDep = 0;
    int indArr = 0;
    for (int i = 0; i < teamNum; i++)
    {
        if (teamArray[i].getName() == departTeamName)
        {
            indDep = i;
            checkDep = true;
        }
        if (teamArray[i].getName() == arriveTeamName)
        {
            indArr = i;
            checkArr = true;
        }
    }
    if (!checkDep && checkArr)
    {
        cout << "Cannot transfer player. Team " << departTeamName << " does not exist." << endl;
    }
    else if (!checkArr && !checkDep)
    {
        cout << "Cannot transfer player. Team " << arriveTeamName << " does not exist." << endl;
    }
    else if (!checkArr && !checkDep)
    {
        cout << "Cannot transfer player. Neither the team " << arriveTeamName << " nor the team " << departTeamName << " exist." << endl;
    }
    else
    {
        int indinDep = 0;
        bool checkifEx = false;
        for (int i = 0; i < teamArray[indDep].getPlayerNum(); i++)
        {
            if (teamArray[indDep].getPlayer(i).getName() == playerName)
            {
                indinDep = i;
                checkifEx = true;
            }
        }
        if (!checkifEx)
        {
            cout << "Cannot transfer player. " << playerName << " does not exist." << endl;
        }

        else
        {
            bool checkifTransfarable = true;
            int jerseyNoPlayer = teamArray[indDep].getPlayer(indinDep).getJerseyNo();
            int salaryPlayer = teamArray[indDep].getPlayer(indinDep).getSalary();

            for (int i = 0; i < teamArray[indArr].getPlayerNum(); i++)
            {
                if (teamArray[indArr].getPlayer(i).getJerseyNo() == jerseyNoPlayer)
                {
                    checkifTransfarable = false;
                }
            }
            if (!checkifTransfarable)
            {
                cout << "Cannot transfer player. Jersey number " << jerseyNoPlayer << " already exists in team " << teamArray[indArr].getName() << endl;
            }
            else
            {
                teamArray[indDep].removetoTransfer(playerName);
                teamArray[indArr].addtoTransfer(playerName, jerseyNoPlayer, salaryPlayer);
                cout << "Transferred player " << playerName << " from team " << teamArray[indDep].getName() << " to team " << teamArray[indArr].getName() << endl;
            }
        }
    }
}

void LeagueManagementSystem::showAllTeams() const
{
    cout << "The teams in the League Management System are: " << endl;
    for (int i = 0; i < teamNum; i++)
    {
        int totalSalary = 0;
        for (int j = 0; j < teamArray[i].getPlayerNum(); j++)
        {
            totalSalary += teamArray[i].getPlayer(j).getSalary();
        }
        cout << teamArray[i].getName() << ", " << teamArray[i].getYear() << ", " << teamArray[i].getPlayerNum() << " players, " << totalSalary << "TL total salary" << endl;
    }
}

void LeagueManagementSystem::showTeam(const string name) const
{
    int ind = 0;
    bool check = false;
    for (int i = 0; i < teamNum; i++)
    {
        if (teamArray[i].getName() == name)
        {
            ind = i;
            check = true;
        }
    }
    if (!check)
    {
        cout << "Team " << name << " does not exist." << endl;
    }
    else
    {
        cout << "Team: " << endl;
        int totalSalary = 0;
        for (int j = 0; j < teamArray[ind].getPlayerNum(); j++)
        {
            totalSalary += teamArray[ind].getPlayer(j).getSalary();
        }
        cout << teamArray[ind].getName() << ", " << teamArray[ind].getYear() << ", " << teamArray[ind].getPlayerNum() << " players, " << totalSalary << "TL total salary" << endl;
        cout << "Players: " << endl;
        for (int i = 0; i < teamArray[ind].getPlayerNum(); i++)
        {
            cout << teamArray[ind].getPlayer(i).getName() << ", jersey " << teamArray[ind].getPlayer(i).getJerseyNo() << ", " << teamArray[ind].getPlayer(i).getSalary() << "TL salary" << endl;
        }
    }
}

void LeagueManagementSystem::showPlayer(const string name) const
{
    int teamInd = 0;
    int playerInd = 0;
    bool checkExis = false;
    for (int i = 0; i < teamNum; i++)
    {
        for (int j = 0; j < teamArray[i].getPlayerNum(); j++)
        {
            if (teamArray[i].getPlayer(j).getName() == name)
            {
                teamInd = i;
                playerInd = j;
                checkExis = true;
            }
        }
    }
    if (checkExis)
    {
        cout << teamArray[teamInd].getPlayer(playerInd).getName() << ", jersey " << teamArray[teamInd].getPlayer(playerInd).getJerseyNo() << ", " << teamArray[teamInd].getPlayer(playerInd).getSalary() << "TL salary" << endl;
        cout << "Plays in team " << teamArray[teamInd].getName() << endl;
    }
    else
    {
        cout << "Player " << name << " does not exist. " << endl;
    }
}
// The management system will allow to specify the name of a player and display detailed information about that particular player. This information includes the name of the player, the jersey number, salary, and the team the player is currently playing in. If the player does not exist, the system should display a warning message.

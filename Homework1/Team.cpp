// done by Zeynep Su Uçan 22103044 Section 3sec

#include <iostream>
using namespace std;
#include <string>
#include "Team.h"

Team::Team()
{
    this->nameTeam = "";
    this->year = 0;
    this->playerNum = 0;
    this->playerArr;
}

Team::Team(string name, int yearr)
{
    this->nameTeam = name;
    this->year = yearr;
    this->playerNum = 0;
    this->playerArr = nullptr;
}

Team::~Team()
{
   if (playerArr != nullptr)
        delete[] playerArr;
}

void Team::addPlayerTeam(const string namePlayer, const int jerseyNo, const int salary)
{
    for (int i = 0; i < playerNum; i++)
    {
        if (playerArr[i].getJerseyNo() == jerseyNo)
        {
            cout << "Cannot add player. Jersey number " << jerseyNo << " already exists in team " << nameTeam << endl;
            return;
        }
    }

    Player *resized = new Player[playerNum + 1];
    for (int i = 0; i < playerNum; i++)
    {
        resized[i] = playerArr[i];
    }
    delete[] playerArr;
    playerArr = resized;
    playerArr[playerNum] = Player(namePlayer, jerseyNo, salary);
    playerNum++;
    cout << "Added player " << namePlayer << " to team " << nameTeam << endl;
}

void Team::removePlayerTeam(const string namePlayer)
{
    int ind = -1;
    for (int i = 0; i < playerNum; i++)
    {
        if (playerArr[i].getName() == namePlayer)
        {
            ind = i;
        }
    }
    if (ind < 0)
    {
        cout << "Cannot remove player. Player " << namePlayer << " doesn't exist." << endl;
        return;
    }

    Player *resized2 = new Player[playerNum - 1];
    for (int i = 0; i < ind; i++)
    {
        resized2[i] = playerArr[i];
    }
    for (int i = ind; i < playerNum - 1; i++)
    {
        resized2[i] = playerArr[i + 1];
    }
    delete[] playerArr;
    playerArr = resized2;
    playerNum--;
    cout << "Removed player " << namePlayer << " from team " << nameTeam << endl;
}

void Team::removetoTransfer(const string namePlayer)
{

    int ind = 0;
    for (int i = 0; i < playerNum; i++)
    {
        if (playerArr[i].getName() == namePlayer)
        {
            ind = i;
        }
    }
    Player *resized2 = new Player[playerNum - 1];
    for (int i = 0; i < ind; i++)
    {
        resized2[i] = playerArr[i];
    }
    for (int i = ind; i < playerNum - 1; i++)
    {
        resized2[i] = playerArr[i + 1];
    }
    delete[] playerArr;
    playerArr = resized2;
    playerNum--;
}

void Team::addtoTransfer(const string namePlayer, const int jerseyNo, const int salary)
{

    Player *resized = new Player[playerNum + 1];
    for (int i = 0; i < playerNum; i++)
    {
        resized[i] = playerArr[i];
    }
    delete[] playerArr;
    playerArr = resized;
    playerArr[playerNum] = Player(namePlayer, jerseyNo, salary);
    playerNum++;
}
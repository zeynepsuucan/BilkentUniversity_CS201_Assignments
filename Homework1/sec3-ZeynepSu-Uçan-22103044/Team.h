// done by Zeynep Su Uçan 22103044 Section 3

#ifndef Team_h
#define Team_h

#include <iostream> 
using namespace std;
#include <string>
#include "Player.h"
#include <string> 

class Team{
private:
    string nameTeam;
    int year;

public:
    Player* playerArr = NULL;
    int playerNum;
    Team();
    Team(const string nameTeam, const int year);
    ~Team();
    string getName() const {return nameTeam;}
    int getYear() const {return year;}
    Player getPlayer(int no) {return playerArr[no];}
    int getPlayerNum() const {return playerNum;}
    void addPlayerTeam(const string namePlayer, const int jerseyNo, const int salary);
    void removePlayerTeam(const string namePlayer);
    void removetoTransfer(const string namePlayer);
    void addtoTransfer(const string namePlayer, const int jerseyNo, const int salary);
};

#endif /* Player_hpp */
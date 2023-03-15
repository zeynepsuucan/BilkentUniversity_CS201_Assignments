// done by Zeynep Su Uçan 22103044 Section 3

#ifndef Player_h
#define Player_h

#include <iostream> 
#include <stdio.h>
using namespace std;
#include <string>

class Player{
private:
    string namePlayer;
    int jerseyNo;
    int salary;
    
public:
    Player();
    Player(string namePlayer, int jerseyNo, int salary);
    Player(const Player& player);
    ~Player();
    void print();
    string getName() const {return namePlayer;}
    int getJerseyNo() const {return jerseyNo;}
    int getSalary() const {return salary;}
    
};

#endif 
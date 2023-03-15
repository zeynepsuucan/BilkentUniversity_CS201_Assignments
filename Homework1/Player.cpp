// done by Zeynep Su Uçan 22103044 Section 3

#include <iostream> 
using namespace std;
#include <string>
#include "Player.h"


    Player::Player(){
        this->namePlayer = "";
        this->jerseyNo = 0;
        this->salary = 0;
    }
    
    Player::Player(string name, int jersey, int salary){
        this->namePlayer = name;
        this->jerseyNo = jersey;
        this->salary = salary;
    }
    Player::Player(const Player& player){
        this->namePlayer=player.namePlayer;
        this->jerseyNo=player.jerseyNo;
        this->salary=player.salary;
    }


    Player::~Player(){
        
    }
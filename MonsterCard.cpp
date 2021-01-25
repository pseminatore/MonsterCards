#include "MonsterCard.h"
#include <string>



 MonsterCard::MonsterCard(){
     name = "empty";
    }

 MonsterCard::~MonsterCard(){
    }

        int MonsterCard::GetattackPoints() {
            return attackPoints;
        }

        void MonsterCard::SetattackPoints(int val) {
            attackPoints = val;
        }

        int MonsterCard::GetdefensePoints() {
            return defensePoints;
        }

        void MonsterCard:: SetdefensePoints(int val) {
            defensePoints = val;
        }

        string& MonsterCard:: Getname() {
            return name;
        }

        void MonsterCard:: Setname(const string& nameIn) {
            name = nameIn; 
        }

        string& MonsterCard:: Gettype() {
            return type;
        }

        void MonsterCard:: Settype(const string& typeIn) {
            type = typeIn;
        }
        void MonsterCard:: setAttackPosition(bool pos){
            attackPosition = pos;
        }
        bool MonsterCard:: getAttackPosition(){
            return attackPosition;
        }

#ifndef MONSTERCARD_H
#define MONSTERCARD_H
#include <string>

using namespace std;

class MonsterCard
{
    public:
        MonsterCard();
        virtual ~MonsterCard();

        int GetattackPoints();
        void SetattackPoints(int);
        int GetdefensePoints();
        void SetdefensePoints(int);
        string& Getname();
        void Setname(const string&);
        string& Gettype();
        void Settype(const string&);
        void setAttackPosition(bool);
        bool getAttackPosition();

protected:
        int attackPoints;
        int defensePoints;
        string name;
        string type;
        bool attackPosition;
};

#endif // MONSTERCARD_H

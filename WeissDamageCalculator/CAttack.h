#ifndef CATTACK_H
#define CATTACK_H
#include "CDeck.h"
#include <iostream>

class CAttack
{
    private:
        CDeck m_YourDeck;
        CDeck m_OppDeck;
        unsigned m_BaseDamage;
        char m_AttackType;
        int m_DamgeTaken;
        int m_DamageValue;
        int m_Canceled = -1;
        bool m_IsCancel = false;
        bool m_IsTriggert = false;
        bool m_IsTriggerT = false;
    public:
        ///Constructor
        CAttack();
        CAttack(CDeck YourDeck, CDeck OppDeck, unsigned BaseDamage, char AttackType);

        int ComputeRealDamage();
        int Hit();
        void DisplayAttackInfo();

        bool getIsCancel() const;
        void setBaseDamage(const unsigned &BaseDamage);
        void setAttackType(char AttackType);
        int getDamgeTaken() const;
        int getCanceled() const;
        bool getIsTriggert() const;
        bool getIsTriggerT() const;
        CDeck getYourDeck() const;
        CDeck getOppDeck() const;
};

#endif // CATTACK_H

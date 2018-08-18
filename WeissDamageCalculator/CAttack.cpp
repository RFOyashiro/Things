#include "CAttack.h"

bool CAttack::getIsCancel() const
{
    return m_IsCancel;
}

void CAttack::setBaseDamage(const unsigned &BaseDamage)
{
    m_BaseDamage = BaseDamage;
}

void CAttack::setAttackType(char AttackType)
{
    m_AttackType = AttackType;
}

int CAttack::getDamgeTaken() const
{
    return m_DamgeTaken;
}

int CAttack::getCanceled() const
{
    return m_Canceled;
}

bool CAttack::getIsTriggert() const
{
    return m_IsTriggert;
}

bool CAttack::getIsTriggerT() const
{
    return m_IsTriggerT;
}

CDeck CAttack::getYourDeck() const
{
    return m_YourDeck;
}

CDeck CAttack::getOppDeck() const
{
    return m_OppDeck;
}

CAttack::CAttack()
{

}

CAttack::CAttack(CDeck YourDeck, CDeck OppDeck, unsigned BaseDamage, char AttackType)
    : m_YourDeck (YourDeck), m_OppDeck (OppDeck), m_BaseDamage (BaseDamage), m_AttackType (AttackType) {}

int CAttack::ComputeRealDamage()
{
    CCard CardTrigger;
    char Trigger;
    switch (m_AttackType) {
        case 'B':
            m_DamageValue = m_BaseDamage;
            return m_DamageValue;
        case 'N':
            CardTrigger = m_YourDeck.Mill();
            Trigger = CardTrigger.getTrigger();
            switch (Trigger) {
                case 'N':
                    m_DamageValue = m_BaseDamage;
                    return m_DamageValue;
                case 't':
                    m_DamageValue = m_BaseDamage + 1;
                    m_IsTriggert = true;
                    return m_DamageValue;
                case 'T':
                    m_DamageValue = m_BaseDamage + 2;
                    m_IsTriggerT = true;
                    return m_DamageValue;
                default:
                    break;
            }
        default:
            return -1;
    }
    return -1;
}

int CAttack::Hit()
{
    ComputeRealDamage();
    m_DamgeTaken = m_DamageValue;
    unsigned Count = 0;
    CCard Damage;
    while ((m_Canceled == -1) && Count < m_DamageValue) {
        Count++;
        Damage = m_OppDeck.Mill();
        if (Damage.getType() == "C") {
            m_Canceled = Count;
            m_IsCancel = true;
            m_DamgeTaken = 0;
        }
    }
    return m_DamageValue;
}

void CAttack::DisplayAttackInfo()
{
    std::cout << "Attack for " << m_DamageValue << std::endl
              << ((m_Canceled != -1) ? "Cancel on " : "Taken") << ((m_Canceled != -1) ? std::to_string(m_Canceled) : "") << std::endl
              << std::endl;
}

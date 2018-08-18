#include "CCard.h"

unsigned CCard::getLevel() const
{
    return m_Level;
}

void CCard::setLevel(const unsigned &Level)
{
    m_Level = Level;
}

std::string CCard::getType() const
{
    return m_Type;
}

void CCard::setType(const std::string &Type)
{
    m_Type = Type;
}

char CCard::getTrigger() const
{
    return m_Trigger;
}

void CCard::setTrigger(const char &Trigger)
{
    m_Trigger = Trigger;
}

CCard::CCard()
{

}

CCard::CCard(unsigned Level, std::__cxx11::string Type, char Trigger)
    : m_Level (Level), m_Type (Type), m_Trigger (Trigger) {}

std::__cxx11::string CCard::ToString()
{
    std::string Str = "Level : " + m_Level;
    Str += "; Type : " + m_Type + "; Trigger " + m_Trigger;
    return Str;
}

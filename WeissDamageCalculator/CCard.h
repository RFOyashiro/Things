#ifndef CCARD_H
#define CCARD_H
#include <string>

class CCard
{
    private:
        unsigned m_Level;
        std::string m_Type;
        char m_Trigger;
    public:
        ///Constructors
        CCard();
        CCard(unsigned Level, std::string Type, char Trigger);

        ///Methods
        std::string ToString();

        ///Getter
        unsigned getLevel() const;
        std::string getType() const;
        char getTrigger() const;

        ///Setter
        void setLevel(const unsigned &Level);
        void setType(const std::string &Type);
        void setTrigger(const char &Trigger);
};

#endif // CCARD_H

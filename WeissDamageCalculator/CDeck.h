#ifndef CDECK_H
#define CDECK_H
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "CCard.h"


class CDeck
{
    private:
        std::vector <CCard> m_Deck;
    public:
        ///Constructor
        CDeck();
        CDeck(unsigned Level0, unsigned Level1, unsigned Level1Trigger,
              unsigned Level2, unsigned Level2Trigger, unsigned Level3,
              unsigned Level3Trigger, unsigned Climax, unsigned ClimaxTrigger,
              unsigned ClimaxDoubleTrigger);
        CDeck(std::vector <CCard> Deck);

        ///Methods
        unsigned CardCount();
        CCard TopCheck();
        CCard Mill();
        std::vector<CCard> getDeck() const;
};

#endif // CDECK_H

#include "CDeck.h"

std::vector<CCard> CDeck::getDeck() const
{
    return m_Deck;
}

CDeck::CDeck()
{

}

CDeck::CDeck(unsigned Level0, unsigned Level1, unsigned Level1Trigger, unsigned Level2, unsigned Level2Trigger, unsigned Level3, unsigned Level3Trigger, unsigned Climax, unsigned ClimaxTrigger, unsigned ClimaxDoubleTrigger)
{
    std::vector <unsigned> NbCards;
    NbCards.push_back(Level0);
    NbCards.push_back(Level1);
    NbCards.push_back(Level1Trigger);
    NbCards.push_back(Level2);
    NbCards.push_back(Level2Trigger);
    NbCards.push_back(Level3);
    NbCards.push_back(Level3Trigger);
    NbCards.push_back(Climax);
    NbCards.push_back(ClimaxTrigger);
    NbCards.push_back(ClimaxDoubleTrigger);

    std::vector <unsigned> TableLevel {0, 1, 1, 2, 2, 3, 3, 0, 0, 0};
    std::vector <std::string> TableType {"NC", "NC", "NC", "NC", "NC", "NC", "NC", "C", "C", "C"};
    std::vector <char> TableTrigger {'N', 'N', 't', 'N', 't', 'N', 't', 'N', 't', 'T'};

    for (unsigned i (0); i < NbCards.size(); ++i)
        for (unsigned j (0); j < NbCards[i]; ++j)
            m_Deck.push_back(CCard(TableLevel[i], TableType[i], TableTrigger[i]));

    std::random_shuffle (m_Deck.begin(), m_Deck.end());
}

CDeck::CDeck(std::vector<CCard> Deck)
    : m_Deck (Deck) {}

unsigned CDeck::CardCount()
{
    return m_Deck.size();
}

CCard CDeck::TopCheck()
{
    return m_Deck[0];
}

CCard CDeck::Mill()
{
    CCard Card = TopCheck();
    m_Deck.erase(m_Deck.begin());
    return Card;
}

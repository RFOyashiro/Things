#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <pthread.h>
#include "CAttack.h"

using namespace std;

namespace {
    void Test () {

        //Your Deck
        unsigned Level0              = 9;
        unsigned Level1              = 8;
        unsigned Level1Trigger       = 0;
        unsigned Level2              = 0;
        unsigned Level2Trigger       = 3;
        unsigned Level3              = 0;
        unsigned Level3Trigger       = 3;
        unsigned Climax              = 0;
        unsigned ClimaxTrigger       = 3;
        unsigned ClimaxDoubleTrigger = 2;

        //Your Opponent Deck
        unsigned OppClimax           = 8;
        unsigned Chara               = 17;

        //Your Opponent Board
        unsigned Scry                = 0;

        //Your Attack
        vector <pair <char, unsigned>> Attack;

        Attack.push_back(pair <char, unsigned> ('N', 3));
        Attack.push_back(pair <char, unsigned> ('P', 1));
        Attack.push_back(pair <char, unsigned> ('N', 3));
        Attack.push_back(pair <char, unsigned> ('P', 1));
        Attack.push_back(pair <char, unsigned> ('N', 3));
        Attack.push_back(pair <char, unsigned> ('P', 1));

        vector <unsigned> NbAttack;

        vector <unsigned> NbCancel;
        vector <vector <unsigned>> CancelsPrecis;
        vector <vector <unsigned>> Triggers;
        vector <vector <unsigned>> Damage;
        vector <vector <unsigned>> DamageCancel;

        vector <unsigned> CancelsPrecis2;
        vector <unsigned> Triggers2;
        vector <unsigned> Damage2;
        vector <unsigned> DamageCancel2;

        for (unsigned i (0); i < Attack.size(); ++i) {
            NbAttack.push_back(0);

            DamageCancel2.push_back(0);
            DamageCancel2.push_back(0);
            DamageCancel2.push_back(0);
            DamageCancel.push_back(DamageCancel2);

            Damage2.push_back(0);
            Damage2.push_back(0);
            Damage2.push_back(0);
            Damage.push_back(Damage2);

            Triggers2.push_back(0);
            Triggers2.push_back(0);
            Triggers2.push_back(0);
            Triggers.push_back(Triggers2);

            for (unsigned j (0); j < Attack[i].second + 2; ++j)
                CancelsPrecis2.push_back(0);
            CancelsPrecis.push_back(CancelsPrecis2);

            NbCancel.push_back(0);

            Damage2.clear();
            CancelsPrecis2.clear();
            Triggers2.clear();
            DamageCancel2.clear();
        }

        ofstream Result ("Result.txt");

        cout << "you tried to inflict :" << endl << "- " << Attack[0].second << " damage";
        Result << "you tried to inflict :" << endl << "- " << Attack[0].second << " damage";

        for (unsigned i (1); i < Attack.size(); ++i) {
            cout << endl << "- " << Attack[i].second << " damage";
            Result << endl << "- " << Attack[i].second << " damage";
        }
        cout << endl << "to your opponent with " << OppClimax << " climax for " << Chara + OppClimax << " cards in his deck." << endl << endl;
        Result << endl << "to your opponent with " << OppClimax << " climax for " << Chara + OppClimax << " cards in his deck." << endl << endl << endl;

        vector <pair <char, unsigned>> AttackBU = Attack;

        for (unsigned i (0); i < 1000000; ++i) {

            Attack = AttackBU;

            unsigned DamageValue;

            CDeck YourDeck (Level0, Level1, Level1Trigger, Level2,
                            Level2Trigger, Level3, Level3Trigger,
                            Climax, ClimaxTrigger, ClimaxDoubleTrigger);

            CDeck OppDeck (Chara, 0, 0, 0, 0, 0, 0, OppClimax, 0, 0);

            CAttack Attacking;

            for (unsigned j (0); j < Attack.size(); ++j) {
                if (Attack[j].first == 'P') {
                    if (!Attacking.getIsCancel()) continue;
                    Attack[j].first = 'B';
                }

                Attacking = CAttack (YourDeck, OppDeck, Attack[j].second, Attack[j].first);

                NbAttack[j]++;

                DamageValue = Attacking.Hit();

                if (Attacking.getIsTriggert()) Triggers[j][1]++;
                else if (Attacking.getIsTriggerT()) Triggers[j][2]++;
                else Triggers[j][0]++;

                if (Attacking.getDamgeTaken() == Attack[j].second) Damage[j][1]++;
                else if (Attacking.getDamgeTaken() == Attack[j].second + 1) Damage[j][2]++;
                else if (Attacking.getDamgeTaken() == Attack[j].second + 2) Damage[j][3]++;
                else Damage[j][0]++;

                if (Attacking.getIsCancel()) {
                    CancelsPrecis[j][Attacking.getCanceled() - 1]++;
                    NbCancel[j]++;
                    if (DamageValue == Attack[j].second) DamageCancel[j][0]++;
                    else if (DamageValue == Attack[1].second + 1) DamageCancel[j][1]++;
                    else DamageCancel[j][2]++;
                }

                YourDeck = Attacking.getYourDeck();
                OppDeck = Attacking.getOppDeck();
            }
        }

        double RetourP = 1;
        double RetourN = 1;

        for (unsigned i (0); i < NbCancel.size(); ++i) {
            RetourP *= ((NbAttack[i] - NbCancel[i]) / (double) NbAttack[i]);
            RetourN *= NbCancel[i] / (double) NbAttack[i];
        }

        Result << setprecision(5)
               << "Chances to deal all the damage : " << RetourP * 100.00 << "%" << endl
               << "Chances to deal no damage      : " << RetourN * 100.00 << "%" << endl << endl;

        for (unsigned i (0); i < Attack.size(); ++i) {
            Result << setprecision(5)
                   << "Out of " << NbAttack[i] << " tries your opponent took the " << i + 1 << "° attack " << (NbAttack[i] - NbCancel[i]) << " times" << endl
                   << "while canceling " << NbCancel[i] << " times" << endl
                   << "Chances to deal damage with this attack : "
                   << ((NbAttack[i] - NbCancel[i]) / (double) NbAttack[i]) * 100 << "%" << endl
                   << endl << endl;

            Result << "Your opponent canceled : " << endl;
            for (unsigned j (0); j < CancelsPrecis[i].size(); ++j) {
                Result << setw(6) << setfill(' ') << CancelsPrecis[i][j] << " times on " << j + 1 << endl;
            }
            Result << endl;
            for (unsigned j (0); j < DamageCancel[i].size(); ++j) {
                Result << setw(6) << setfill(' ') << DamageCancel[i][j] << " times an attack for " << j + Attack[i].second << " damage" << endl;
            }
            Result << endl;

            Result << "You triggered :" << endl;
            for (unsigned j (0); j < 3; j++)
                Result << setw(6) << setfill(' ') << Triggers[i][j] << " times +" << j << " souls" << endl;
            Result << endl;

            Result << "You dealed :" << endl;
            Result << setw(6) << setfill(' ') << Damage[i][0] << " times 0 damage ("
                   << setprecision(5)  << ((double) Damage[i][0] / (double) NbAttack[i]) * 100 << "%)" << endl;
            for (unsigned j (1); j < 4; j++) {
                Result << setw(6) << setfill(' ') << Damage[i][j] << " times " << j + Attack[i].second - 1 << " damage ("
                       << setprecision(5)  << ((double) Damage[i][j] / (double) NbAttack[i]) * 100 << "%)" << endl;
            }
            Result << endl << endl << endl;
        }
    }
}

int main(){
    srand (time(0));

    Test();

    /*
    //Your Deck
    unsigned Level0              = 9;
    unsigned Level1              = 8;
    unsigned Level1Trigger       = 0;
    unsigned Level2              = 0;
    unsigned Level2Trigger       = 3;
    unsigned Level3              = 0;
    unsigned Level3Trigger       = 3;
    unsigned Climax              = 0;
    unsigned ClimaxTrigger       = 3;
    unsigned ClimaxDoubleTrigger = 2;

    //Your Opponent Deck
    unsigned OppClimax           = 8;
    unsigned Chara               = 17;

    //Your Opponent Board
    unsigned Scry                = 0;

    //Your Attack
    vector <pair <char, unsigned>> Attack;

    Attack.push_back(pair <char, unsigned> ('N', 2));

    unsigned NbCancel = 0;
    vector <unsigned> CancelsPrecis;
    vector <unsigned> Triggers;
    vector <unsigned> Damage;
    vector <unsigned> DamageCancel;
    DamageCancel.push_back(0);
    DamageCancel.push_back(0);
    DamageCancel.push_back(0);
    Damage.push_back(0);
    Damage.push_back(0);
    Damage.push_back(0);
    Damage.push_back(0);
    Triggers.push_back(0);
    Triggers.push_back(0);
    Triggers.push_back(0);

    for (unsigned k (0); k < Attack[0].second + 2; ++k)
        CancelsPrecis.push_back(0);

    ofstream Result ("Result.txt");

    cout << "you tried to infict " << Attack[0].second << " damage to your opponent" << endl
         << "with " << OppClimax << " climax for " << Chara + OppClimax << " cards in his deck." << endl << endl;

    Result << "you tried to infict " << Attack[0].second << " damage to your opponent" << endl
           << "with " << OppClimax << " climax for " << Chara + OppClimax << " cards in his deck." << endl << endl;

    for (unsigned i (0); i < 1000000; ++i) {

        unsigned DamageValue;

        CDeck YourDeck (Level0, Level1, Level1Trigger, Level2,
                        Level2Trigger, Level3, Level3Trigger,
                        Climax, ClimaxTrigger, ClimaxDoubleTrigger);

        CDeck OppDeck (Chara, 0, 0, 0, 0, 0, 0, OppClimax, 0, 0);


        CAttack Attacking (YourDeck, OppDeck, Attack[0].second, Attack[0].first);

        DamageValue = Attacking.Hit();

        if (Attacking.getIsTriggert()) Triggers[1]++;
        else if (Attacking.getIsTriggerT()) Triggers[2]++;
        else Triggers[0]++;

        if (Attacking.getDamgeTaken() == Attack[0].second) Damage[1]++;
        else if (Attacking.getDamgeTaken() == Attack[0].second + 1) Damage[2]++;
        else if (Attacking.getDamgeTaken() == Attack[0].second + 2) Damage[3]++;
        else Damage[0]++;

        if (Attacking.getIsCancel()) {
            CancelsPrecis[Attacking.getCanceled() - 1]++;
            NbCancel++;
            if (DamageValue == Attack[0].second) DamageCancel[0]++;
            else if (DamageValue == Attack[0].second + 1) DamageCancel[1]++;
            else DamageCancel[2]++;
        }
    }


    Result << "Out of 1 000 000 tries your opponent took this attack " << (1000000 - NbCancel) << " times" << endl
         << "while canceling " << NbCancel << " times" << endl
         << "Chances to deal damage with this attack : " << setprecision(5)
         << ((1000000 - NbCancel) / 1000000.00) * 100 << "%" << endl
         << endl << endl;

    Result << "Your opponent canceled : " << endl;
    for (unsigned j (0); j < CancelsPrecis.size(); ++j) {
        Result << setw(6) << setfill(' ') << CancelsPrecis[j] << " times on " << j + 1 << endl;
    }
    Result << endl;
    for (unsigned j (0); j < DamageCancel.size(); ++j) {
        Result << setw(6) << setfill(' ') << DamageCancel[j] << " times an attack for " << j + Attack[0].second << " damage" << endl;
    }
    Result << endl;

    Result << "You triggered :" << endl;
    for (unsigned i (0); i < 3; i++)
        Result << setw(6) << setfill(' ') << Triggers[i] << " times +" << i << " souls" << endl;
    Result << endl;

    Result << "You dealed :" << endl;
    Result << setw(6) << setfill(' ') << Damage[0] << " times 0 damage ("
         << setprecision(5)  << ((double) Damage[0] / 1000000.00) * 100 << "%)" << endl;
    for (unsigned i (1); i < 4; i++) {
        Result << setw(6) << setfill(' ') << Damage[i] << " times " << i + Attack[0].second - 1 << " damage ("
             << setprecision(5)  << ((double) Damage[i] / 1000000.00) * 100 << "%)" << endl;
    }
    Result << endl;
*/
    return 0;
}

/*
 * chance a et b passe     -> p(a ^ b) = P(a) * P(a/b)
 * chance a passe et pas b -> p(a ^ |b)
 * chance b passe et pas a -> p(|a ^ b)
 * chance rien passe       -> p(|a ^ |b)
 *
 */

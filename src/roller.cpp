#include "roller.h"
#include "cassinoAdm.h"
#include <iostream>

Roller::Roller()
{
    m_dice.reserve(10);
    m_reportFrequency = CassinoAdm::cassinoAdm().getCrapWindow();
}

void Roller::pickDice(int p_numberOfDice)
{
    m_dice = std::vector<Die>(p_numberOfDice, Die());
    m_numberOfRolls = 0;
}

void Roller::roll()
{
    for(auto& die : m_dice)
        std::cout << die.roll() << " ";
    std::cout << std::endl;

    if(++m_numberOfRolls % m_reportFrequency == 0)
        report();
}

void Roller::history()
{
    for (const auto& die : m_dice) {
        const auto& hist = die.history();
        for (int i = 0; i < hist.size(); ++i)
            std::cout << i+1 << ": " << hist[i] << "   ";
        std::cout << std::endl;
    }
}

void Roller::report()
{
    CassinoAdm::cassinoAdm().evaluateDice(m_dice);
}
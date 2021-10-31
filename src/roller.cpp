#include "roller.h"
#include "cassinoAdm.h"
#include <iostream>

Roller::Roller()
{
    m_dice.reserve(10);
    m_reportFrequency = CassinoAdm::cassinoAdm().getCrapsWindow();
}

void Roller::pickDice(int p_numberOfDice)
{
    m_dice = std::vector<Die>(p_numberOfDice, Die());
    m_numberOfRolls = 0;
    std::cout <<  p_numberOfDice << " dice picked" << std::endl;
}

void Roller::roll()
{
    if (m_dice.size() == 0)
        throw std::runtime_error("No dice picked. For picking use \'pick <number>\'\n");

    std::cout << "[Roll " << m_numberOfRolls + 1 << "] ";
    for(auto& die : m_dice)
        std::cout << die.roll() << " ";
    std::cout << std::endl;

    if(++m_numberOfRolls % m_reportFrequency == 0)
        report();
}

void Roller::history()
{
    for (int i = 0; i < m_dice.size(); ++i) {
        const auto& hist = m_dice[i].history();
        std::cout << "[Die " << i + 1 << "]   ";
        for (int j = 0; j < hist.size(); ++j)
            std::cout << "f" << j+1 << ": " << hist[j] << "   ";
        std::cout << std::endl;
    }
}

void Roller::report()
{
    CassinoAdm::cassinoAdm().evaluateDice(m_dice);
}
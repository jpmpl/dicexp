#pragma once

#include "die.h"
#include <vector>

class Roller
{
public:
    Roller();
    void pickDice(int p_numberOfDice);
    void roll();
    void history();
private:
    long int m_numberOfRolls{0};
    std::vector<Die> m_dice{};
    int m_reportFrequency{0};

    void report();
};
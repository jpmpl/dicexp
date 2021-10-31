#pragma once

#include "die.h"
#include <vector>

class CassinoAdm
{
public:
    static CassinoAdm& cassinoAdm();
    int getCrapWindow() { return m_crapWindow; };
    void evaluateDice(std::vector<Die>& p_dice);
    
private:
    int m_crapWindow{10};
    int m_penaltyLevel{2};

    CassinoAdm();
    void penalize(Die& p_die, int p_face);
};
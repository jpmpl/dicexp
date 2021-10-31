#pragma once

#include "die.h"
#include <vector>

class CassinoAdm
{
public:
    static CassinoAdm& cassinoAdm();
    int getCrapsWindow() { return m_crapsWindow; };
    void evaluateDice(std::vector<Die>& p_dice);
    
private:
    int m_crapsWindow{10};
    int m_penaltyLevel{2};

    CassinoAdm();
    void penalize(Die& p_die, int p_face);
    std::vector<float> getProbabilities(const Die& p_die);

    friend class CassinoAdmTest;
};
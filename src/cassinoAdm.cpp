#include "cassinoAdm.h"
#include <algorithm>
#include <iostream>

CassinoAdm& CassinoAdm::cassinoAdm()
{
    static CassinoAdm instance{};
    return instance;
}

void CassinoAdm::evaluateDice(std::vector<Die>& p_dice)
{
    for (auto& die : p_dice) {
        auto hist = die.history();
        auto face = std::max_element(&hist[0], &hist[0]+hist.size()) - &hist[0];
        penalize(die, face);
    }
}

void CassinoAdm::penalize(Die& p_die, int p_face)
{
    p_die.addPenalty(p_face, m_penaltyLevel);
}

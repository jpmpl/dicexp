#include "die.h"
#include <iostream>
#include <algorithm>
#include <random>

Die::Die()
{
    for (int i = 0; i < m_probMatrix.size(); ++i) {
        std::fill_n(&m_probMatrix[i][0], m_probMatrix[i].size(), i+1);
        m_trackPenalty[0] = m_probMatrix[i].data();
    }
    std::fill_n(&m_globalHistory[0], m_globalHistory.size(), 0);
    initHistory();
}

void Die::initHistory()
{
    std::fill_n(&m_history[0], m_history.size(), 0);
}

int Die::roll()
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist_col(0, m_probMatrix.size()-1);
    std::uniform_int_distribution<int> uniform_dist_row(0, m_probMatrix[0].size()-1);
    int ret = m_probMatrix[uniform_dist_col(e1)][uniform_dist_row(e1)];
    if (ret == 0)
        ret = roll();
    else {
        m_history[ret-1]++;
        m_globalHistory[ret-1]++;
    }
    
    return ret;
}

std::array<long int, DIEFACES> Die::history() const
{
    return m_globalHistory;
}

void Die::addPenalty(int p_face, int p_penaltyLevel)
{
    
    std::fill_n(m_trackPenalty[p_face], p_penaltyLevel, 0);
    m_trackPenalty[p_face] += p_penaltyLevel;
    initHistory();

    if (hasAllFaceSamePenalty(p_penaltyLevel))
        restoreAllOnePenalty(p_penaltyLevel);
}

bool Die::hasAllFaceSamePenalty(int p_penaltyLevel)
{
    bool hasAllSamePenalty = true;
    for (int i = 0; i < m_trackPenalty.size(); ++i) {
        if (m_trackPenalty[i] - m_probMatrix[i].data() < 2) {
            hasAllSamePenalty = false;
            break;
        }
    }
    return hasAllSamePenalty;
}

void Die::restoreAllOnePenalty(int p_penaltyLevel)
{
    for (int i = 0; i < m_trackPenalty.size(); ++i) {
        std::fill_n(m_trackPenalty[i]-p_penaltyLevel, p_penaltyLevel, i+1);
        m_trackPenalty[i] -= p_penaltyLevel;
    }
}
#include "die.h"
#include <iostream>
#include <algorithm>
#include <random>

static bool g_debug = getenv("DEBUG");

Die::Die()
{
    for (int i = 0; i < m_probMatrix.size(); ++i)
        std::fill_n(&m_probMatrix[i][0], m_probMatrix[i].size(), i+1);

    std::fill_n(&m_trackPenalty[0], m_trackPenalty.size(), 0);
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

void Die::addPenalty(int p_face, int p_penaltyLevel)
{
    std::fill_n(&m_probMatrix[p_face][0] + m_trackPenalty[p_face], p_penaltyLevel, 0);
    m_trackPenalty[p_face] += p_penaltyLevel;
    initHistory();

    if (hasAllFaceSamePenalty(p_penaltyLevel))
        restoreAllOnePenalty(p_penaltyLevel);
    
    evaluateProbabilities();
}

bool Die::hasAllFaceSamePenalty(int p_penaltyLevel)
{
    bool hasAllSamePenalty = true;
    for (int i = 0; i < m_trackPenalty.size(); ++i) {
        if (m_trackPenalty[i] < 2) {
            hasAllSamePenalty = false;
            break;
        }
    }
    return hasAllSamePenalty;
}

void Die::restoreAllOnePenalty(int p_penaltyLevel)
{
    for (int i = 0; i < m_trackPenalty.size(); ++i) {
        std::fill_n(&m_probMatrix[i][0] + m_trackPenalty[i] - p_penaltyLevel, p_penaltyLevel, i+1);
        m_trackPenalty[i] -= p_penaltyLevel;
    }
}

void Die::evaluateProbabilities()
{
    int totalCases{0};
    std::array<int, DIEFACES> casesPerFace{};
    for (int i = 0; i < m_probabilities.size(); ++i) {
        casesPerFace[i] = m_probMatrix[i].size() - m_trackPenalty[i];
        totalCases += casesPerFace[i];
    }
    
    for (int i = 0; i < m_probabilities.size(); ++i) {
        m_probabilities[i] = (float) casesPerFace[i]/totalCases;
        
        if (g_debug)
            std::cout << "Face " << i+1 << ": " << casesPerFace[i] << "/" << totalCases << " = " << m_probabilities[i] << "   ";
    }
    if (g_debug)
        std::cout << std::endl;
}
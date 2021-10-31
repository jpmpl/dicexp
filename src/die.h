#pragma once

#include <array>
#define MAXSIZE 100
#define DIEFACES 6

class Die
{
public:
    Die();
    int roll();
    const std::array<long int, DIEFACES>& history() const { return m_globalHistory; };
private:
    std::array<std::array<int, MAXSIZE>, DIEFACES> m_probMatrix{};
    std::array<int, DIEFACES> m_trackPenalty{};
    std::array<int, DIEFACES> m_history{};
    std::array<long int, DIEFACES> m_globalHistory{};
    std::array<float, DIEFACES> m_probabilities;

    void initHistory();
    void addPenalty(int p_face, int p_penaltyLevel);
    bool hasAllFaceSamePenalty(int p_penaltyLevel);
    void restoreAllOnePenalty(int p_penaltyLevel);
    void evaluateProbabilities();
    const std::array<float, DIEFACES>& probabilities() const { return m_probabilities; };
    const std::array<int, DIEFACES>& windowHistory() const { return m_history; };

    friend class CassinoAdm;
};

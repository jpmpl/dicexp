#pragma once

#include <array>
#define MAXSIZE 100
#define DIEFACES 6

class Die
{
public:
    Die();
    int roll();
    std::array<long int, DIEFACES> history() const;
private:
    std::array<std::array<int, MAXSIZE>, DIEFACES> m_probMatrix{};
    std::array<int*, DIEFACES> m_trackPenalty{};
    std::array<int, DIEFACES> m_history{};
    std::array<long int, DIEFACES> m_globalHistory{};

    void initHistory();
    void addPenalty(int p_face, int p_penaltyLevel);
    bool hasAllFaceSamePenalty(int p_penaltyLevel);
    void restoreAllOnePenalty(int p_penaltyLevel);

    friend class CassinoAdm;
};

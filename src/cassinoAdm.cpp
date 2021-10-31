#include "cassinoAdm.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

static bool g_debug = getenv("DEBUG");

CassinoAdm::CassinoAdm()
{
    nlohmann::json json;
    std::ifstream configFile("config/cassino.json", std::ifstream::in);
    if (!configFile.is_open())
        throw std::runtime_error("File cassino.json not found.");
    configFile >> json;
    m_crapWindow = json["crapwindow"].get<int>();
    m_penaltyLevel = json["penaltyLevel"].get<int>();
}

CassinoAdm& CassinoAdm::cassinoAdm()
{
    static CassinoAdm instance{};
    return instance;
}

void CassinoAdm::evaluateDice(std::vector<Die>& p_dice)
{
    int d{0};
    for (auto& die : p_dice) {
        auto hist = die.windowHistory();
        if (!std::equal(&hist[0]+1, &hist[0]+hist.size(), &hist[0])) {
            auto face = std::max_element(&hist[0], &hist[0]+hist.size()) - &hist[0];
            penalize(die, face);

            if (g_debug) {
                std::cout << "Die " << ++d << ": " << face+1 << std::endl;
                for (int i = 0; i < die.probabilities().size(); ++i) {
                    std::cout << "p" << i+1 << ": " << die.probabilities()[i] << "   ";
                }
                std::cout << std::endl;
            }
        }
    }
    if (g_debug)
        std::cout << std::endl;
}

void CassinoAdm::penalize(Die& p_die, int p_face)
{
    p_die.addPenalty(p_face, m_penaltyLevel);
}

std::vector<float> CassinoAdm::getProbabilities(const Die& p_die)
{
    std::vector<float> probs{};
    for (int i = 0; i < p_die.probabilities().size(); ++i)
        probs.push_back(p_die.probabilities()[i]);
    return probs;
}

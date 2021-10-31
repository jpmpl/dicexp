#include "gtest/gtest.h"

#include "die.h"
#include "roller.h"
#include "cassinoAdm.h"

class DieTest : public ::testing::Test
{
protected:
    Die m_die0;
    Die m_die1;
    long int getTotalRollsFromHistory(Die p_die) {
        long int sum{0};
        for (const auto& val : p_die.history())
            sum += val;
        return sum;
    }
};

TEST_F(DieTest, noRolls)
{
    long int sum{0};
    for (const auto& val : m_die0.history())
        sum += val;
    EXPECT_EQ(sum, 0) << "History should be 0";
}

TEST_F(DieTest, hundredRolls)
{
    int face;
    for (int i = 0; i < 100; ++i) {
        face = m_die1.roll();
        EXPECT_TRUE((face >= 1) && (face <= 6)) << "Face is out of range";
    }
    
    EXPECT_EQ(getTotalRollsFromHistory(m_die1), 100) << "Total number of cases should be 100";
}

class RollerTest : public ::testing::Test
{
protected:
    Roller m_r0;
    Roller m_r1;

    int getNumberOfDice(const Roller& p_r) { return p_r.m_dice.size(); }
    int getNumberOfRolls(const Roller& p_r) { return p_r.m_numberOfRolls; }
};

TEST_F(RollerTest, noDicePicked)
{
    EXPECT_THROW(m_r0.roll(), std::runtime_error);
}

TEST_F(RollerTest, fiveDicePicked)
{
    m_r1.pickDice(5);
    EXPECT_EQ(getNumberOfDice(m_r1), 5);
    EXPECT_EQ(getNumberOfRolls(m_r1), 0);
    EXPECT_NO_THROW(m_r1.roll());
}

TEST_F(RollerTest, hundredRolls)
{
    m_r1.pickDice(5);
    for (int i = 0; i < 100; ++i)
        EXPECT_NO_THROW(m_r1.roll());
    EXPECT_EQ(getNumberOfRolls(m_r1), 100);
    EXPECT_NO_THROW(m_r1.history());
}

TEST_F(RollerTest, multiplePick)
{
    m_r1.pickDice(5);
    EXPECT_EQ(getNumberOfDice(m_r1), 5);
    EXPECT_EQ(getNumberOfRolls(m_r1), 0);
    m_r1.roll();
    m_r1.roll();
    m_r1.roll();
    EXPECT_EQ(getNumberOfRolls(m_r1), 3);
    m_r1.pickDice(3);
    EXPECT_EQ(getNumberOfDice(m_r1), 3);
    EXPECT_EQ(getNumberOfRolls(m_r1), 0);
    m_r1.roll();
    m_r1.roll();
    m_r1.roll();
    m_r1.roll();
    EXPECT_EQ(getNumberOfRolls(m_r1), 4);
}

class CassinoAdmTest : public ::testing::Test
{
protected:
    Die m_die;
    int getPenaltyLevel() { return CassinoAdm::cassinoAdm().m_penaltyLevel; }
    std::vector<float> getProbabilities(const Die& p_die) { return CassinoAdm::cassinoAdm().getProbabilities(p_die); }
    float sumProbabilities(const Die& p_die) {
        float sum{0};
        for (auto& prob : CassinoAdm::cassinoAdm().getProbabilities(p_die))
            sum += prob;
        return sum;
    }
    bool allEqualFaceProbability(const Die& p_die) {
        auto probs = CassinoAdm::cassinoAdm().getProbabilities(p_die);
        float prob = probs[0];
        for (int i = 1; i < probs.size(); ++i)
            if (prob != probs[i])
                return false;
        return true;
    }
    void penalize(Die& p_die, int p_face) { CassinoAdm::cassinoAdm().penalize(p_die, p_face); }
};

TEST_F(CassinoAdmTest, constructorInitialization)
{
    EXPECT_NO_THROW(CassinoAdm::cassinoAdm());
    EXPECT_GT(CassinoAdm::cassinoAdm().getCrapsWindow(), 0);
    EXPECT_GT(getPenaltyLevel(), 0);
}

TEST_F(CassinoAdmTest, addPenalty)
{
    int face1 = 1;
    int face2 = 2;
    int face3 = 3;
    int face4 = 4;
    int face5 = 5;
    int face6 = 6;
    
    EXPECT_TRUE(allEqualFaceProbability(m_die));
    penalize(m_die, face2-1);
    EXPECT_FALSE(allEqualFaceProbability(m_die));
    EXPECT_EQ(sumProbabilities(m_die), 1);

    penalize(m_die, face4-1);
    auto probs = getProbabilities(m_die);
    EXPECT_EQ(probs[face2-1], probs[face4-1]);
    penalize(m_die, face2-1);
    probs = getProbabilities(m_die);
    EXPECT_LT(probs[face2-1], probs[face4-1]);
    EXPECT_GT(probs[face6-1], probs[face4-1]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
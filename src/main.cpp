#include "roller.h"
#include <array>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
    auto r = Roller();
    r.pickDice(5);

    for (int i=0 ; i< 10; i++)
        r.roll();
    
    r.history();
}
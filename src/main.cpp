#include "roller.h"
#include <array>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    auto r = Roller();
    std::cout << "> ";
    std::string cmd{};
    while (std::getline(std::cin, cmd)) {

        // Get arguments from command
        std::istringstream ss(cmd);
        std::string cmdPiece{};
        std::vector<std::string> args{};
        while (ss >> cmdPiece) {
            if (cmdPiece.empty())
                continue;
            args.push_back(cmdPiece);
        }
        
        // Evaluate command
        try {
            bool isPick{false}, isRoll{false};
            int argCount{0};
            for (; argCount < args.size(); ++argCount) {
                const auto& arg = args[argCount];
                if (arg == "quit" || arg == "exit")
                    exit(0);
                
                if (argCount == 0 && arg == "pick")
                    isPick = true;
                else if (argCount == 1 && isPick)
                    r.pickDice(std::stoi(arg));
                else if (argCount == 0 && arg == "roll")
                    isRoll = true;
                else if (argCount == 1 && isRoll)
                    for (int i = 0; i < std::stoi(arg); ++i)
                        r.roll();
                else if (argCount == 0 && arg == "history")
                    r.history();
                else {
                    std::stringstream errorMsg;
                    errorMsg << "Invalid input: " << arg << std::endl;
                    throw std::runtime_error(errorMsg.str());
                }
            } while(ss);
            
            if (argCount == 1 && isPick)
                r.pickDice(2);
            if (argCount == 1 && isRoll)
                r.roll();
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what();
        }

        std::cout << std::endl << "> ";
    }
}
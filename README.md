# dicexp

### Problem Statement
As a cassino manager for the Craps Session, there is a need to keep track of the dice behavior in order to analyse the possibility of a face turning up more often than the other, which elevates the risk of the cassino loosing. Once this behavior is detected, there is need to contrabalance such behavior by reducing the chances of getting the often played number.

### Solution
The proposed solution is to replace the roller and statistics person by an automatic system. Through this system, the player will be able to pick a number of dice and roll them. On the background, the history of the dice will be kept and analysed such that a penalization will be applied on an often played number, when detected.

### Implementation Structure
```bash
dicexp
├── Makefile
├── README.md
├── config
│   └── cassino.json
├── dependencies
│   ├── gtest
│   └── json_nlohmann
├── src
│   ├── Makefile
│   ├── cassinoAdm.cpp
│   ├── cassinoAdm.h
│   ├── die.cpp
│   ├── die.h
│   ├── die.log
│   ├── main.cpp
│   ├── roller.cpp
│   └── roller.h
└── test
    ├── Makefile
    └── rollerTest.cpp
```

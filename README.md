# dicexp

### 1) Problem Statement
As a cassino manager for the Craps Session, there is a need to keep track of the dice behavior in order to analyse the possibility of a face turning up more often than the other, which elevates the risk of the cassino loosing. Once this behavior is detected, there is need to contrabalance such behavior by reducing the chances of getting the often played number.

### 2) Solution
The proposed solution is to replace the roller and statistics person by an automatic system. Through this system, the player will be able to pick a number of dice and roll them. On the background, the history of the dice will be kept and analysed such that a penalization will be applied on an often played number, when detected.

### 3) Build
To build the application, download the src code and on the project root dir, just call make.
To run the application, run: ./src/bin/roller
To check probability data and debug messages, run: env DEBUG=1 ./src/bin/roller

#### 3.1) Unit Tests
Some unit tests were added using googletest framework. All tests can be run by: ./test/src/rollertest

### 4) Implementation Structure
The implementation has the following directory structure:

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

#### 4.1) Die Class (die.h die.cpp)
The die class simulates the behavior of a die. You can roll it and it will return the face it turned up.<br><br>
There are structures in the class to regulate the probability of getting a face of the dice. The main idea here is to have a n-per-6 matrix like structure which keeps, at the beggining, the same number of n face values. Initially the probability of getting one face is: n/(6\*n) = 1/6 for each. This is possible, because the indexes of the matrix are picked randomly based on a homogeneus distribution.<br><br>
However, as penalties are added to a face, the number of face occurencies in the matrix are reduced, reducing the chance/probability of this face being picked when compared to the other.

#### 4.2) Roller Class (roller.h roller.cpp)
The roller class interfaces with the player, the dice and the cassino administration. After a window of rolls defined by the administration, the roller reports the dice data to the cassino administration, which analyses if there is an unbalanced number of events for each die. In case there is, a penalty is added to the face that showed up the most in this window, reducing it's probability of being picked.

#### 4.3) CassinoAdm Class (cassinoAdm.h cassinoAdm.cpp)
The cassino adm is responsible for analysing the historical data from the dice and applying a penalty to a face when an unbalanced cenario is detected. The cassino adm operates on the background and its actions are not transparent to the player.

#### 4.4) Main application (roller)
The main application is a shell-like console application. After the player starts the roller application (./src/bin/roller), it will accept the following commands:
* pick \<number\> <br>
    Picks n dice (default is 2) <br>
    (The pick command will always pick new dice) <br><br>
* roll \<number\> <br>
    Roll all dice n times (default is 1) and outputs results <br><br>
* history <br>
    Display the historical frequency (number of times) that each face was played for each die.

### 5) Application Flow
![flow](https://user-images.githubusercontent.com/15233024/139600891-aff77d38-bf7e-4190-80ef-f4f0e286105c.png)

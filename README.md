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
│   │   ├── include
│   │   │   ├── gmock
│   │   │   │   ├── gmock-actions.h
│   │   │   │   ├── gmock-cardinalities.h
│   │   │   │   ├── gmock-function-mocker.h
│   │   │   │   ├── gmock-matchers.h
│   │   │   │   ├── gmock-more-actions.h
│   │   │   │   ├── gmock-more-matchers.h
│   │   │   │   ├── gmock-nice-strict.h
│   │   │   │   ├── gmock-spec-builders.h
│   │   │   │   ├── gmock.h
│   │   │   │   └── internal
│   │   │   │       ├── custom
│   │   │   │       │   ├── README.md
│   │   │   │       │   ├── gmock-generated-actions.h
│   │   │   │       │   ├── gmock-matchers.h
│   │   │   │       │   └── gmock-port.h
│   │   │   │       ├── gmock-internal-utils.h
│   │   │   │       ├── gmock-port.h
│   │   │   │       └── gmock-pp.h
│   │   │   └── gtest
│   │   │       ├── gtest-death-test.h
│   │   │       ├── gtest-matchers.h
│   │   │       ├── gtest-message.h
│   │   │       ├── gtest-param-test.h
│   │   │       ├── gtest-printers.h
│   │   │       ├── gtest-spi.h
│   │   │       ├── gtest-test-part.h
│   │   │       ├── gtest-typed-test.h
│   │   │       ├── gtest.h
│   │   │       ├── gtest_pred_impl.h
│   │   │       ├── gtest_prod.h
│   │   │       └── internal
│   │   │           ├── custom
│   │   │           │   ├── README.md
│   │   │           │   ├── gtest-port.h
│   │   │           │   ├── gtest-printers.h
│   │   │           │   └── gtest.h
│   │   │           ├── gtest-death-test-internal.h
│   │   │           ├── gtest-filepath.h
│   │   │           ├── gtest-internal.h
│   │   │           ├── gtest-param-util.h
│   │   │           ├── gtest-port-arch.h
│   │   │           ├── gtest-port.h
│   │   │           ├── gtest-string.h
│   │   │           └── gtest-type-util.h
│   │   └── lib
│   │       ├── cmake
│   │       │   └── GTest
│   │       │       ├── GTestConfig.cmake
│   │       │       ├── GTestConfigVersion.cmake
│   │       │       ├── GTestTargets-noconfig.cmake
│   │       │       └── GTestTargets.cmake
│   │       ├── libgmock.a
│   │       ├── libgmock_main.a
│   │       ├── libgtest.a
│   │       ├── libgtest_main.a
│   │       └── pkgconfig
│   │           ├── gmock.pc
│   │           ├── gmock_main.pc
│   │           ├── gtest.pc
│   │           └── gtest_main.pc
│   └── json_nlohmann
│       └── include
│           └── nlohmann
│               └── json.hpp
├── src
│   ├── Makefile
│   ├── bin
│   │   └── roller
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
    ├── bin
    │   └── rollertest
    └── rollerTest.cpp
```

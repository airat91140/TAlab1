//
// Created by airat on 15.09.2021.
//

#ifndef LAB1_DIALOGUE_H
#define LAB1_DIALOGUE_H

#include <string>
#include <fstream>
#include <iostream>
#include <list>

#include "CheckStr.h"
#include "Hash.h"

class Dialogue {
private:
    void runFast();
    std::list<std::string> runFromSource();
    char **strings;
    int strNum;
    bool isFast; // if true - the input is from cmd arguments and output is to cmd
    std::ofstream out;
    std::ifstream in;
    static std::string formResult(const std::string &str, const CheckStr &checker);

public:
    Dialogue(int argc, char *argv[]);
    void run();
    ~Dialogue();
};


#endif //LAB1_DIALOGUE_H

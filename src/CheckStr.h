//
// Created by airat on 11.09.2021.
//

#ifndef LAB1_CHECKSTR_H
#define LAB1_CHECKSTR_H

#include <string>
#include <CheckStr_sm.h>
#include <ctime>
#include <chrono>

#include "Hash.h"

namespace lab1 {

    class CheckStrContext;

#ifdef CRTP
    class CheckStr : public CheckStrContext<CheckStr> {
#else

    class CheckStr {
#endif
    private:
#ifndef CRTP
        CheckStrContext _fsm;
#endif
        Hash hash; // field where hash is stored
        bool isAccepted;

        static std::string genAcceptedStr(int len);

        static std::string genInacceptedStr(int len);

    public:
        [[nodiscard]] bool getIsAccepted() const;

        CheckStr();

        inline void accept() { isAccepted = true; }

        inline void unaccept() { isAccepted = false; }

        [[nodiscard]] Hash getHash() const;

        void appendToHash(char c); // append one letter to existing has

        bool check(const std::string &str);

        void reset();

        void runTiming();
    };
}
#endif //LAB1_CHECKSTR_H

//
// Created by airat on 11.09.2021.
//

#ifndef LAB1_CHECKSTR_H
#define LAB1_CHECKSTR_H

#include <string>
#include <CheckStr_sm.h>

#include "Hash.h"

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

    public:
        CheckStr();
        inline void accept() {isAccepted = true;}
        inline void unaccept() {isAccepted = false;}
        Hash getHash() const;
        void appendToHash(char c); // append one letter to existing hash
        bool check(std::string str);
    };

#endif //LAB1_CHECKSTR_H

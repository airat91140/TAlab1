//
// Created by airat on 11.09.2021.
//
#include "CheckStr_sm.h"
#include "CheckStr.h"



CheckStr::CheckStr()
#ifndef CRTP
    : hash(32), isAccepted(false), _fsm(*this)
#else
    : counter(32), isAccepted(false)
#endif
{
#ifdef FSM_DEBUG
#ifdef CRTP
    setDebugFlag(true);
#else
    _fsm.setDebugFlag(true);
#endif
#endif
}

Hash CheckStr::getHash() const {
    return hash;
}

void CheckStr::appendToHash(char c) {
    hash.append(c);
}

bool CheckStr::check(std::string str) {
#ifdef CRTP
    enterStartState();
    for (char c : str) {
        switch (c) {
            case 'e':
                letter_e();
                break;

            case 'd':
                letter_d();
                break;

            case '2':
                digit_2();
                break;

            case 'k':
                letter_k();
                break;

            case ':':
                colon();
                break;

            case '/':
                slash();
                break;

            case 'f':
                letter_f();
                break;

            case 'i':
                letter_i();
                break;

            case 'l':
                letter_l();
                break;

            case '0'...'1':
            case '3'...'9':
                digit(c);
                break;

            case 'a'...'c':
                letter_a_c(c);
                break;

            case 'g'...'h':
            case 'j':
            case 'm'...'z':
                letter_g_z(c);
                break;

            case '+':
            case '-':
            case '_':
            case '.':
                special();
                break;

            case '|':
                pipe();
                break;

            default:
                unknown();
                break;
        }
    }
    // end of string has been reached - send the EOS transition.
    EOS();
#else
    _fsm.enterStartState();
    for (char c : str) {
        switch (c) {
            case 'e':
                _fsm.letter_e();
                break;

            case 'd':
                _fsm.letter_d();
                break;

            case '2':
                _fsm.digit_2();
                break;

            case 'k':
                _fsm.letter_k();
                break;

            case ':':
                _fsm.colon();
                break;

            case '/':
                _fsm.slash();
                break;

            case 'f':
                _fsm.letter_f();
                break;

            case 'i':
                _fsm.letter_i();
                break;

            case 'l':
                _fsm.letter_l();
                break;

            case '0'...'1':
            case '3'...'9':
                _fsm.digit(c);
                break;

            case 'a'...'c':
                _fsm.letter_a_c(c);
                break;

            case 'g'...'h':
            case 'j':
            case 'm'...'z':
                _fsm.letter_g_z(c);
                break;

            case '+':
            case '-':
            case '_':
            case '.':
                _fsm.special();
                break;

            case '|':
                _fsm.pipe();
                break;

            default:
                _fsm.unknown();
                break;
        }
    }
    // end of string has been reached - send the EOS transition.
    _fsm.EOS();
#endif

    return isAccepted;
}

bool CheckStr::getIsAccepted() const {
    return isAccepted;
}



//
// Created by airat on 11.09.2021.
//
#include "CheckStr_sm.h"
#include "CheckStr.h"

using std::chrono::steady_clock;

namespace lab1 {

    CheckStr::CheckStr()
#ifndef CRTP
            : hash(32), isAccepted(false), _fsm(*this)
#else
    : counter(32), isAccepted(false)
#endif
    {
//#define FSM_DEBUG
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

    bool CheckStr::check(const std::string &str) {
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
        for (char c: str) {
            switch (c) {
                case 'e':
                case 'E':
                    _fsm.letter_e();
                    break;

                case 'd':
                case 'D':
                    _fsm.letter_d();
                    break;

                case '2':
                    _fsm.digit_2();
                    break;

                case 'k':
                case 'K':
                    _fsm.letter_k();
                    break;

                case ':':
                    _fsm.colon();
                    break;

                case '/':
                    _fsm.slash();
                    break;

                case 'f':
                case 'F':
                    _fsm.letter_f();
                    break;

                case 'i':
                case 'I':
                    _fsm.letter_i();
                    break;

                case 'l':
                case 'L':
                    _fsm.letter_l();
                    break;

                case '0'...'1':
                case '3'...'9':
                    _fsm.digit(c);
                    break;

                case 'a'...'c':
                case 'A'...'C':
                    _fsm.letter_a_c(c);
                    break;

                case 'g'...'h':
                case 'G'...'H':
                case 'j':
                case 'J':
                case 'm'...'z':
                case 'M'...'Z':
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

    void CheckStr::reset() {
        _fsm.enterStartState();
        hash.reset();
        _fsm.emptyStateStack();
        isAccepted = false;

    }

    void CheckStr::runTiming() {
        std::string str;
        steady_clock::duration duration = steady_clock::duration::zero();
        steady_clock::time_point t;
        srand(time(nullptr));
        for (int l = 10000; l <= 100000; l += 1000) {
            duration = duration.zero();
            for (int i = 0; i < l; ++i) {
                {
                    CheckStr checker;
                    str = genAcceptedStr();
                    t = std::chrono::steady_clock::now();
                    checker.check(str);
                    duration += std::chrono::steady_clock::now() - t;
                }
                {
                    CheckStr checker;
                    str = genInacceptedStr();
                    t = std::chrono::steady_clock::now();
                    checker.check(str);
                    duration += std::chrono::steady_clock::now() - t;
                }
            }
            std::cout/* << "Checks: " */<< l * 2 << " "/*" time: "*/ << duration.count() << std::endl;
        }
    }

// ed2k://|file|имя_файла|размер_файла|хэш_файла|/
    std::string CheckStr::genAcceptedStr() {
        std::string str = "ed2k://|file|";
        str.reserve(250);
        int len = rand() % 100;
        for (int i = 0; i < len; ++i) {
            str += rand() % ('z' - 'a' + 1) + (rand() & 1 ? 'a' : 'A');
        }
        str += '|';
        len = rand() % 100;
        for (int i = 0; i < len; ++i) {
            str += rand() % ('9' - '0' + 1) + '0';
        }
        str += '|';
        for (int i = 0; i < 32; ++i) {
            str += (rand() & 1) ? ((rand() % ('9' - '0' + 1)) + '0') : (rand() % ('f' - 'a' + 1) + (rand() & 1 ? 'a' : 'A')); //generating random hash
        }
        str += "|/";
        return str;
    }

    std::string CheckStr::genInacceptedStr() {
        std::string str;
        str.reserve(250);
        for (int i = 0; i < 250; ++i) {
            str += rand() % ('~' - '(' + 1) + '(';
        }
        return str;
    }
}


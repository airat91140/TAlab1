//
// Created by airat on 12.09.2021.
//

#ifndef LAB1_HASH_H
#define LAB1_HASH_H

#include <string>

class Hash {
private:
    std::string str; // field in which hash is stored
    int max; // number of letters in hash
public:
    [[nodiscard]] bool isUnderOrEqMax() const; // return true if number of letter in hash <= max

    [[nodiscard]] bool isEqMax() const; // return true if number of letter in hash == max

    [[nodiscard]] int getLen() const; // returns the len of hash

    [[nodiscard]] int getMax() const;

    void setMax(int max_);

    Hash(int max_ = 32);

    void append(char c); // pushes one char at the end of hash

    inline void reset(); // emptifies string

    std::string getHash() const;
};


#endif //LAB1_HASH_H

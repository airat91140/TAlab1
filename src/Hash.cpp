//
// Created by airat on 12.09.2021.
//

#include "Hash.h"

void Hash::append(char c) {
    str.push_back(c);
}

void Hash::reset() {
    str = "";
    str.reserve(max);
}

std::string Hash::getHash() const {
    return str;
}

Hash::Hash(int max_) : max(max_) {
    str.reserve(max_);
}

bool Hash::isUnderOrEqMax() const {
    return str.length() <= max;
}

bool Hash::isEqMax() const {
    return str.length() == max;
}

int Hash::getLen() const {
    return str.length();
}

int Hash::getMax() const {
    return max;
}

void Hash::setMax(int max_) {
    Hash::max = max_;
}

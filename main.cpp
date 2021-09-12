#include <iostream>
#include "CheckStr.h"

int main() {
    CheckStr a;
    std::cout << (a.check("ed2k://|file|abcjcjd|654356|aaaaeeee5454100f|/") ? "true" : "fasle");
    return 0;
}
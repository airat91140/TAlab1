#include <iostream>
#include "Dialogue.h"

// ed2k://|file|имя_файла|размер_файла|хэш_файла|/
// ed2k://|file|qwertyuioopasdfghjklzxcvbnm+_-.txt|000320|0123456789abcdef0123456789abcdef|/


int main(int argc, char *argv[]) {
    try
    {
        Dialogue dialogue(argc, argv);
        dialogue.run();
    }
    catch (const std::exception &ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
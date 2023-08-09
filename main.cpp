#include "ftl.h"
#include "measurement.h"

#include <iostream>

int main(){

    /* Initialization */
    Ftl ftl;
    for(int i = 1; i < PAGES_PER_BLOCK * 3; i++)
    {
        ftl.processWrite(i);
    }
    for(int i = 1; i < PAGES_PER_BLOCK * 3; i++)
    {
        ftl.processWrite(i);
    }
    bool writeResult = ftl.processWrite(PAGES_PER_BLOCK * 3);
    bool readResult = ftl.processRead(PAGES_PER_BLOCK);
    

    std::cout << "Result of processWrite: " << writeResult << std::endl;
    std::cout << "Result of processRead: " << readResult << std::endl;

    return 0;
}
#include "ftl.h"

#include <iostream>

Measurement& mainInstance = Measurement::getInstance();

int main(){

    /* Initialization */
    Ftl ftl;
    for(int i = 1; i < PAGES_PER_BLOCK * 3; i++)
    {
        ftl.processFtl(W, i * SECTORS_PER_PAGE, 2);
    }
    for(int i = 1; i < PAGES_PER_BLOCK * 3; i++)
    {
        ftl.processFtl(R, i * SECTORS_PER_PAGE, 2);
    }
    
    mainInstance.print_stats();
    return 0;
}
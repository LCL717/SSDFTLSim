#include "ftl.h"

#include <iostream>

Measurement& mainInstance = Measurement::getInstance();

int main(){

    /* Initialization */
    Ftl ftl;
    for(int i = 0; i < PAGES_PER_BLOCK * 4; i++)
    {
        ftl.processFtl(W, i);
    }
    for(int i = 0; i < PAGES_PER_BLOCK; i++)
    {
        ftl.processFtl(W, i);
    }
    for(int i = 0; i < PAGES_PER_BLOCK * 2; i++)
    {
        ftl.processFtl(R, i);
    }
    
    mainInstance.print_stats();
    return 0;
}
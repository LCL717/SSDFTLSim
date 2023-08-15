#pragma once

#include "nand.h"
#include "block.h"
#include "measurement.h"

#include <unordered_map>
#include <vector>

#define INVALID         -1
#define GC_THRESHOLD    1
#define MAXERSCNT       10000
#define MAXREADCNT      4

#define R   0
#define W   1

class Ftl{
public:
    Ftl();
    bool processRead(int lpn);
    bool processWrite(int lpn);
    bool updateMap(int lpn, int blockId, int pageId);
    void migratePage(int ppn, Block& block, int pageId);
    bool getUpdateBlock();

    bool processFtl(int request, int lpn);

    /*GC*/
    bool gcHandler();
    Block* pickBlock();

    /*WL*/
    bool wlHandler();
    
    /*RD*/
    bool rdHandler(Block& target);

    /*BB*/
    bool bbHandler(Block &b);
    

    std::unordered_map<int, int> l2p;
    std::vector<Block> blocks;
    std::vector<int> free_blocks;
    Block *updatingBlock;
};
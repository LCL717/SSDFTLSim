#pragma once

#include "nand.h"
#include "block.h"
#include "measurement.h"

#include <unordered_map>
#include <vector>

#define INVALID         -1
#define GC_THRESHOLD    1
#define MAXERSCNT       10000

class Ftl{
public:
    Ftl();
    bool processRead(int lpn);
    bool processWrite(int lpn);
    bool updateMap(int lpn, int blockId, int pageId);
    void migratePage(int ppn, Block& block, int pageId);
    bool getUpdateBlock();

    /*GC*/
    bool gcHandler();
    Block* pickBlock();

    /*WL*/
    bool wlHandler();
    // TODO: GC, WL, RD, and some other ways to read and write
    

    std::unordered_map<int, int> l2p;
    std::vector<Block> blocks;
    std::vector<int> free_blocks;
    Block *updatingBlock;
};
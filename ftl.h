#pragma once

#include "nand.h"
#include "block.h"
#include "measurement.h"

#include <unordered_map>
#include <vector>

#define INVALID         -1
#define GC_THRESHOLD    1

class Ftl{
public:
    Ftl();
    bool processRead(int lpn);
    bool processWrite(int lpn);
    bool updateMap(int lpn, int blockId, int pageId);
    void migratePage(int ppn, Block& block, int pageId);
    bool getUpdateBlock();

    // TODO: GC, WL, RDH, and some other ways to read and write
    bool gcHandler();
    Block* pickBlock();

    std::unordered_map<int, int> l2p;
    std::vector<Block> blocks;
    std::vector<int> free_blocks;
    Block *updatingBlock;
};
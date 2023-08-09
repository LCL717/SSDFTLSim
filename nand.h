#pragma once

#define SECTORS_PER_PAGE  8
#define PAGES_PER_BLOCK   4
#define BLOCKS_PER_DEVICE 4

class Nand {
public:
    int ppn;

    Nand();
    static int getBlockId(int ppn);
    static int getPageId(int ppn);
    static int getPpn(int blockId, int offset);
};
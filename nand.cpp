#include "nand.h"

Nand::Nand() {
}

int Nand::getBlockId(int ppn) {
    int block = ppn / PAGES_PER_BLOCK;
    return block;
}

int Nand::getPageId(int ppn) {
    int page = ppn % PAGES_PER_BLOCK;
    return page;
}

int Nand::getPpn(int blockId, int pageId) {
    return blockId * PAGES_PER_BLOCK + pageId;
}
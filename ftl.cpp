#include "ftl.h"

Ftl::Ftl() : updatingBlock(nullptr), l2p(), blocks(), free_blocks(){
    int pageNum = PAGES_PER_BLOCK * BLOCKS_PER_DEVICE;
    
    for(int i = 0; i < pageNum; i++) {
        l2p[i] = INVALID;
    }
    
    for(int i = 0; i < BLOCKS_PER_DEVICE; i++) {
        Block b(i);
        blocks.push_back(b);
        free_blocks.push_back(i);
    }
}

bool Ftl::processRead(int lpn) {
    int ppn;

    if (l2p[lpn] == INVALID){
        return false;
    }
    else {
        ppn = l2p[lpn];
        return true;
    }
}

bool Ftl::getUpdateBlock(){
    if(updatingBlock != nullptr) {
        updatingBlock->offset += 1;
        if(updatingBlock->validpages <= 0) {
            updatingBlock->status = USED;
            updatingBlock = nullptr;
        }
    }

    if(updatingBlock == nullptr){
        /* get free block to allocate a new position */
        
        if (!free_blocks.empty()) {
            updatingBlock = &(blocks[free_blocks.back()]);
            free_blocks.pop_back();
            updatingBlock->status = INUSE;
        }
        else {
            //TODO: Handle situation with no free blocks
            return false;
        }
    }
    return true;
}

bool Ftl::processWrite(int lpn) {
    getUpdateBlock();

    updatingBlock->write(updatingBlock->offset);
    
    updateMap(lpn, updatingBlock->id, updatingBlock->offset);
    if(free_blocks.size() <= GC_THRESHOLD) {
        gcHandler();
    }
    
    return true;
}

bool Ftl::updateMap(int lpn, int blockId, int pageId) {
    int old_ppn;

    old_ppn = l2p[lpn];
    if(old_ppn != INVALID) {
        //TODO: handle valid page while writing
    }
    else {
        l2p[lpn] = Nand::getPpn(blockId, pageId);
        updatingBlock->lpns[pageId] = lpn;
    }
    return true;
}

bool Ftl::gcHandler(){

    Block* victim = pickBlock();
    if(victim == nullptr){
        return false;
    }
    for(auto lpn : victim->lpns) {
        if(lpn == INVALID) continue;
        getUpdateBlock();
        migratePage(l2p[lpn], *updatingBlock, updatingBlock->offset);
        updateMap(lpn, updatingBlock->id, updatingBlock->offset);
    }
    victim->erase();
    free_blocks.push_back(victim->id);
    return true;

}

Block* Ftl::pickBlock() {
    Block *victim = nullptr;
    for(auto &block : blocks) {
        if (block.status != USED) {
            continue;
        } 
        victim = &block;
    }
    if(victim != nullptr) {
        victim->status = GC;
    }
    return victim;
}

void Ftl::migratePage(int ppn, Block& block, int pageId) {
    /*Read PPN*/
    block.write(pageId);
}
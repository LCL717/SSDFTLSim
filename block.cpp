#include "block.h"

Block::Block(int id) {
    this->id = id;
    offset = 0;
    validpages = PAGES_PER_BLOCK;
    status = FREE;
    for(int i = 0; i < PAGES_PER_BLOCK; i++) {
        lpns[i] = INVALID;
    }
}

void Block::erase() {
    offset = 0;
    validpages = PAGES_PER_BLOCK;
    status = FREE;
    for(int i = 0; i < PAGES_PER_BLOCK; i++) {
        lpns[i] = INVALID;
    }
}

void Block::write(int offset) {
    this->validpages -= 1;
    this->offset = offset;

    if(this->status == FREE){
        this->status = INUSE;
    }
    if(this->offset == PAGES_PER_BLOCK) {
        this->status = USED;
    }
}

void Block::read(int offset) {
    this->offset = offset;
}
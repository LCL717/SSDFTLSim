#include "block.h"

Measurement& measurementInstance = Measurement::getInstance();

Block::Block(int id) {
    this->id = id;
    offset = 0;
    validpages = PAGES_PER_BLOCK;
    status = FREE;
    for(int i = 0; i < PAGES_PER_BLOCK; i++) {
        lpns[i] = INVALID;
    }
    erasecnt = 0;
    readcnt = 0;
}

void Block::erase() {
    offset = 0;
    validpages = PAGES_PER_BLOCK;
    status = FREE;
    for(int i = 0; i < PAGES_PER_BLOCK; i++) {
        lpns[i] = INVALID;
    }
    erasecnt++;
    readcnt = 0;
    measurementInstance.update(ERASE);
}

void Block::write(int offset) {
    this->validpages -= 1;
    this->offset = offset;

    if(this->status == FREE){
        this->status = INUSE;
    }
    if(this->validpages == 0) {
        this->status = USED;
    }
    measurementInstance.update(WRITE);
}

void Block::read(int offset) {
    this->offset = offset;
    readcnt++;
    measurementInstance.update(READ);
}
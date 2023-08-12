#pragma once

#include <vector>
#include "nand.h"
#include "measurement.h"

#define FREE  0
#define INUSE 1
#define USED  2
#define GC    3
#define BAD   4

#define INVALID         -1
#define VALID           1

class Block{
public:
    int offset;
    int status;
    int id;
    int validpages;
    int lpns[PAGES_PER_BLOCK];
    int erasecnt;
    int readcnt;

    Block(int id);
    void erase();
    void write(int offset);
    void read(int offset);
};
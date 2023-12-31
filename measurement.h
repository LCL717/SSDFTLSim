#pragma once

#include <iostream>

#define READPAGEUS      80
#define WRITEPAGEUS     500
#define ERASEBLOCKUS    1500

#define READ            0
#define WRITE           1
#define ERASE           2
#define RDH             3
#define GCH             4
#define RR              5
#define RW              6
#define RE              7

class Measurement{
private:
    int clock;
    int elapsed;
    int request_read;
    int request_write;
    int request_page_read;
    int request_page_write;

    int request_block_erase;

    int pages_read;
    int pages_write;
    int pages_migrated;
    int pages_skipped;
    int pages_overwritten;

    int blocks_erased;

    int rdh_times;
    int gch_times;

    static Measurement instance;
    

public:
    Measurement();
    static Measurement& getInstance() {
        return instance;
    }
    bool print_stats();
    bool reset();
    bool update(int request);

};
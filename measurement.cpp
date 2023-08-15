#include "measurement.h"

Measurement::Measurement(){
    clock = 0;
    elapsed = 0;
    request_read = 0;
    request_write = 0;
    request_page_read = 0;
    request_page_write = 0;
    request_block_erase = 0;

    pages_read = 0;
    pages_write = 0;
    pages_migrated = 0;
    pages_skipped = 0;
    pages_overwritten = 0;

    blocks_erased = 0;

    rdh_times = 0;
    gch_times = 0;
}

bool Measurement::print_stats(){
    std::cout << "Measurement Statistics:\n";
    std::cout << "------------------------\n";
    std::cout << "Elapsed Time: " << elapsed << "\n";
    std::cout << "Read Requests: " << request_read << "\n";
    std::cout << "Write Requests: " << request_write << "\n";
    std::cout << "Block Erase Requsts: " << request_block_erase << "\n";
    std::cout << "Pages Read: " << pages_read << "\n";
    std::cout << "Pages Write: " << pages_write << "\n";
    std::cout << "Blocks Erased: " << blocks_erased << "\n";
    std::cout << "RDH Times: " << rdh_times << "\n";
    std::cout << "GC Times: " << gch_times << "\n";
    return true;
}

bool Measurement::reset(){
    clock = 0;
    elapsed = 0;
    request_read = 0;
    request_write = 0;
    request_page_read = 0;
    request_page_write = 0;

    pages_read = 0;
    pages_write = 0;
    pages_migrated = 0;
    pages_skipped = 0;
    pages_overwritten = 0;

    blocks_erased = 0;
    return true;
}

bool Measurement::update(int request){
    switch (request)
    {
    case READ:
        instance.elapsed += READPAGEUS;
        instance.pages_read += 1;
        break;
    case WRITE:
        instance.elapsed += WRITEPAGEUS;
        instance.pages_write += 1;
        break;
    case ERASE:
        instance.elapsed += ERASEBLOCKUS;
        blocks_erased += 1;
        break;
    case RDH:
        rdh_times += 1;
        break;
    case GCH:
        gch_times += 1;
        break;
    case RR:
        request_read += 1;
    case RW:
        request_write += 1;
    default:
        break;
    }
    return true;
}

Measurement Measurement::instance;
#include "measurement.h"

Measurement::Measurement(){
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
}

bool Measurement::print_stats(){
    std::cout << "Measurement Statistics:\n";
    std::cout << "------------------------\n";
    std::cout << "Clock: " << clock << "\n";
    std::cout << "Elapsed Time: " << elapsed << "\n";
    std::cout << "Read Requests: " << request_read << "\n";
    std::cout << "Write Requests: " << request_write << "\n";
    std::cout << "Page Read Requests: " << request_page_read << "\n";
    std::cout << "Page Write Requests: " << request_page_write << "\n";
    std::cout << "Pages Read: " << pages_read << "\n";
    std::cout << "Pages Write: " << pages_write << "\n";
    std::cout << "Pages Migrated: " << pages_migrated << "\n";
    std::cout << "Pages Skipped: " << pages_skipped << "\n";
    std::cout << "Pages Overwritten: " << pages_overwritten << "\n";
    std::cout << "Blocks Erased: " << blocks_erased << "\n";
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
        instance.request_read += 1;
        break;
    case WRITE:
        instance.elapsed += WRITEPAGEUS;
        instance.request_write += 1;
        break;
    case ERASE:
        instance.elapsed += ERASEBLOCKUS;
        break;
    default:
        break;
    }
    return true;
}

Measurement Measurement::instance;
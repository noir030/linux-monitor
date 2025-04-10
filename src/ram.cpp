#include "ram.h"
#include <fstream>
#include <iostream>

RAM::RAM() {}

std::string RAM::getRAMSize() {
    std::ifstream stream("/proc/meminfo");
    if (!stream.is_open()) {
        std::cout << "Unable to open /proc/meminfo" << std::endl;
        return "";
    }
    std::string size, e;
    stream >> size >> size;
    int num = atoi(size.c_str());
    int gb = (num / 1024) / 1024;
    int mb = (num - gb * 1024 * 1024) / 1024;
    int kb = (num - (gb * 1024 * 1024 + mb * 1024));
    
    if (gb > 0) 
       e = std::to_string(gb) + " Gb ";
    else
       e = "";
    if (mb > 0)
       e += std::to_string(mb) + " Mb ";
    if (kb > 0)
       e += std::to_string(kb) + " Kb ";

    return e;
}

std::string RAM::getUsedRAMSize() {
    std::ifstream stream("/proc/meminfo");
    if (!stream.is_open()) {
        std::cout << "Unable to open /proc/meminfo" << std::endl;
        return "";
    }

    std::string size;
    int free = 0, total = 0;

    stream >> size >> size;
    total = atoi(size.c_str());

    for (int i = 0 ; i < 3 ; i++) {
        stream >> size >> size >> size; 
        free += atoi(size.c_str());
    }

    int used = total - free;

    int gb = used / 1024 / 1024;
    int mb = (used - gb * 1024 * 1024) / 1024;
    int kb = (used - ((mb * 1024) + (gb * 1024 * 1024)));

    std::string e = "";
    if (gb > 0) 
       e = std::to_string(gb) + " Gb ";
    if (mb > 0)
        e += std::to_string(mb) + " Mb ";
    if (kb > 0)
       e += std::to_string(kb) + " Kb ";

    return e;
}
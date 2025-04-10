#ifndef CPU_H
#define CPU_H

#include <vector>

class CPU {
public:
    CPU();
    std::vector<float> readCpuStats();
    int getCpuLoad(int dt);
};

#endif 

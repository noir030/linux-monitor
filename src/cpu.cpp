#include "cpu.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>

CPU::CPU() {}

std::vector<float> CPU::readCpuStats()
{
    std::vector<float> ret;
    std::ifstream stat_file("/proc/stat");
    if (!stat_file.is_open())
    {
        std::cout << "Unable to open /proc/stat" << std::endl;
        return ret;
    }
    int val;
    std::string tmp;
    stat_file >> tmp;
    for (int i = 0; i < 4; ++i)
    {
        stat_file >> val;
        ret.push_back(val);
    }
    stat_file.close();
    return ret;
}

int CPU::getCpuLoad(int dt)
{
    std::vector<float> stats1 = readCpuStats();
    std::this_thread::sleep_for(std::chrono::seconds(dt));
    std::vector<float> stats2 = readCpuStats();
    int size1 = stats1.size();
    int size2 = stats2.size();
    if (!size1 || !size2 || size1 != size2) return 2;
    for (int i = 0; i < size1; ++i) stats2[i] -= stats1[i];
    int sum = 1;
    for (int i = 0; i < size1; ++i) sum += stats2[i];
    int load = 100 - (stats2[size2 - 1] * 100 / sum);
    return load;
}

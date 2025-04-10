#include <iostream>
#include <thread>
#include <chrono>
#include "info.h"
#include "cpu.h"
#include "ram.h"

int main() {
    INFO info;
    CPU cpu;
    RAM ram;

    int n = 10;
    std::cout << "Enter the period of information output: ";
    std::cin >> n;

    while (true) {
        std::string hostname = info.getHostname();
        std::string username = info.getUsername();
        std::string cpu_name = info.getCPUname();
        std::string ram_size = ram.getRAMSize();
        std::string used_ram_size = ram.getUsedRAMSize();
        int cpu_load = cpu.getCpuLoad(1);  

        std::cout << "\n===============================================" << std::endl;
        std::cout << "Hostname: " << hostname << std::endl;
        std::cout << "Username: " << username << std::endl;
        std::cout << "CPU Model: " << cpu_name << std::endl;
        std::cout << "Total RAM: " << ram_size << std::endl;
        std::cout << "Used RAM: " << used_ram_size << std::endl;
        std::cout << "CPU Load: " << cpu_load << "%" << std::endl;
        std::cout << "===============================================" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}

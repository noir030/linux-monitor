#include "info.h"
#include <iostream>
#include <fstream>
#include <pwd.h>
#include <unistd.h>

INFO::INFO() {}

std::string INFO::getHostname() {
    std::ifstream stream("/proc/sys/kernel/hostname"); 
    if (!stream.is_open()) {
        std::cout << "Unable to open /proc/sys/kernel/hostname" << std::endl;
        return "";
    }
    std::string hostname;
    getline(stream, hostname);
    return hostname;
}

std::string INFO::getUsername() {
    uid_t uid = geteuid();
    passwd *pw = getpwuid(uid);
    if (pw) {
        return pw->pw_name;
    }
    else {
        std::cerr << "Unable to get username" << std::endl;
        return "";
    }
}

std::string INFO::getCPUname() {
    std::ifstream stream("/proc/cpuinfo");
    if (!stream.is_open()) {
        std::cout << "Unable to open /proc/cpuinfo" << std::endl;
        return "";
    }
    std::string cpu_name;
    for(int i = 0; i < 16; i++) stream >> cpu_name; 
    getline(stream, cpu_name);
    return cpu_name;
}

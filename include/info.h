#ifndef INFO_H
#define INFO_H

#include <string>

class INFO {
public:
    INFO();
    std::string getHostname();
    std::string getUsername();
    std::string getCPUname();
};

#endif 
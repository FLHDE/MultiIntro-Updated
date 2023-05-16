#pragma once

#include "Common.h"
#include <string>

struct IntroConfig
{
    bool randomIntroOnMenuVisit = true;
    int introAmount = 0;
};

class ConfigReader
{
public:
    /// @brief Retrieves the config file in the given path.
    /// @param path Path that points to the config (.ini) file.
    /// @param config Config that will be filled with the information from the config file.
    void GetConfig(const std::string &path, struct IntroConfig &config);

private:
    /// @brief Common.dll INI_Reader class.
    INI_Reader ir;
};

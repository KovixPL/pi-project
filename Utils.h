#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

namespace Utils {
    std::string getFloatWithPrecision(const float& val, const int& precision);

    std::string getFormalBookType(const char& bookType);

    std::string getFormalCoverType(const std::string& coverType);
}

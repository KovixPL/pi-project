#include "Utils.h"

std::string Utils::getFloatWithPrecision(const float& val, const int& precision) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << val;
    return ss.str();
}

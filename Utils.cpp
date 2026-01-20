#include "Utils.h"

std::string Utils::getFloatWithPrecision(const float& val, const int& precision) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << val;
    return ss.str();
}

std::string Utils::getFormalBookType(const char& bookType) {
    switch(bookType) {
        case 'A': return "Audio Book";
        case 'E': return "Ebook";
        case 'P': return "Ksiazka";
    }
    return "Produkt";
}

std::string Utils::getFormalCoverType(const std::string& coverType) {
    if (coverType == "hardCover") return "Twarda";
    else if (coverType == "paperBack") return "Miekka";
    return "NULL";
}

std::string Utils::boolToPolish(bool b) {
    switch(b) {
    case true:
        return "TAK";
    default: return "NIE";
    }
    return "NIE";
}

std::string Utils::engTextBoolToPolish(std::string engBool) {
    if (engBool == "true") return "TAK";
    else return "NIE";
}

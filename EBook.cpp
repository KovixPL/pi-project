#include "EBook.h"
#include "EnumConvert.h"
#include "Utils.h"

void EBook::compare(const Product& p) {
}

float EBook::getFileSizeMB() {
    return fileSizeMB;
}

Format EBook::getFormat() {
    return format;
}

std::string EBook::toString() const {
    return "A;" + std::to_string(id) + ";"
    + title + ";"
    + author + ";"
    + Utils::getFloatWithPrecision(price, 2) + ";"
    + std::to_string(amount) + ";"
    + EnumConvert::genreToString(genre) + ";"
    + Utils::getFloatWithPrecision(fileSizeMB, 2) + ";"
    + EnumConvert::formatToString(format);
}

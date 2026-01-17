#include "PaperBook.h"
#include "EnumConvert.h"
#include "Utils.h"

void PaperBook::compare(const Product& p) {
}

int PaperBook::getPageCount() {
    return pageCount;
}

CoverType PaperBook::getCoverType() {
    return coverType;
}

bool PaperBook::getHasIllustrations() {
    return hasIllustrations;
}

std::string PaperBook::toString() const {
    std::string illustrations = hasIllustrations ? "true" : "false";

    return "A;" + std::to_string(id) + ";"
    + title + ";"
    + author + ";"
    + Utils::getFloatWithPrecision(price, 2) + ";"
    + std::to_string(amount) + ";"
    + EnumConvert::genreToString(genre) + ";"
    + std::to_string(pageCount) + ";"
    + EnumConvert::coverTypeToString(coverType) + ";"
    + illustrations;
}

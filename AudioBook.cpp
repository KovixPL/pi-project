#include "AudioBook.h"
#include "EnumConvert.h"
#include "Utils.h"

void AudioBook::compare(const Product& p) {
}

float AudioBook::getLengthHours() {
    return lengthHours;
}

bool AudioBook::getHasMultipleNarrators() {
    return hasMultipleNarrators;
}

bool AudioBook::getIsAiNarrated() {
    return isAiNarrated;
}

bool AudioBook::getHasSoundEffects() {
    return hasSoundEffects;
}

std::string AudioBook::toString() const {
    std::string narrators = hasMultipleNarrators ? "true" : "false";
    std::string ai = isAiNarrated ? "true" : "false";
    std::string sound = hasSoundEffects ? "true" : "false";

    return "A;" + std::to_string(id) + ";"
    + title + ";"
    + author + ";"
    + Utils::getFloatWithPrecision(price, 2) + ";"
    + std::to_string(amount) + ";"
    + EnumConvert::genreToString(genre) + ";"
    + Utils::getFloatWithPrecision(lengthHours, 2) + ";"
    + narrators + ";"
    + ai + ";"
    + sound;
}

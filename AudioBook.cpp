#include "AudioBook.h"
#include "EnumConvert.h"
#include "Utils.h"

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

    return u8"A;" + std::to_string(id) + ";"
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

void AudioBook::displayInfo() const {
    std::string ts = toString();
    std::stringstream ss(ts);

    std::string bookType,id,title,author,price,amount,genre,
    lengthHours,hasMultipleNarrators,isAiNarrated,hasSoundEffects;

    std::getline(ss, bookType, ';');
    char bT = bookType[0];
    bookType = Utils::getFormalBookType(bT);

    std::getline(ss, id, ';');
    std::getline(ss, title, ';');
    std::getline(ss, author, ';');
    std::getline(ss, price, ';');
    std::getline(ss, amount, ';');
    std::getline(ss, genre, ';');
    std::getline(ss, lengthHours, ';');



    std::getline(ss, hasMultipleNarrators, ';');
    std::getline(ss, isAiNarrated, ';');
    std::getline(ss, hasSoundEffects);

    std::string narratorsPolish = Utils::engTextBoolToPolish(hasMultipleNarrators);
    std::string aiPolish = Utils::engTextBoolToPolish(isAiNarrated);
    std::string soundPolish = Utils::engTextBoolToPolish(hasSoundEffects);

    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Typ: " << bookType << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Tytul: " << title << std::endl;
    std::cout << "Autor: " << author << std::endl;
    std::cout << "Cena: " << price << std::endl;
    std::cout << "Ilosc: " << amount << std::endl;
    std::cout << "Gatunek: " << genre << std::endl;
    std::cout << "Dlugosc w godzinach: " << lengthHours << std::endl;
    std::cout << "Ma wielu narratorow: " << narratorsPolish << std::endl;
    std::cout << "Ma narracje AI: " << aiPolish << std::endl;
    std::cout << "Ma efekty dzwiekowe: " << soundPolish << std::endl;
    std::cout << "------------------------------" << std::endl;
}

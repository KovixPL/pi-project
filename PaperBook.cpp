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

    return "P;" + std::to_string(id) + ";"
    + title + ";"
    + author + ";"
    + Utils::getFloatWithPrecision(price, 2) + ";"
    + std::to_string(amount) + ";"
    + EnumConvert::genreToString(genre) + ";"
    + std::to_string(pageCount) + ";"
    + EnumConvert::coverTypeToString(coverType) + ";"
    + illustrations;
}

void PaperBook::displayInfo() const {
    std::string ts = toString();
    std::stringstream ss(ts);

    std::string bookType,id,title,author,price,amount,genre,
    pageCount,coverType,hasIllustrations;

    std::getline(ss, bookType, ';');
    char bT = bookType[0];
    bookType = Utils::getFormalBookType(bT);

    std::getline(ss, id, ';');
    std::getline(ss, title, ';');
    std::getline(ss, author, ';');
    std::getline(ss, price, ';');
    std::getline(ss, amount, ';');
    std::getline(ss, genre, ';');
    std::getline(ss, pageCount, ';');
    std::getline(ss, coverType, ';');
    std::getline(ss, hasIllustrations, ';');

    std::string illustrationsPolish = Utils::engTextBoolToPolish(hasIllustrations);

    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Typ: " << bookType << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Tytul: " << title << std::endl;
    std::cout << "Autor: " << author << std::endl;
    std::cout << "Cena: " << price << std::endl;
    std::cout << "Ilosc: " << amount << std::endl;
    std::cout << "Gatunek: " << genre << std::endl;
    std::cout << "Ilosc stron: " << pageCount << std::endl;
    std::cout << "Typ okladki: " << Utils::getFormalCoverType(coverType) << std::endl;
    std::cout << "Ma ilustracje: " << illustrationsPolish << std::endl;
    std::cout << "------------------------------" << std::endl;
}


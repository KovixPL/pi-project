#include "EBook.h"
#include "EnumConvert.h"
#include "Utils.h"

float EBook::getFileSizeMB() {
    return fileSizeMB;
}

Format EBook::getFormat() {
    return format;
}

std::string EBook::toString() const {
    return "E;" + std::to_string(id) + ";"
    + title + ";"
    + author + ";"
    + Utils::getFloatWithPrecision(price, 2) + ";"
    + std::to_string(amount) + ";"
    + EnumConvert::genreToString(genre) + ";"
    + Utils::getFloatWithPrecision(fileSizeMB, 2) + ";"
    + EnumConvert::formatToString(format);
}

void EBook::displayInfo() const {
    std::string ts = toString();
    std::stringstream ss(ts);

    std::string bookType,id,title,author,price,amount,genre,fileSizeMB,format;

    std::getline(ss, bookType, ';');
    char bT = bookType[0];
    bookType = Utils::getFormalBookType(bT);

    std::getline(ss, id, ';');
    std::getline(ss, title, ';');
    std::getline(ss, author, ';');
    std::getline(ss, price, ';');
    std::getline(ss, amount, ';');
    std::getline(ss, genre, ';');
    std::getline(ss, fileSizeMB, ';');
    std::getline(ss, format, ';');

    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Typ: " << bookType << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Tytul: " << title << std::endl;
    std::cout << "Autor: " << author << std::endl;
    std::cout << "Cena: " << price << std::endl;
    std::cout << "Ilosc: " << amount << std::endl;
    std::cout << "Gatunek: " << genre << std::endl;
    std::cout << "Rozmiar pliku w MB: " << fileSizeMB << std::endl;
    std::cout << "Format: " << format << std::endl;
    std::cout << "------------------------------" << std::endl;
}

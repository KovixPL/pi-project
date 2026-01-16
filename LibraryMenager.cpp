#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>

#include "LibraryMenager.h"
#include "AudioBook.h"
#include "EBook.h"
#include "PaperBook.h"

std::vector<std::string> LibraryMenager::splitLine(std::string line, char delimiter) {
    std::vector<std::string> v;
    std::stringstream sstream(line);
    std::string part;

    while (std::getline(sstream, part, delimiter)) {
        v.push_back(part);
    }

    return v;
}

Genre LibraryMenager::stringToGenre(std::string strGenre) {
    if (strGenre == "fantasy") return Genre::fantasy;
    if (strGenre == "scienceFiction") return Genre::scienceFiction;
    if (strGenre == "horror") return Genre::horror;
    if (strGenre == "crime") return Genre::crime;
    if (strGenre == "romance") return Genre::romance;
    throw std::runtime_error("ERROR: INCORRECT BOOK GENRE.");
}

CoverType LibraryMenager::stringToCoverType(std::string strCover) {
    if (strCover == "hardCover") return CoverType::hardCover;
    if (strCover == "paperBack") return CoverType::paperBack;
    throw std::runtime_error("ERROR: INCORRECT BOOK COVER TYPE.");
}

Format LibraryMenager::stringToFormat(std::string strFormat) {
    if (strFormat == "PDF") return Format::PDF;
    if (strFormat == "EPUB") return Format::EPUB;
    throw std::runtime_error("ERROR: INCORRECT BOOK FORMAT.");
}

void LibraryMenager::createBook(char bookType, std::vector<std::string> bookInfo) {
    int id = std::stoi(bookInfo.at(1));
    std::string title = bookInfo.at(2);
    std::string author = bookInfo.at(3);
    float price = std::stof(bookInfo.at(4));
    int amount = std::stoi(bookInfo.at(5));
    Genre genre = stringToGenre(bookInfo.at(6));

    switch(bookType) {
        case 'A': {
            float lengthHours = std::stof(bookInfo.at(7));
            bool hasMultipleNarrators = bookInfo.at(8) == "true";
            bool isAiNarrated = bookInfo.at(9) == "true";
            bool hasSoundEffects = bookInfo.at(10) == "true";

            AudioBook* ab = new AudioBook(
                id,
                title,
                author,
                price,
                amount,
                genre,
                lengthHours,
                hasMultipleNarrators,
                isAiNarrated,
                hasSoundEffects
            );
            products.push_back(ab);
            break;
        }
        case 'E': {
            float fileSizeMB = std::stof(bookInfo.at(7));
            Format format = stringToFormat(bookInfo.at(8));

            EBook* ebook = new EBook(
                id,
                title,
                author,
                price,
                amount,
                genre,
                fileSizeMB,
                format
            );

            products.push_back(ebook);
            break;
        }
        case 'P': {
            int pageCount = std::stoi(bookInfo.at(7));
            CoverType cover = stringToCoverType(bookInfo.at(8));
            bool hasIllustrations = bookInfo.at(9) == "true";

            PaperBook* pb = new PaperBook(
                id,
                title,
                author,
                price,
                amount,
                genre,
                pageCount,
                cover,
                hasIllustrations
            );

            products.push_back(pb);
        }
    }
}

LibraryMenager::LibraryMenager(std::string dbFile) {
    std::ifstream db(dbFile);

    if (!db.is_open()) {
        throw std::runtime_error("ERROR: DATABASE COULD NOT BE LOADED.");
    }

    std::string line;

    while (std::getline(db, line)) {
        std::vector<std::string> bookInfo = splitLine(line, ';');
        char bookType = bookInfo.front()[0];
        createBook(bookType,bookInfo);
    }

    std::cout << products.size() << std::endl;

    db.close();
}


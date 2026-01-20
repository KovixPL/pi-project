#include <stdexcept>
#include <iostream>

#include "EnumConvert.h"

Genre EnumConvert::stringToGenre(const std::string& strGenre) {
    if (strGenre == "fantasy") return Genre::fantasy;
    if (strGenre == "scienceFiction") return Genre::scienceFiction;
    if (strGenre == "horror") return Genre::horror;
    if (strGenre == "crime") return Genre::crime;
    if (strGenre == "romance") return Genre::romance;
    throw std::runtime_error("BLAD: Nieprawidlowa nazwa gatunku.");
}

CoverType EnumConvert::stringToCoverType(const std::string& strCover) {
    if (strCover == "hardCover") return CoverType::hardCover;
    if (strCover == "paperBack") return CoverType::paperBack;
    throw std::runtime_error("BLAD: Nieprawidlowa nazwa ok³adki.");
}

Format EnumConvert::stringToFormat(const std::string& strFormat) {
    if (strFormat == "PDF") return Format::PDF;
    if (strFormat == "EPUB") return Format::EPUB;
    throw std::runtime_error("BLAD: Nieprawidlowy format.");
}

std::string EnumConvert::genreToString(const Genre& genre) {
    switch(genre) {
    case Genre::crime:
        return "crime";

    case Genre::fantasy:
        return "fantasy";

    case Genre::horror:
        return "horror";

    case Genre::romance:
        return "romance";

    case Genre::scienceFiction:
        return "scienceFiction";
    }
    std::cout << genre << std::endl;
    throw std::runtime_error("BLAD: Nieprawidlowy gatunek.");
}

std::string EnumConvert::coverTypeToString(const CoverType& coverType) {
    switch(coverType) {
    case CoverType::hardCover:
        return "hardCover";

    case CoverType::paperBack:
        return "paperBack";
    }
    throw std::runtime_error("BLAD: Nieprawidlowa ok³adka.");
}

std::string EnumConvert::formatToString(const Format& format) {
    switch(format) {
    case Format::EPUB:
        return "EPUB";

    case Format::PDF:
        return "PDF";
    }
    throw std::runtime_error("BLAD: Nieprawidlowy format.");
}



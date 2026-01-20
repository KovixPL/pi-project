#include <stdexcept>
#include <iostream>
#include <windows.h>

#include "Product.h"
#include "AudioBook.h"
#include "EBook.h"
#include "PaperBook.h"
#include "LibraryMenager.h"
#include "EnumConvert.h"

const std::string DB_FILE_PATH = "db.txt";

void displayMainMenu() {
    std::cout << std::endl;
    std::cout << "###SYSTEM ZARZADZANIA KSIEGARNIA###" << std::endl;
    std::cout << std::endl;
    std::cout << "***MENU GLOWNE***" << std::endl;

    std::cout << "1: Wyszukiwanie" << std::endl;
    std::cout << "2: Zarzadzanie stanem" << std::endl;
    std::cout << "3: Raporty" << std::endl;
    std::cout << "4: Zapisz aktualny stan" << std::endl;

    std::cout << ">";
}

void handleSearchMenu(LibraryMenager& menager) {
    while(true) {
        char choice;
        std::cout << std::endl;
        std::cout << "***WYSZUKIWANIE KSIAZEK***" << std::endl;
        std::cout << "1: Po id" << std::endl;
        std::cout << "2: Po tytule" << std::endl;
        std::cout << "3: Po autorze" << std::endl;
        std::cout << "4: Po zakresie cenowym" << std::endl;
        std::cout << "5: Menu glowne" << std::endl;

        std::cout << ">";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch(choice) {
        case '1': {
            int id;
            std::cout << "Podaj id" << std::endl;
            std::cout << ">";
            std::cin >> id;
            std::cin.ignore(1000, '\n');

            menager.searchBooksById(id);
            break;
        }
        case '2': {
            std::string title;
            std::cout << "Podaj tytul" << std::endl;
            std::cout << ">";
            getline(std::cin, title);

            menager.searchBooksByTitle(title);
            break;
        }
        case '3': {
            std::string author;
            std::cout << "Podaj autora" << std::endl;
            std::cout << ">";
            std::getline(std::cin, author);

            menager.searchBooksByAuthor(author);
            break;
        }
        case '4': {
            int minPrice;
            int maxPrice;
            std::cout << "Podaj minimalna cene" << std::endl;
            std::cout << ">";
            std::cin >> minPrice;

            std::cout << "Podaj maksymalna cene" << std::endl;
            std::cout << ">";
            std::cin >> maxPrice;

            menager.searchByPriceRange(minPrice, maxPrice);
            break;
        }
        }
        if(choice == '5') break;
    }
}

void handleBookSell(LibraryMenager& menager) {
    int id;
    int amountToSell;
    std::cout << "Podaj id" << std::endl;
    std::cout << ">";
    std::cin >> id;

    std::cout << "Ile chcesz sprzedac?" << std::endl;
    std::cout << ">";
    std::cin >> amountToSell;

    std::cin.ignore(1000, '\n');

    menager.sellBookById(id, amountToSell);
}

void handleRestock(LibraryMenager& menager) {
    int id;
    int amountToRestock;
    std::cout << "Podaj id" << std::endl;
    std::cout << ">";
    std::cin >> id;

    std::cout << "Ilosc ksiazek w dostawie" << std::endl;
    std::cout << ">";
    std::cin >> amountToRestock;

    std::cin.ignore(1000, '\n');

    menager.restockBookById(id, amountToRestock);
}

void handleBookAddition(LibraryMenager& menager) {
    std::string bookType;
    std::cout << "Podaj typ ksiazki (\"AudioBook\", \"EBook\", \"Papierowa\")" << std::endl;
    std::cout << ">";

    std::cin >> bookType;
    std::cin.ignore(1000, '\n');

    if (bookType != "AudioBook" && bookType != "EBook" && bookType != "Papierowa") {
        std::cout << "BLAD: Podano nieprawidlowy typ ksiazki." << std::endl;
        return;
    }

    int id;
    std::string title;
    std::string author;
    float price;
    int amount;
    Genre genre;

    std::cout << "Podaj id" << std::endl;
    std::cout << ">";
    std::cin >> id;
    std::cin.ignore(1000, '\n');

    if (menager.idAlreadExists(id)) {
        std::cout << "BLAD: Ksiazka o podanym id juz istnieje w bazie." << std::endl;
        return;
    }

    std::cout << "Podaj tytul" << std::endl;
    std::cout << ">";
    std::cin >> title;
    std::cin.ignore(1000, '\n');

    std::cout << "Podaj autora" << std::endl;
    std::cout << ">";
    std::cin >> author;
    std::cin.ignore(1000, '\n');

    std::cout << "Podaj cene" << std::endl;
    std::cout << ">";
    std::cin >> price;
    std::cin.ignore(1000, '\n');

    std::cout << "Podaj ilosc" << std::endl;
    std::cout << ">";
    std::cin >> amount;
    std::cin.ignore(1000, '\n');

    std::string strGenre;
    std::cout << "Podaj gatunek (\"fantasy\", \"scienceFiction\", \"horror\", \"crime\", \"romance\")" << std::endl;
    std::cout << ">";
    std::cin >> strGenre;
    std::cin.ignore(1000, '\n');

    genre = EnumConvert::stringToGenre(strGenre);

    if (bookType == "AudioBook") {
        float lengthHours;
        bool hasMultipleNarrators;
        bool isAiNarrated;
        bool hasSoundEffects;

        std::cout << "Podaj dlugosc w godzinach" << std::endl;
        std::cout << ">";
        std::cin >> lengthHours;
        std::cin.ignore(1000, '\n');

        std::string narrators;
        std::cout << "Ma wielu narratorow? (T/N)" << std::endl;
        std::cout << ">";
        std::cin >> narrators;
        std::cin.ignore(1000, '\n');

        hasMultipleNarrators = narrators == "T" ? true : false;

        std::string aiNarration;
        std::cout << "Ma narracje AI? (T/N)" << std::endl;
        std::cout << ">";
        std::cin >> aiNarration;
        std::cin.ignore(1000, '\n');

        isAiNarrated = aiNarration == "T" ? true : false;

        std::string soundEffects;
        std::cout << "Ma efekty dzwiekowe? (T/N)" << std::endl;
        std::cout << ">";
        std::cin >> soundEffects;
        std::cin.ignore(1000, '\n');

        isAiNarrated = soundEffects == "T" ? true : false;

        menager.addAudioBook(id,title,author,price,amount,genre,lengthHours,hasMultipleNarrators,isAiNarrated,hasSoundEffects);
        if(!menager.getHasUnsavedChanges()) menager.setHasUnsavedChanges(true);
        return;

    } else if (bookType == "EBook") {
        float fileSizeMB;
        Format format;

        std::string strFormat;

        std::cout << "Podaj rozmiar pliku w MB" << std::endl;
        std::cout << ">";
        std::cin >> fileSizeMB;
        std::cin.ignore(1000, '\n');

        std::cout << "Podaj format (\"PDF\", \"EPUB\")" << std::endl;
        std::cout << ">";
        std::cin >> strFormat;
        std::cin.ignore(1000, '\n');

        format = EnumConvert::stringToFormat(strFormat);

        menager.addEBook(id,title,author,price,amount,genre,fileSizeMB,format);
        if(!menager.getHasUnsavedChanges()) menager.setHasUnsavedChanges(true);

        return;
    } else if (bookType == "Papierowa") {
        int pageCount;
        CoverType coverType;
        bool hasIllustrations;

        std::cout << "Podaj ilosc stron" << std::endl;
        std::cout << ">";
        std::cin >> pageCount;
        std::cin.ignore(1000, '\n');

        std::string strCover;
        std::cout << "Podaj typ okladki (Twarda/Miekka)" << std::endl;
        std::cout << ">";
        std::cin >> strCover;
        std::cin.ignore(1000, '\n');

        strCover = strCover == "Twarda" ? "hardCover" : "paperBack";

        coverType = EnumConvert::stringToCoverType(strCover);

        std::string illus;
        std::cout << "Ma ilustracje? (T/N)" << std::endl;
        std::cout << ">";
        std::cin >> illus;
        std::cin.ignore(1000, '\n');

        hasIllustrations = illus == "T" ? true : false;
        menager.addPaperBook(id,title,author,price,amount,genre,pageCount,coverType,hasIllustrations);
        if(!menager.getHasUnsavedChanges()) menager.setHasUnsavedChanges(true);
    }
}

void handleBookRemoval(LibraryMenager& menager) {
    int id;
    std::cout << "Podaj id" << std::endl;
    std::cin >> id;
    std::cin.ignore(1000, '\n');

    menager.removeBookById(id);
}

void handlePriceChange(LibraryMenager& menager) {
    int id;
    std::cout << "Podaj id" << std::endl;
    std::cin >> id;
    std::cin.ignore(1000, '\n');

    float newPrice;
    std::cout << "Podaj nowa cene" << std::endl;
    std::cin >> newPrice;
    std::cin.ignore(1000, '\n');

    menager.changeBookPriceById(id, newPrice);
}

void handleManagementMenu(LibraryMenager& menager) {
    while(true) {
        char choice;
        std::cout << std::endl;
        std::cout << "***ZARZADZANIE STANEM***" << std::endl;
        std::cout << "1: Sprzedaz po id" << std::endl;
        std::cout << "2: Dostawa ksiazki" << std::endl;
        std::cout << "3: Dodaj ksiazke" << std::endl;
        std::cout << "4: Usun ksiazke" << std::endl;
        std::cout << "5: Zmien cene ksiazki po id" << std::endl;
        std::cout << "6: Menu glowne" << std::endl;

        std::cout << ">";

        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch(choice) {
            case '1': {
                handleBookSell(menager);
                break;
            }
            case '2': {
                handleRestock(menager);
                break;
            }
            case '3': {
                handleBookAddition(menager);
                break;
            }
            case '4': {
                handleBookRemoval(menager);
                break;
            }
            case '5': {
                handlePriceChange(menager);
                break;
            }
        }
        if(choice == '6') break;
    }
}

void handleBookCount(LibraryMenager& menager) {
    int bookCount = menager.getAllBookCount();
    std::cout << "Ilosc wszystkich ksiazek: " << bookCount << std::endl;
}

void handleBookValue(LibraryMenager& menager) {
    int allBookValue = menager.getAllBookValue();
    std::cout << "Wartosc wszystkich ksiazek: " << allBookValue << std::endl;
}

void handleBookShortage(LibraryMenager& menager) {
    menager.displayShortage();
}

void handleStatsMenu(LibraryMenager& menager) {
    while(true) {
        char choice;
        std::cout << std::endl;
        std::cout << "***STATYSTYKI KSIEGARNI***" << std::endl;
        std::cout << "1: Ilosc wszystkich ksiazek" << std::endl;
        std::cout << "2: Wartosc wszystkich ksiazek" << std::endl;
        std::cout << "3: Wszystkie ksiazki gdzie ilosc mniejsza niz 5" << std::endl;
        std::cout << "4: Menu glowne" << std::endl;

        std::cout << ">";
        std::cin.ignore(1000, '\n');

        std::cin >> choice;

        switch(choice) {
            case '1': {
                handleBookCount(menager);
                break;
            }
            case '2': {
                handleBookValue(menager);
                break;
            }
            case '3': {
                handleBookShortage(menager);
                break;
            }
        }
        if (choice == '4') break;
    }
}

void handleDataBaseSave(LibraryMenager& menager) {
    menager.saveAll();
}

int main()
{
    try {
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
        LibraryMenager menager(DB_FILE_PATH);

        while(true) {
            char uiChoice;
            displayMainMenu();
            std::cin >> uiChoice;

            switch (uiChoice) {
            case '1':
                try {
                    handleSearchMenu(menager);
                    break;
                } catch(std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }

            case '2':
                try {
                    handleManagementMenu(menager);
                    break;
                } catch(std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
            case '3':
                try {
                    handleStatsMenu(menager);
                    break;
                } catch(std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
            case '4':
                try {
                    handleDataBaseSave(menager);
                    break;
                } catch(std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }

    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

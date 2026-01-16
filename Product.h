#pragma once // to prevent multiple imports
#include <string>

enum Genre {
    fantasy,
    scienceFiction,
    horror,
    crime,
    romance
};

enum CoverType {
    hardCover,
    paperBack
};

enum Format {
    PDF,
    EPUB
};

class Product {
protected:
    int id;
    std::string title;
    std::string author;
    float price;
    int amount;
    Genre genre;

public:
    Product(int id, std::string title, std::string author, Genre genre, float price, int amount);

    virtual ~Product() {}

    virtual void compare(const Product& p) = 0;

    void sell();

    void changePrice(float newPrice);
};


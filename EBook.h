#pragma once // to prevent multiple imports
#include <string>
#include "product.h"

class EBook : public Product {
private:
    float fileSizeMB;
    Format format;

public:
    EBook(
    int id,
    std::string title,
    std::string author,
    float price,
    int amount,
    Genre genre,
    float fileSizeMB,
    Format format
    ) : Product(id, title, author, genre, price, amount) {}

    ~EBook() {}

    void compare(const Product& p);
};



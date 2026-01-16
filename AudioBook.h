#pragma once // to prevent multiple imports
#include <string>
#include "product.h"

class AudioBook : public Product {
private:
    float lengthHours;
    bool hasMultipleNarrators;
    bool isAiNarrated;
    bool hasSoundEffects;

public:
    AudioBook(
    int id,
    std::string title,
    std::string author,
    float price,
    int amount,
    Genre genre,
    float lengthHours,
    bool hasMultipleNarrators,
    bool isAiNarrated,
    bool hasSoundEffects
    ) : Product(id, title, author, genre, price, amount) {}

    ~AudioBook() {}

    void compare(const Product& p);
};



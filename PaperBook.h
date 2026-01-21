#pragma once // to prevent multiple imports
#include <string>
#include "product.h"

class PaperBook : public Product {
private:
    int pageCount;
    CoverType coverType;
    bool hasIllustrations;

public:
    PaperBook(
        int id,
        std::string title,
        std::string author,
        float price,
        int amount,
        Genre genre,
        int pageCount,
        CoverType coverType,
        bool hasIllustrations
    ) : Product(id, title, author, price, amount, genre),
        pageCount(pageCount),
        coverType(coverType),
        hasIllustrations(hasIllustrations) {}

    ~PaperBook() {}

    std::string toString() const override;

    void displayInfo() const override;

    int getPageCount();
    CoverType getCoverType();
    bool getHasIllustrations();

};

#pragma once // to prevent multiple imports
#include <string>
#include "product.h"

class EBook : public Product {
private:
    float fileSizeMB;
    Format format;

public:
    EBook(
        const int& id,
        const std::string& title,
        const std::string& author,
        const float& price,
        const int& amount,
        const Genre& genre,
        const float& fileSizeMB,
        const Format& format
    ) : Product(id, title, author, price, amount, genre),
        fileSizeMB(fileSizeMB),
        format(format) {}

    ~EBook() {}

    std::string toString() const override;

    void displayInfo() const override;

    float getFileSizeMB();
    Format getFormat();

};

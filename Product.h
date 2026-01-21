#pragma once // to prevent multiple imports
#include <string>

#include "enum.h"

class Product {
protected:
    int id;
    std::string title;
    std::string author;
    float price;
    int amount;
    Genre genre;

public:
    Product(
        const int& id,
        const std::string& title,
        const std::string& author,
        const float& price,
        const int& amount,
        const Genre& genre
    );

    virtual ~Product() {}

    virtual std::string toString() const = 0;

    virtual void displayInfo() const = 0;

    void sell(const int& amountToSell);

    void restock(const int& restockAmount);

    void changePrice(const float& newPrice);

    int getId();
    std::string getTitle();
    std::string getAuthor();
    float getPrice();
    int getAmount();
    Genre getGenre();
};


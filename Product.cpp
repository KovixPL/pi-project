#include "Product.h"

Product::Product(
    const int& id,
    const std::string& title,
    const std::string& author,
    const float& price,
    const int& amount,
    const Genre& genre) :
    id(id),
    title(title),
    author(author),
    price(price),
    amount(amount),
    genre(genre) {}

void Product::sell(const int& amountToSell) {
    amount -= amountToSell;
    if (amount < 0) amount = 0;
}

void Product::restock(const int& restockAmount) {
    amount += restockAmount;
}

void Product::changePrice(const float& newPrice) {
    price = newPrice;
}

int Product::getId() {
    return id;
}

std::string Product::getTitle() {
    return title;
}

std::string Product::getAuthor() {
    return author;
}

float Product::getPrice() {
    return price;
}

int Product::getAmount() {
    return amount;
}

Genre Product::getGenre() {
    return genre;
}

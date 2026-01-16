#include "Product.h"

Product::Product(int id, std::string title, std::string author, Genre genre,
    float price, int amount) :
    id(id),
    title(title),
    author(author),
    price(price),
    amount(amount) {}

void Product::sell() {
    amount--;
}

void Product::changePrice(float newPrice) {
    price = newPrice;
}

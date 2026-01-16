#include <stdexcept>
#include <iostream>

#include "Product.h"
#include "AudioBook.h"
#include "EBook.h"
#include "PaperBook.h"
#include "LibraryMenager.h"


int main()
{
    try {
        LibraryMenager menager("db.txt");

    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

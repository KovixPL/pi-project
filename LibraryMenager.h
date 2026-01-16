#include <vector>
#include <string>
#include <memory>

#include "Product.h"

class LibraryMenager {
private:
    std::vector<Product*> products;

public:
    std::vector<std::string> splitLine(std::string line, char delimiter);

    LibraryMenager(std::string dbFile);

    void createBook(char bookType, std::vector<std::string> bookInfo);

    Genre stringToGenre(std::string strGenre);
    CoverType stringToCoverType(std::string strCover);
    Format stringToFormat(std::string strFormat);

    void saveAll();
    void readAll();
};

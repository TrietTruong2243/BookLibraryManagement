#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"
#include "EBook.h"
#include "BookDetails.h"
#include <memory>
#include <type_traits>
#include <vector>
int main() {
    Library lib;

    lib.addBook(Book("Book A", "Author X", 2020, 200, 19.99, "Fiction"));
    lib.addBook(Book("Book B", "Author Y", 2017, 300, 29.99, "Sci-Fi"));
    lib.addBook(EBook("EBook C", "Author Z", 2022, 150, 14.99, "Non-fiction", 2.5, "PDF"));

    std::cout << "All Books:\n";
    lib.printAllBooks();

    std::cout << "\nBooks newer than 5 years:\n";
    auto recent = lib.searchBook([](const Book& b) {
        return 2025 - b.getYear() <= 5;
        });

    for (const auto& b : recent) {
        b.printBookInfo();
    }

    return 0;
}

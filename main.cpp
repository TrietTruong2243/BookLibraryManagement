#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"
#include "EBook.h"
#include "BookDetails.h"
#include "BookContainer.h"
#include <memory>
#include <type_traits>
#include <vector>
int main() {
    Library lib;

    lib.addBook(Book("Book A", "Author X", 2020, 200, 19.99, "Fiction"));
    lib.addBook(Book("Book B", "Author Y", 2017, 300, 29.99, "Sci-Fi"));
    lib.addBook(EBook("EBook C", "Author Z", 2022, 150, 14.99, "Non-fiction", 2.5, "PDF"));

    ::std::cout << "All Books:" << ::std::endl;
    lib.printAllBooks();
    ::std::cout << ::std::endl;
    ::std::cout << "Books newer than 5 years:";
    ::std::cout << ::std::endl;

    auto recent = lib.searchBook([](const Book& b) {
        return 2025 - b.getYear() <= 5;
        });

    for (const auto& b : recent) {
        b.printBookInfo();
    }

    BookContainer<::std::vector<::std::shared_ptr<Book>>> vBookContainers;
    vBookContainers.addBook(::std::make_shared<Book>("Book A", "Author X", 2020, 200, 19.99, "Fiction"));

    for (const auto& b : vBookContainers.getBooks()) {
        ::std::cout << *b;
    }

    return 0;
}

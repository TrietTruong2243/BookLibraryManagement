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
    Book vBook1{ "Book A", "Author X", 2020, 200, 19.99, "Fiction" };
    Book vBook2{ "Book B", "Author Y", 2017, 300, 29.99, "Sci-Fi" };
    Book vBook3{ "EBook C", "Author Z", 2022, 150, 14.99, "Non-fiction", 2.5, "PDF"};

    lib.addBook(vBook1);
    lib.addBook(vBook2);
    lib.addBook(vBook3);

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

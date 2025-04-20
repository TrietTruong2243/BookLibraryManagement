#include "Author.h"
#include <iostream>

Author::Author(std::string name, int booksPublished)
    : name(name), booksPublished(booksPublished) {}

std::string Author::getName() const { return name; }
int Author::getBooksPublished() const { return booksPublished; }

void Author::setName(const std::string& n) { name = n; }
void Author::setBooksPublished(int b) { booksPublished = b; }

void Author::printAuthorInfo() const {
    std::cout << "Author: " << name << " | Books Published: " << booksPublished << std::endl;
}

void Author::addBookToAuthor(const Book& book) {
    books.push_back(book);
    booksPublished++;
}

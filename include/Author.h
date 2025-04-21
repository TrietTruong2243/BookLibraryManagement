#pragma once
#include <string>
#include <vector>
#include "Book.h"

class Author {
private:
    ::std::string name;
    int booksPublished;
    ::std::vector<Book> books;

public:
    Author(::std::string name, int booksPublished = 0);

    ::std::string getName() const;
    int getBooksPublished() const;

    void setName(const ::std::string&);
    void setBooksPublished(int);

    void printAuthorInfo() const;
    void addBookToAuthor(const Book&);
};
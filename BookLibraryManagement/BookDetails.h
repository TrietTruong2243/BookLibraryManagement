#pragma once
#include <string>
#include "Book.h"

struct BookDetails {
    std::string title;
    std::string author;
    double price;
    int year;

    BookDetails(const Book& book);
};
#include "BookDetails.h"

BookDetails::BookDetails(const Book& book)
    : title(book.getTitle()), author(book.getAuthor()), price(book.getPrice()), year(book.getYear()) {}

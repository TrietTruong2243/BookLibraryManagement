#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
// BookLoan
class BookLoan {
    ::std::string borrower;
    ::std::string borrowDate;
    int duration;
    ::std::vector<::std::shared_ptr<Book>> borrowedBooks;

public:
    BookLoan(::std::string br, ::std::string date, int d) : borrower(br), borrowDate(date), duration(d) {}

    void borrowBook(::std::shared_ptr<Book> book) {
        borrowedBooks.push_back(book);
    }

    double totalLoanValue() const {
        double total = 0;
        for (const auto& book : borrowedBooks)
            total += book->getPrice();
        return total;
    }
};
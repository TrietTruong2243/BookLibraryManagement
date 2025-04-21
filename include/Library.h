#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Book.h"

class Library {
private:
    ::std::vector<Book> books;

public:
    void addBook(const Book& book)
    {
        books.push_back(book);
    }
 
    template <typename Predicate>
    ::std::vector<Book> searchBook(Predicate pred) const {
        ::std::vector<Book> result;
        for (const auto& book : books) {
            if (pred(book)) {
                result.push_back(book);
            }
        }
        return result;
    }
    void removeBook(const ::std::string& title);

    void updateBookInfo(const ::std::string& title, const Book& newBook);

    void sortBooksByTitle();

    void sortBooksByYear();
    

    void sortBooksByPrice();

    void printAllBooks() const;

    double calculateTotalValue() const;
};

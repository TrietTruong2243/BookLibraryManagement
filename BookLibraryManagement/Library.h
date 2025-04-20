#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Book.h"

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }
 
    template <typename Predicate>
    std::vector<Book> searchBook(Predicate pred) const {
        std::vector<Book> result;
        for (const auto& book : books) {
            if (pred(book)) result.push_back(book);
        }
        return result;
    }

    void removeBook(const std::string& title) {
        books.erase(std::remove_if(books.begin(), books.end(),
            [&](const Book& b) { return b.getTitle() == title; }),
            books.end());
    }

    void updateBookInfo(const std::string& title, const Book& newBook) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book = newBook;
                break;
            }
        }
    }

    void sortBooksByTitle() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getTitle() < b.getTitle();
            });
    }

    void sortBooksByYear() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getYear() < b.getYear();
            });
    }

    void sortBooksByPrice() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getPrice() < b.getPrice();
            });
    }

    void printAllBooks() const {
        for (const auto& book : books) {
            std::cout << "Title: " << book.getTitle()
                << ", Author: " << book.getAuthor()
                << ", Year: " << book.getYear()
                << ", Pages: " << book.getPages()
                << ", Price: " << book.getPrice()
                << ", Genre: " << book.getGenre() << '\n';
        }
    }

    double calculateTotalValue() const {
        double total = 0.0;
        for (const auto& book : books) {
            total += book.getPrice();
        }
        return total;
    }
};

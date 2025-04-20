#pragma once
#include <iostream>
#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    int year;
    int pages;
    double price;
    std::string genre;

public:
    Book(std::string title, std::string author, int year, int pages, double price, std::string genre);

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    int getPages() const;
    double getPrice() const;
    std::string getGenre() const;

    void setTitle(const std::string&);
    void setAuthor(const std::string&);
    void setYear(int);
    void setPages(int);
    void setPrice(double);
    void setGenre(const std::string&);

    virtual void printBookInfo() const;

    bool operator<(const Book& other) const;
    bool operator>(const Book& other) const;
    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
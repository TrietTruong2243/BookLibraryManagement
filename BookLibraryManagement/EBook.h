#pragma once
#include "Book.h"

class EBook : public Book {
private:
    double fileSize;
    std::string fileFormat;

public:
    EBook(std::string title, std::string author, int year, int pages, double price, std::string genre,
        double fileSize, std::string fileFormat);

    void downloadEBook() const;
    void printBookInfo() const override;
};
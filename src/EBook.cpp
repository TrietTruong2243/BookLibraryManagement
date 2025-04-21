#include "EBook.h"
#include <iostream>

EBook::EBook(std::string title, std::string author, int year, int pages, double price, std::string genre,
    double fileSize, std::string fileFormat)
    : Book(title, author, year, pages, price, genre), fileSize(fileSize), fileFormat(fileFormat) {}

void EBook::downloadEBook() const {
    std::cout << "Downloading " << title << " in format " << fileFormat << " (" << fileSize << "MB)...\n";
}

void EBook::printBookInfo() const {
    Book::printBookInfo();
    std::cout << "[EBook] Format: " << fileFormat << ", File Size: " << fileSize << "MB" << std::endl;
}

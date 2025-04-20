#include "Book.h"

Book::Book(std::string title, std::string author, int year, int pages, double price, std::string genre)
    : title(title), author(author), year(year), pages(pages), price(price), genre(genre) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
int Book::getPages() const { return pages; }
double Book::getPrice() const { return price; }
std::string Book::getGenre() const { return genre; }

void Book::setTitle(const std::string& t) { title = t; }
void Book::setAuthor(const std::string& a) { author = a; }
void Book::setYear(int y) { year = y; }
void Book::setPages(int p) { pages = p; }
void Book::setPrice(double pr) { price = pr; }
void Book::setGenre(const std::string& g) { genre = g; }

void Book::printBookInfo() const {
    std::cout << "[Book] Title: " << title << ", Author: " << author
        << ", Year: " << year << ", Pages: " << pages
        << ", Price: $" << price << ", Genre: " << genre << std::endl;
}

bool Book::operator<(const Book& other) const {
    return price < other.price;
}

bool Book::operator>(const Book& other) const {
    return price > other.price;
}

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author;
}

bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "[Book] " << book.title << " by " << book.author
        << " | Year: " << book.year << ", Pages: " << book.pages
        << ", Price: $" << book.price << ", Genre: " << book.genre;
    return os;
}

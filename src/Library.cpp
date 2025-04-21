#include "Library.h"

// template <typename Predicate>
// ::std::vector<Book> Library::searchBook(Predicate pred) const
// {
//     ::std::vector<Book> result;
//     for (const auto &book : books)
//     {
//         if (pred(book))
//             result.push_back(book);
//     }
//     return result;
// }

void Library::removeBook(const ::std::string &title)
{
    books.erase(::std::remove_if(books.begin(), books.end(),
                                 [&](const Book &b)
                                 { return b.getTitle() == title; }),
                books.end());
}

void Library::updateBookInfo(const ::std::string &title, const Book &newBook)
{
    for (auto &book : books)
    {
        if (book.getTitle() == title)
        {
            book = newBook;
            break;
        }
    }
}

void Library::sortBooksByTitle()
{
    ::std::sort(books.begin(), books.end(), [](const Book &a, const Book &b)
                { return a.getTitle() < b.getTitle(); });
}

void Library::sortBooksByYear()
{
    ::std::sort(books.begin(), books.end(), [](const Book &a, const Book &b)
                { return a.getYear() < b.getYear(); });
}

void Library::sortBooksByPrice()
{
    ::std::sort(books.begin(), books.end(), [](const Book &a, const Book &b)
                { return a.getPrice() < b.getPrice(); });
}

void Library::printAllBooks() const
{
    for (const auto &book : books)
    {
        ::std::cout << "Title: " << book.getTitle()
                    << ", Author: " << book.getAuthor()
                    << ", Year: " << book.getYear()
                    << ", Pages: " << book.getPages()
                    << ", Price: " << book.getPrice()
                    << ", Genre: " << book.getGenre() << ::std::endl;
    }
}

double Library::calculateTotalValue() const
{
    double total = 0.0;
    for (const auto &book : books)
    {
        total += book.getPrice();
    }
    return total;
}
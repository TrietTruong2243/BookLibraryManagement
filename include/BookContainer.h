#include <vector>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
#include "Book.h"

template <typename ContainerType>
class BookContainer {
    ContainerType books;

public:
    void addBook(const typename ContainerType::value_type& book) {
        books.insert(books.end(), book);
    }

    void removeBook(const typename ContainerType::value_type& book) {
        books.erase(std::remove(books.begin(), books.end(), book), books.end());
    }

    template <typename Predicate>
    std::vector<typename ContainerType::value_type> searchBook(Predicate pred) {
        std::vector<typename ContainerType::value_type> result;
        for (auto& book : books) {
            if (pred(book)) result.push_back(book);
        }
        return result;
    }

    template <typename Compare>
    void sortBooks(Compare comp) {
        std::sort(books.begin(), books.end(), comp);
    }

    const ContainerType& getBooks() const { return books; }
};

template <>
class BookContainer<::std::vector<::std::shared_ptr<Book>>> {
    ::std::vector<::std::shared_ptr<Book>> books;

public:
    void addBook(::std::shared_ptr<Book> book) {
        books.push_back(book);
    }

    void removeBook(::std::shared_ptr<Book> book) {
        books.erase(std::remove(books.begin(), books.end(), book), books.end());
    }

    ::std::vector<::std::shared_ptr<Book>> searchBook(::std::function<bool(::std::shared_ptr<Book>)> pred) {
        ::std::vector<::std::shared_ptr<Book>> result;
        for (auto& book : books) {
            if (pred(book)) result.push_back(book);
        }
        return result;
    }

    void sortBooks(::std::function<bool(::std::shared_ptr<Book>, ::std::shared_ptr<Book>)> comp) {
        std::sort(books.begin(), books.end(), comp);
    }

    const ::std::vector<::std::shared_ptr<Book>>& getBooks() const { return books; }
};

template <>
class BookContainer<::std::map<::std::string, ::std::vector<::std::shared_ptr<Book>>>> {
    ::std::map<::std::string, ::std::vector<::std::shared_ptr<Book>>> booksByAuthor;

public:
    void addBook(::std::shared_ptr<Book> book) {
        booksByAuthor[book->getAuthor()].push_back(book);
    }

    const ::std::map<::std::string, ::std::vector<::std::shared_ptr<Book>>>& getBooks() const { return booksByAuthor; }
};

template <typename Container, typename Predicate>
std::vector<typename Container::value_type> searchBooks(const Container& c, Predicate pred) {
    std::vector<typename Container::value_type> result;
    for (auto& item : c) {
        if (pred(item)) result.push_back(item);
    }
    return result;
}

template <typename Container, typename Compare>
void sortBooks(Container& c, Compare comp) {
    std::sort(c.begin(), c.end(), comp);
}

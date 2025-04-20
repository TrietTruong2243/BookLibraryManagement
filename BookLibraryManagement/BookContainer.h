#include <vector>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
#include "Book.h"

using namespace std;

// Template chính cho các container có phương thức insert, remove, v.v.
template <typename ContainerType>
class BookContainer {
    ContainerType books;

public:
    void addBook(const typename ContainerType::value_type& book) {
        books.insert(books.end(), book);
    }

    void removeBook(const typename ContainerType::value_type& book) {
        books.erase(remove(books.begin(), books.end(), book), books.end()); // áp dụng cho vector
    }

    template <typename Predicate>
    vector<typename ContainerType::value_type> searchBook(Predicate pred) {
        vector<typename ContainerType::value_type> result;
        for (auto& book : books) {
            if (pred(book)) result.push_back(book);
        }
        return result;
    }

    template <typename Compare>
    void sortBooks(Compare comp) {
        sort(books.begin(), books.end(), comp); // áp dụng cho vector
    }

    const ContainerType& getBooks() const { return books; }
};

// Specialization cho vector<shared_ptr<Book>>
template <>
class BookContainer<vector<shared_ptr<Book>>> {
    vector<shared_ptr<Book>> books;

public:
    void addBook(shared_ptr<Book> book) {
        books.push_back(book);
    }

    void removeBook(shared_ptr<Book> book) {
        books.erase(remove(books.begin(), books.end(), book), books.end());
    }

    vector<shared_ptr<Book>> searchBook(function<bool(shared_ptr<Book>)> pred) {
        vector<shared_ptr<Book>> result;
        for (auto& book : books) {
            if (pred(book)) result.push_back(book);
        }
        return result;
    }

    void sortBooks(function<bool(shared_ptr<Book>, shared_ptr<Book>)> comp) {
        sort(books.begin(), books.end(), comp);
    }

    const vector<shared_ptr<Book>>& getBooks() const { return books; }
};

// Specialization cho map<string, vector<shared_ptr<Book>>>
template <>
class BookContainer<map<string, vector<shared_ptr<Book>>>> {
    map<string, vector<shared_ptr<Book>>> booksByAuthor;

public:
    void addBook(shared_ptr<Book> book) {
        booksByAuthor[book->getAuthor()].push_back(book);
    }

    const map<string, vector<shared_ptr<Book>>>& getBooks() const { return booksByAuthor; }
};

// Template function chung cho mọi container
template <typename Container, typename Predicate>
vector<typename Container::value_type> searchBooks(const Container& c, Predicate pred) {
    vector<typename Container::value_type> result;
    for (auto& item : c) {
        if (pred(item)) result.push_back(item);
    }
    return result;
}

template <typename Container, typename Compare>
void sortBooks(Container& c, Compare comp) {
    sort(c.begin(), c.end(), comp);
}

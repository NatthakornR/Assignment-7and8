#ifndef BOOK_H
#define BOOK_H
#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    std::string title;
    std::string author;

public:
    Book(int id, const std::string& title, const std::string& author) : LibraryItem(id), title(title), author(author) {}

    void borrowItem() override {
        if (isAvailable) {
            isAvailable = false;
            std::time_t now = std::time(nullptr);
            dueToDate = now + 28 * 24 * 60 * 60;
            std::cout << "Book '" << title << "' borrowed. Due date: " << std::ctime(&dueToDate);
        }
        else {
            std::cout << "Book '" << title << "' is not available." << std::endl;
        }
    }
};

#endif
#pragma once

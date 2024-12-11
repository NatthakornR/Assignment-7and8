#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
private:
    std::string title;
    int issueNumber;

public:
    Magazine(int id, const std::string& title, int issueNumber) : LibraryItem(id), title(title), issueNumber(issueNumber) {}

    void borrowItem() override {
        if (isAvailable) {
            isAvailable = false;
            std::time_t now = std::time(nullptr);
            dueToDate = now + 14 * 24 * 60 * 60;
            std::cout << "Magazine '" << title << "' borrowed. Due date: " << std::ctime(&dueToDate);
        }
        else {
            std::cout << "Magazine '" << title << "' is not available." << std::endl;
        }
    }
};

#endif
#pragma once

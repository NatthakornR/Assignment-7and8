#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>
#include <ctime>

class LibraryItem {
protected:
    int id;
    bool isAvailable;
    std::time_t dueToDate;

public:
    LibraryItem(int id) : id(id), isAvailable(true), dueToDate(0) {}

    virtual ~LibraryItem() = default;

    virtual void borrowItem() = 0;

    virtual void returnItem() {
        isAvailable = true;
        dueToDate = 0;
        std::cout << "Item with ID " << id << " returned." << std::endl;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    int getId() const {
        return id;
    }
};

#endif
#pragma once

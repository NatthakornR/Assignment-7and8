#ifndef IMEMBER_H
#define IMEMBER_H

#include "LibraryItem.h"
#include <vector>

class IMember {
public:
    virtual ~IMember() = default;
    virtual void borrowItem(LibraryItem* item) = 0;
    virtual void returnItem(LibraryItem* item) = 0;
    virtual void listBorrowedItems() const = 0;
};

#endif

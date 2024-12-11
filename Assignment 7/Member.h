#ifndef MEMBER_H
#define MEMBER_H

#include "IMember.h"
#include <iostream>
#include <string>

class Member : public IMember {
protected:
    std::string name;
    std::vector<LibraryItem*> borrowedItems;
    int borrowingLimit;

public:
    Member(const std::string& name, int limit) : name(name), borrowingLimit(limit) {}

    virtual ~Member() = default;

    void returnItem(LibraryItem* item) override {
        auto it = std::find(borrowedItems.begin(), borrowedItems.end(), item);
        if (it != borrowedItems.end()) {
            borrowedItems.erase(it);
            item->returnItem();
            std::cout << name << " returned item with ID: " << item->getId() << std::endl;
        }
        else {
            std::cout << "Item not found in borrowed list." << std::endl;
        }
    }

    void listBorrowedItems() const override {
        std::cout << name << "'s Borrowed Items:" << std::endl;
        for (const auto& item : borrowedItems) {
            std::cout << "- Item ID: " << item->getId() << std::endl;
        }
        if (borrowedItems.empty()) {
            std::cout << "No borrowed items." << std::endl;
        }
    }

    virtual void borrowItem(LibraryItem* item) override = 0;
};

#endif

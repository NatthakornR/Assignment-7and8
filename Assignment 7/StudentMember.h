#ifndef STUDENTMEMBER_H
#define STUDENTMEMBER_H

#include "Member.h"

class StudentMember : public Member {
public:
    StudentMember(const std::string& name) : Member(name, 3) {}

    void borrowItem(LibraryItem* item) override {
        if (borrowedItems.size() < borrowingLimit) {
            if (item->getAvailability()) {
                item->borrowItem();
                borrowedItems.push_back(item);
                std::cout << name << " borrowed item with ID: " << item->getId() << std::endl;
            }
            else {
                std::cout << "Item with ID: " << item->getId() << " is not available." << std::endl;
            }
        }
        else {
            std::cout << name << " has reached the borrowing limit." << std::endl;
        }
    }
};

#endif

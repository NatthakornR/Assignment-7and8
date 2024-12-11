#include <iostream>
#include <vector>
#include "Book.h"
#include "Magazine.h"
#include "FacultyMember.h"
#include "StudentMember.h"
#include "GuestMember.h"

int main() {
    Book book1(1, "Meaningless and Nothing", "Natthakorn");
    Magazine magazine1(2, "How To C++", 101);

    FacultyMember faculty("Mysterious Man");
    StudentMember student("Silent Patient");
    GuestMember guest("Pannawit");

    std::cout << "\nBorrowing Items:" << std::endl;
    faculty.borrowItem(&book1);
    student.borrowItem(&magazine1);
    guest.borrowItem(&book1);

    std::cout << "\nReturning Items:" << std::endl;
    faculty.returnItem(&book1);
    student.returnItem(&magazine1);

    std::cout << "\nBorrowed Items List:" << std::endl;
    faculty.listBorrowedItems();
    student.listBorrowedItems();
    guest.listBorrowedItems();

    return 0;
}

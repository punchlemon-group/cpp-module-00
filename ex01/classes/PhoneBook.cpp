#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"

void setValue(std::string dstName, std::string& dst)
{
    std::string input;
    std::cout << "Please enter " << dstName << std::endl;
    std::cin >> input;
    dst = input;
}

void PhoneBook::init() {
    i = 0;
    while (i < NUM)
        contacts[i++].init();
}

void PhoneBook::add() {
    std::string input;
    if (++i >= NUM)
        i = 0;
    setValue("first name", contacts[i].firstName);
    setValue("last name", contacts[i].lastName);
    setValue("nick name", contacts[i].nickname);
    setValue("phone number", contacts[i].phoneNumber);
    setValue("darkest secret", contacts[i].darkestSecret);
    std::cout << "The contact is added!" << std::endl;
}

void PhoneBook::search() {
    int id;
    while (true) {
        std::cout << "Please enter index of contact" << std::endl;
        std::cin >> id;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (0 <= id && id < NUM) {
            contacts[id].printContact(id);
            break ;
        }
        std::cout << "The input is not a valid value" << std::endl;
    }
}

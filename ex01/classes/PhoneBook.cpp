#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include "PhoneBook.hpp"

bool setValue(std::string dstName, char *dst) {
    std::string input;
    while (input.empty() || isAllSpaces(input)) {
        std::cout << "    Enter [" << dstName << "]: ";
        std::getline(std::cin, input);
        if (std::cin.eof() || std::cin.fail()) {
            std::cout << std::endl;
            return false;
        }
    }
    if (input.length() > MAX_STRLEN)
        input = input.substr(0, MAX_STRLEN);
    std::strncpy(dst, input.c_str(), MAX_STRLEN);
    dst[input.length()] = '\0';
    return true;
}

void PhoneBook::init() {
    i = 0;
    while (i < NUM)
        contacts[i++].init();
}

bool PhoneBook::add() {
    std::string input;
    if (++i == NUM)
        i = 0;
    if (!setValue("first name", contacts[i].firstName))
        return false;
    if (!setValue("last name", contacts[i].lastName))
        return false;
    if (!setValue("nick name", contacts[i].nickname))
        return false;
    if (!setValue("phone number", contacts[i].phoneNumber))
        return false;
    if (!setValue("darkest secret", contacts[i].darkestSecret))
        return false;
    std::cout << "The contact is added!" << std::endl;
    return true;
}

bool PhoneBook::search() {
    int id;
    while (true) {
        std::cout << "    Enter index of contact: ";
        std::cin >> id;
        if (std::cin.eof()) {
            std::cout << std::endl;
            return false;
        }
        if (std::cin.fail() || id <= 0 || NUM < id) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "    Invalid value. Please try again." << std::endl;
        }
        else {
            contacts[id - 1].printContact(id);
            break ;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

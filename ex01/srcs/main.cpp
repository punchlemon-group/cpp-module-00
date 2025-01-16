#include <iostream>
#include "PhoneBook.hpp"

bool isAllSpaces(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isspace(*it)) {
            return false;
        }
    }
    return true;
}

int main(void) {
    PhoneBook phonebook;
    std::string input;

    phonebook.init();
    while (true) {
        while (input.empty() || isAllSpaces(input)) {
            std::cout << "Enter the command: ";
            std::getline(std::cin, input);
            if (std::cin.eof() || std::cin.fail()) {
                std::cout << std::endl;
                return 1;
            }
        }
        if (input == "ADD") {
            if (!phonebook.add())
                return 1;
        }
        else if (input == "SEARCH") {
            if (!phonebook.search())
                return 1;
        }
        else if (input == "EXIT")
            break ;
        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
        input.clear();
    }
    return 0;
}

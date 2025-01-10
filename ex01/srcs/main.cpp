#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char *argv[]) {
    PhoneBook phonebook;
    std::string input;
    phonebook.init();
    while (true) {
        std::cout << "Enter the command ..." << std::endl;
        std::cin >> input;
        if (input == "ADD")
            phonebook.add();
        else if (input == "SEARCH")
            phonebook.search();
        else if (input == "EXIT")
            break ;
    }
    return (0);
}

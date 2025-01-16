#include <string>
#include <iostream>
#include <iomanip> // std::setw, std::setfill
#include "Contact.hpp"

void tenCharacterOutput(std::string output) {
    if (output.length() > 10)
        std::cout << output.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << std::setfill(' ') << output;
}

void clear_str(char *dst) {
    for (int i = 0; i < MAX_STRLEN; i++) {
        dst[i] = '\0';
    }
}

void Contact::init() {
    clear_str(firstName);
    clear_str(lastName);
    clear_str(nickname);
    clear_str(phoneNumber);
    clear_str(darkestSecret);
}

void Contact::printContact(int id) {
    std::cout
        << std::endl
        << "    |     index|first name| last name|  nickname|" << std::endl
        << "    +----------+----------+----------+----------+" << std::endl
        << "    |" << std::setw(10) << std::setfill(' ') << id;
    std::cout << "|"; tenCharacterOutput(firstName);
    std::cout << "|"; tenCharacterOutput(lastName);
    std::cout << "|"; tenCharacterOutput(nickname);
    std::cout << "|" << std::endl << std::endl;
}

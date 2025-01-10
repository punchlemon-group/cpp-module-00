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

void Contact::init() {
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::printContact(int id) {
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "|" << std::setw(10) << std::setfill(' ') << id;
    std::cout << "|"; tenCharacterOutput(firstName);
    std::cout << "|"; tenCharacterOutput(lastName);
    std::cout << "|"; tenCharacterOutput(nickname);
    std::cout << "|" << std::endl;
}

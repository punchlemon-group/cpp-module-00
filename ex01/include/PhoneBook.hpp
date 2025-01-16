#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#define NUM 8

class PhoneBook {
    private:
        int i;
        Contact contacts[NUM];
    public:
        void init();
        bool add();
        bool search();
};

bool isAllSpaces(const std::string& str);

#endif

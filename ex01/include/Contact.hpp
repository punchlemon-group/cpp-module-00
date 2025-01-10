#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <string>

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        void init();
        void printContact(int id);
};

#endif /* __CONTACAT_HPP__ */

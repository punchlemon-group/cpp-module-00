#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#define MAX_STRLEN 10
#define BUF_LEN 11
#include <string>

class Contact {
    public:
        char firstName[BUF_LEN];
        char lastName[BUF_LEN];
        char nickname[BUF_LEN];
        char phoneNumber[BUF_LEN];
        char darkestSecret[BUF_LEN];
        void init();
        void printContact(int id);
};

#endif /* __CONTACAT_HPP__ */

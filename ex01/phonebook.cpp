#include <iostream>
#include <string>
#include <iomanip> // std::setw, std::setfill
#define NUM 8

void tenCharacterOutput(std::string output) {
    if (output.length() > 10)
        std::cout << output.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << std::setfill(' ') << output;
}

void setValue(std::string dstName, std::string& dst)
{
    std::string input;
    std::cout << "Please enter " << dstName << std::endl;
    std::cin >> input;
    dst = input;
}

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        void init() {
            firstName = "";
            lastName = "";
            nickname = "";
            phoneNumber = "";
            darkestSecret = "";
        }
        void printContact(int id) {
            std::cout << "|     index|first name| last name|  nickname|" << std::endl;
            std::cout << "|" << std::setw(10) << std::setfill(' ') << id;
            std::cout << "|"; tenCharacterOutput(firstName);
            std::cout << "|"; tenCharacterOutput(lastName);
            std::cout << "|"; tenCharacterOutput(nickname);
            std::cout << "|" << std::endl;
        }
};

class PhoneBook {
    private:
        int i;
        Contact contacts[NUM];
    public:
        void init() {
            i = 0;
            while (i < NUM)
                contacts[i++].init();
        }
        void add() {
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
        void search() {
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
};

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

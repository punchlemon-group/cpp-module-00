#include <iostream>
#include <string>
#include <algorithm> // std::transform
#include <cctype>    // std::toupper

unsigned char to_upper(int c) {
    return static_cast<unsigned char>(std::toupper(c));
}

int main(int argc, char *argv[]) {
    std::string str;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
        {
            str = argv[i];
            std::transform(str.begin(), str.end(), str.begin(), to_upper);
            std::cout << str;
        }
    }
    std::cout << std::endl;
    return 0;
}

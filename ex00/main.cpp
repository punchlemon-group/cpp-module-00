#include <iostream>
#include <cctype>

int main(int argc, const char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUT AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < argc; ++i) {
            for (const char *p = argv[i]; *p; ++p) {
                std::cout << static_cast<char>(std::toupper(*p));
            }
        }
    }
    std::cout << std::endl;
}

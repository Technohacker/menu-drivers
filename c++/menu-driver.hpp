#ifndef MENU_DRIVER_H
#define MENU_DRIVER_H

#include <iostream>
#include <string>
#include <vector>

typedef void (*menu_function_t)();

struct menu_option {
    std::string message;
    menu_function_t func;
};

void _exit_program() {
    exit(0);
}

class MenuDriver {
private:
    std::vector<menu_option> menu_options;
public:
    void add_option(std::string message, menu_function_t func) {
        menu_option opt = {
            message: message,
            func: func
        };
        this->menu_options.push_back(opt);
    }

    void run() {
        int ch = 0, i;

        // Add an exit option
        this->add_option("Exit", _exit_program);

        while (1) {
            std::cout << "\n\n";
            for (i = 0; i < this->menu_options.size(); i += 1) {
                std::cout << (i + 1) << ". " << this->menu_options[i].message << "\n";
            }
            std::cout << "\nEnter choice: ";
            std::cin >> ch;

            ch -= 1;

            if (ch >= this->menu_options.size()) {
                std::cout << "Invalid choice\n\n";
            } else {
                (*this->menu_options[ch].func)();
            }
        }
    }
};

#endif
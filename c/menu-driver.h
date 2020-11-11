#ifndef MENU_DRIVER_H
#define MENU_DRIVER_H

#include <stdio.h>
#include <stdlib.h>

typedef void (*menu_function_t)();

typedef struct menu_option {
    char* message;
    menu_function_t func;
} menu_option;

typedef struct menu_driver {
    menu_option* menu_options;
    unsigned int menu_options_size;
    unsigned int menu_options_capacity;
} menu_driver;

void _exit_program() {
    exit(0);
}

menu_driver* init_menu_driver() {
    menu_driver *menu = malloc(sizeof(menu_driver));

    menu->menu_options_size = 0;
    menu->menu_options_capacity = 1;
    menu->menu_options = malloc(sizeof(menu_option) * menu->menu_options_capacity);

    return menu;
}

void add_menu_option(menu_driver* menu, char* message, menu_function_t func) {
    if (menu->menu_options_size == menu->menu_options_capacity) {
        // Resize array
        menu->menu_options_capacity *= 2;
        menu->menu_options = realloc(menu->menu_options, sizeof(menu_option) * menu->menu_options_capacity);

        if (menu->menu_options == NULL) {
            // Crash and burn
            abort();
        }
    }

    menu->menu_options[menu->menu_options_size].message = message;
    menu->menu_options[menu->menu_options_size].func = func;
    menu->menu_options_size += 1;
}

void run_menu_driver(menu_driver* menu) {
    int ch = 0, i;

    // Add an exit option
    add_menu_option(menu, "Exit", _exit_program);

    while (1) {
        printf("\n\n");
        for (i = 0; i < menu->menu_options_size; i += 1) {
            printf("%d. %s\n", (i + 1), menu->menu_options[i].message);
        }
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        ch -= 1;

        if (ch >= menu->menu_options_size) {
            printf("Invalid choice\n\n");
        } else {
            (*menu->menu_options[ch].func)();
        }
    }
}

#endif
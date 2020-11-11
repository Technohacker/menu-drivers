#include "menu-driver.h"

void example() {
    printf("Example");
}

int main() {
    menu_driver* menu;

    menu = init_menu_driver();

    add_menu_option(menu, "Example 1", example);
    add_menu_option(menu, "Example 2", example);
    add_menu_option(menu, "Example 3", example);
    add_menu_option(menu, "Example 4", example);
    add_menu_option(menu, "Example 5", example);
    add_menu_option(menu, "Example 6", example);

    run_menu_driver(menu);

    return 0;
}
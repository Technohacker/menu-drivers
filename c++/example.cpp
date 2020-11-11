#include "menu-driver.hpp"

void example() {
    printf("Example");
}

int main() {
    MenuDriver menu;
    menu.add_option("Example 1", example);
    menu.add_option("Example 2", example);
    menu.add_option("Example 3", example);
    menu.add_option("Example 4", example);
    menu.add_option("Example 5", example);
    menu.add_option("Example 6", example);

    menu.run();

    return 0;
}
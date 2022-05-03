#include <iostream>
#include <Windows.h>
#include "StudentMenu.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StudentMenu menu;
    menu.UseMenu(menu.GetMenuItems(), 6);
}

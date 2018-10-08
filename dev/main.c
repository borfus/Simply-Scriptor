#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "main.h"
#include "mouse.h"
#include "keyboard.h"

void get_resolution(int *horizontal, int *vertical)
{
    RECT desktop;
    HWND desktop_handle = GetDesktopWindow();
    GetWindowRect(desktop_handle, &desktop);

    *horizontal = desktop.right;
    *vertical = desktop.bottom;
}

void run_script()
{
    move_mouse(500, 500);
    left_click();
    right_click();
    press_backspace();
    press_function_key(1);
    press_function_key(2);
    press_function_key(3);
    press_function_key(4);
    press_function_key(5);
    press_function_key(6);
    press_function_key(7);
    press_function_key(8);
    press_function_key(9);
    press_function_key(10);
    press_function_key(11);
    press_function_key(12);
    type("`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./");
    press_tab();
    press_capslock();
    press_shift();
    press_control();
    press_alt();
    press_space();
    press_enter();
    press_escape();
    press_up();
    press_down();
    press_left();
    press_right();
}

int main()
{
    get_resolution(&resolution_width, &resolution_height);
    
    run_script();

    return 0;
}

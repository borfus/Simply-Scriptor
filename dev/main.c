#include <stdio.h>
#include <Windows.h>
#include "main.h"
#include "mouse.h"

void get_resolution(int *horizontal, int *vertical)
{
    RECT desktop;
    HWND desktop_handle = GetDesktopWindow();
    GetWindowRect(desktop_handle, &desktop);

    *horizontal = desktop.right;
    *vertical = desktop.bottom;
}

int main()
{
    get_resolution(&resolution_width, &resolution_height); 

    scroll_wheel(3);
    scroll_wheel(-3);
    move_mouse(resolution_width + 1160, 1000);

    left_click();
    double_click();
    right_click();

    left_click_hold();
    Sleep(1000);
    left_click_release();

    return 0;
}

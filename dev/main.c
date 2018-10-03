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
    move_mouse(889, 327);
    left_click();
    type("HeLlO WoRlD1234567890!@#$%^&*()`~-_=+[{]}\\|;:'\",<.>/?");
    //press_enter();
}

int main()
{
    get_resolution(&resolution_width, &resolution_height);
    
    run_script();

    return 0;
}

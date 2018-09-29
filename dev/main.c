#include <stdio.h>
#include <Windows.h>
#include "main.h"
#include "mouse.h"

int main()
{
    monitor_x = 2560;
    monitor_y = 1440;

    scroll_wheel(3);
    scroll_wheel(-3);
    move_mouse(monitor_x/2, monitor_y/2);

    return 0;
}

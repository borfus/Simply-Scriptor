#include <stdio.h>
#include <Windows.h>

#define max_coord 65535

INPUT mouse_input;

int monitor_x = 2560;
int monitor_y = 1440;

void send_mouse_input()
{
    SendInput(1, &mouse_input, sizeof(INPUT));
}

void setup_mouse_movement()
{
    mouse_input.mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
    mouse_input.mi.time = 0;
}

float calculate_coord_percentage_x(int x)
{
    return (float)x / 2560;
}

float calculate_coord_percentage_y(int y)
{
    return (float)y / 1440;
}

void set_mouse_coords(int x, int y)
{
    setup_mouse_movement();

    mouse_input.mi.dx = max_coord * calculate_coord_percentage_x(x);
    mouse_input.mi.dy = max_coord * calculate_coord_percentage_y(y);
    
    send_mouse_input();
}

int main()
{
    mouse_input.type = INPUT_MOUSE;
    set_mouse_coords(1280, 720);
    return 0;
}

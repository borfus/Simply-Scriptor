#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "mouse.h"
#include "main.h"

#define max_coord 65535
#define scroll_up WHEEL_DELTA
#define scroll_down -WHEEL_DELTA

INPUT mouse_input;

void send_mouse_input()
{
    SendInput(1, &mouse_input, sizeof(INPUT));
}

void setup_mouse_movement()
{
    mouse_input.mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
    mouse_input.type = INPUT_MOUSE;
    mouse_input.mi.time = 0;
}

void setup_mouse_wheel()
{
    mouse_input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    mouse_input.type = INPUT_MOUSE;
    mouse_input.mi.time = 0;
}

float calculate_coord_percentage_x(int x)
{
    return (float)x / (float)monitor_x;
}

float calculate_coord_percentage_y(int y)
{
    return (float)y / (float)monitor_y;
}

void move_mouse(int x, int y)
{
    setup_mouse_movement();

    mouse_input.mi.dx = max_coord * calculate_coord_percentage_x(x);
    mouse_input.mi.dy = max_coord * calculate_coord_percentage_y(y);
    
    send_mouse_input();
}

void scroll_wheel(int x)
{
    setup_mouse_wheel();

    int scroll_once;
    if (x < 0)
        scroll_once = scroll_down;
    else
        scroll_once = scroll_up;

    for (int i = 0; i < abs(x); i++)
    {
        mouse_input.mi.mouseData = scroll_once;
        send_mouse_input();
        Sleep(10);
    } 
}

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

void setup_mouse_leftclick_down()
{
    mouse_input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    mouse_input.type = INPUT_MOUSE;
    mouse_input.mi.time = 0;
}

void setup_mouse_leftclick_up()
{
    mouse_input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    mouse_input.type = INPUT_MOUSE;
    mouse_input.mi.time = 0;
}

void setup_mouse_rightclick_down()
{
    mouse_input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    mouse_input.type = INPUT_MOUSE;
    mouse_input.mi.time = 0;
}

void setup_mouse_rightclick_up()
{
    mouse_input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    mouse_input.type = INPUT_MOUSE;
    mouse_input.mi.time = 0;
}

float calculate_coord_percentage_x(int x)
{
    return (float)x / (float)resolution_width;
}

float calculate_coord_percentage_y(int y)
{
    return (float)y / (float)resolution_height;
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

void left_click()
{
    setup_mouse_leftclick_down();
    send_mouse_input();
    Sleep(10);
    setup_mouse_leftclick_up();
    send_mouse_input();
    Sleep(10);
}

void right_click()
{
    setup_mouse_rightclick_down();
    send_mouse_input();
    Sleep(10);
    setup_mouse_rightclick_up();
    send_mouse_input();
    Sleep(10);
}

void double_click()
{
    left_click();
    left_click();
}

void left_click_hold()
{
    setup_mouse_leftclick_down();
    send_mouse_input();
    Sleep(10);
}

void left_click_release()
{
    setup_mouse_leftclick_up();
    send_mouse_input();
    Sleep(10);
}

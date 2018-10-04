#include <stdio.h>
#include <string.h>
#include <Windows.h>

INPUT keyboard_input;

void send_keyboard_input()
{
    SendInput(1, &keyboard_input, sizeof(INPUT));
}

void setup_keyboard_press()
{
    keyboard_input.type = INPUT_KEYBOARD;
    keyboard_input.ki.wScan = 0;
    keyboard_input.ki.time = 0;
    keyboard_input.ki.dwExtraInfo = 0;
    keyboard_input.ki.dwFlags = 0;
}

short convert_to_keycode(char *key)
{
    CHAR converted_key;
    memcpy(&converted_key, key, sizeof(converted_key));
    return VkKeyScan(converted_key);
}

int is_non_numeric_shift_symbol(char a)
{
    if (a == '~' || a == '_' || a == '+' || a == '{' || 
        a == '}' || a == '|' || a == ':' || a == '"' || 
        a == '<' || a == '>' || a == '?')
    {
        return 1;
    }
    return 0;
}

void hold_shift()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_LSHIFT;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_shift()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_LSHIFT;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_ctrl()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_CONTROL;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_ctrl()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_CONTROL;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_alt()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_MENU;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_alt()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_MENU;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_capslock()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_CAPITAL;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_capslock()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_CAPITAL;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_tab()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_TAB;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_tab()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_TAB;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_backspace()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_BACK;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_backspace()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_BACK;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_space()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_SPACE;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_space()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_SPACE;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_up()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_UP;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_up()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_UP;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_down()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_DOWN;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_down()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_DOWN;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_left()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_LEFT;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_left()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_LEFT;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void hold_right()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_RIGHT;
    keyboard_input.ki.dwFlags = 0;
    send_keyboard_input();
}

void release_right()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_RIGHT;
    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void press_capslock()
{
    hold_capslock();
    release_capslock();
}

void press_tab()
{
    hold_tab();
    release_tab();
}

void press_backspace()
{
    hold_backspace();
    release_backspace();
}

void press_space()
{
    hold_space();
    release_space();
}

void press_up()
{
    hold_up();
    release_up();
}

void press_down()
{
    hold_down();
    release_down();
}

void press_left()
{
    hold_left();
    release_left();
}

void press_right()
{
    hold_right();
    release_right();
}

void press_escape()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_ESCAPE;
    send_keyboard_input();

    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void press_enter()
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = VK_RETURN;
    send_keyboard_input();

    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void press_key(char key)
{
    setup_keyboard_press();
    keyboard_input.ki.wVk = convert_to_keycode(&key);
    send_keyboard_input();

    keyboard_input.ki.dwFlags = KEYEVENTF_KEYUP;
    send_keyboard_input();
}

void type(char *words)
{
    for (int i = 0; i < strlen(words); i++)
    {
        if ((words[i] >= 'A' && words[i] <= 'Z') || 
           ((!isdigit(words[i]) && !isalpha(words[i])) && 
             is_non_numeric_shift_symbol(words[i])))
        {
            hold_shift();
            press_key(words[i]);
            release_shift();
        }
        else
        {
            press_key(words[i]);
        }
    }
}

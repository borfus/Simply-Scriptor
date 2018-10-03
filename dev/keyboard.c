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

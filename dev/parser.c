#include <stdio.h>
#include <string.h>
#include "main.h"
#include "mouse.h"
#include "keyboard.h"

#define fill_command(x) { #x, x }
typedef struct
{
    char *command;
    void (*command_func)();
} command;

command commands[] = 
{
    fill_command(left_click),
    fill_command(right_click),
    fill_command(double_click),
    fill_command(left_click_hold),
    fill_command(left_click_release),
    fill_command(hold_shift),
    fill_command(release_shift),
    fill_command(hold_control),
    fill_command(release_control),
    fill_command(hold_alt),
    fill_command(release_alt),
    fill_command(hold_capslock),
    fill_command(release_capslock),
    fill_command(hold_tab),
    fill_command(release_tab),
    fill_command(hold_backspace),
    fill_command(release_backspace),
    fill_command(hold_space),
    fill_command(release_space),
    fill_command(hold_up),
    fill_command(release_up),
    fill_command(hold_down),
    fill_command(release_down),
    fill_command(hold_left),
    fill_command(release_left),
    fill_command(hold_right),
    fill_command(release_right),
    fill_command(press_shift),
    fill_command(press_control),
    fill_command(press_alt),
    fill_command(press_capslock),
    fill_command(press_tab),
    fill_command(press_backspace),
    fill_command(press_space),
    fill_command(press_up),
    fill_command(press_down),
    fill_command(press_left),
    fill_command(press_right),
    fill_command(press_escape),
    fill_command(press_enter),
    { 0, 0 }
};

FILE* open_script(char *file_name)
{
    FILE* file;
    file = fopen(file_name, "r");

    if (file)
    {
        return file;
    }

    error("Error opening main script file.\nPlease check that main_script.txt is located in the same directory as Simply Scriptor.");
}

int check_command(char *command)
{
    //TODO: move_mouse(x, y)
    //TODO: scroll_wheel(x)
    //TODO: press_function_key(x)
    //TODO: press_key(x)
    //TODO: type(x)
    //TODO: wait(x)
    
    for (int i = 0; commands[i].command; i++)
    {
        if (strcmp(commands[i].command, command) == 0)
        {
            commands[i].command_func();
            return 1;
        }
    }
    return 0;
}

void run_script(FILE *script_file)
{
    char line[32];
    //TODO: loop amount
    while (fscanf(script_file, "%s\n", line) == 1)
    {
        if(!check_command(line))
        {
            error("Unknown command given. Please check main_script.txt for spelling errors.");
        }
    }
}

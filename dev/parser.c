#include <stdio.h>
#include <string.h>
#include <Windows.h>
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
    fill_command(mouse_wheel_click),
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

void grab_argument(char *command, int *x)
{
    sscanf(strchr(command, '('), "(%i)", x);
}

void grab_arguments(char *command, int *x, int *y)
{
    sscanf(strchr(command, '('), "(%i,%i)", x, y);
}

int check_command(char *command)
{
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

//TODO: really ugly; refactor this
void run_script(FILE *script_file)
{
    //TODO: loop amount
    char line[32];
    while (fscanf(script_file, "%s\n", line) == 1)
    {
        char *first_parentheses = strchr(line, '(');
        char *second_parentheses = strchr(line, ')');
        if (first_parentheses && second_parentheses)
        {
            if (strncmp(line, "move_mouse", strlen("move_mouse")) == 0 && 
               (strcmp(second_parentheses, ")\n") == 0 || strcmp(second_parentheses, ")\0") == 0))
            {
                int x;
                int y;
                grab_arguments(line, &x, &y);
                move_mouse(x, y);
                continue;
            }
            else if (strncmp(line, "scroll_wheel", strlen("scroll_wheel")) == 0 && 
                    (strcmp(second_parentheses, ")\n") == 0 || strcmp(second_parentheses, ")\0") == 0))
            {
                int x;
                grab_argument(line, &x);
                scroll_wheel(x);
                continue;
            }
            else if (strncmp(line, "press_function_key", strlen("press_function_key")) == 0 && 
                    (strcmp(second_parentheses, ")\n") == 0 || strcmp(second_parentheses, ")\0") == 0))
            {
                int x;
                grab_argument(line, &x);
                press_function_key(x);
                continue;
            }
            else if (strncmp(line, "type", strlen("type")) == 0 && 
                    (strcmp(line + strlen(line)-1, ")\n") == 0 || strcmp(line + strlen(line)-1, ")\0") == 0))
            {
                char x[1024];
                sscanf(first_parentheses, "(%1023s)", x);
                x[strlen(x)-1] = '\0';
                type(x);
                continue;
            }
            else if (strncmp(line, "wait", strlen("wait")) == 0 && 
                    (strcmp(second_parentheses, ")\n") == 0 || strcmp(second_parentheses, ")\0") == 0))
            {
                int x;
                grab_argument(line, &x);
                Sleep(x);
                continue;
            }
            else if (!check_command(line))
            {
                error("Unknown command given. Please check main_script.txt for spelling errors.");
            }
        }
        else if (!check_command(line))
        {
            error("Unknown command given. Please check main_script.txt for spelling errors.");
        }
    }
}

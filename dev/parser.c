#include <stdio.h>
#include <string.h>
#include "main.h"
#include "mouse.h"
#include "keyboard.h"

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

void check_command(char *command)
{
    //TODO: finish all commands
    if (!strcmp(command, "left_click"))
    {
        printf("%s\n", command);
    }
    else
    {
        error("Unknown command given. Please check main_script.txt for spelling errors.");
    }
}

void run_script(FILE *script_file)
{
    char line[32];
    while (fscanf(script_file, "%s\n", line) == 1)
    {
        check_command(line);
    }
}

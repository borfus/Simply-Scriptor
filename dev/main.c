#include <stdio.h>
#include <Windows.h>
#include <errno.h>
#include "main.h"
#include "parser.h"

void error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void get_resolution(int *horizontal, int *vertical)
{
    RECT desktop;
    HWND desktop_handle = GetDesktopWindow();
    GetWindowRect(desktop_handle, &desktop);

    *horizontal = desktop.right;
    *vertical = desktop.bottom;
}

int main()
{
    get_resolution(&resolution_width, &resolution_height);
    
    FILE *main_script = open_script("main_script.txt");
    run_script(main_script);
    
    fclose(main_script);
    return 0;
}

# Simply Scriptor
Simply Scriptor is a lightweight, portable, all-purpose scripting program for Windows. Simply Scriptor reads a list of commands from a text file and executes mouse and keyboard inputs based on the commands given.

<img src="https://i.imgur.com/H5T43l2.gif" width="600" height="400" />

## Instructions

Fill out the main_script.txt file with commands and run Simply Scriptor. Make sure they are in the same directory! You can use [Mouse Recorder](https://github.com/borfus/Simply-Scriptor-Mouse-Recorder) to help generate mouse commands.

Commands will be executed until the program doesn't recognize a command (through typos or otherwise) or until it reaches the end.

Simply Scriptor doesn't need to run through a command prompt or a bash shell to work, but if you want to see descriptive error text then you will still need to do so.

## Building

Simply use gcc:
`gcc main.c mouse.c keyboard.c parser.c -o "Simply Scriptor"`

Or if you prefer, CMake:
`mkdir build && cd build && cmake .. && make`

## Commands

```
Mouse Commands:

move_mouse(x,y)		  // Top Left of screen is 0,0. Use Mouse Recorder to make this easier.
scroll_wheel(x) 	  // Positive number scrolls up and negative number scrolls down.
left_click
mouse_wheel_click
right_click
double_click
left_click_hold
left_click_release

Keyboard Commands:

hold_shift
release_shift
hold_control
release_control
hold_alt
release_alt
hold_capslock
release_capslock
hold_tab
release_tab
hold_backspace
release_backspace
hold_space
release_space
hold_up
release_up
hold_down
release_down
hold_left
release_left
hold_right
release_right
press_shift
press_control
press_alt
press_capslock
press_tab
press_backspace
press_space
press_up
press_down
press_left
press_right
press_escape
press_enter
press_function_key(x) // 1 - 12
type(x)               // press any button you can normally 'type' with. Example: type(HelloWorld!)
		      // WARNING: Do not use a space here. If you want to press the spacebar use 
		      // the "press_space" command instead.

Other Commands:
wait(x)               // Wait for x amount of miliseconds (Identical to Sleep(x) used from Windows.h)
```

## Disclaimer

I do not condone cheating or any other malicious purpose this program might be used for. I am not responsible for your actions! Thank you!

cmake_minimum_required(VERSION 3.6)
project(simply_scriptor)
add_executable(simply_scriptor main.c mouse.c keyboard.c parser.c)
install(TARGETS simply_scriptor DESTINATION bin)
set_target_properties(simply_scriptor PROPERTIES OUTPUT_NAME "Simply Scriptor")

cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)
project(sim800-example)
set(CMAKE_C_STANDARD 11)
pico_sdk_init()

add_executable(sim800
        src/main.c
	src/sim800l.c
        )

target_include_directories(sim800
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/../
        ${PROJECT_SOURCE_DIR}/lib
)
target_link_libraries(sim800 PUBLIC pico_stdlib hardware_uart hardware_gpio)

pico_enable_stdio_usb(sim800 0) 
pico_enable_stdio_uart(sim800 1) 

# create map/bin/hex file etc.
pico_add_extra_outputs(sim800)


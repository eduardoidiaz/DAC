# cmake version
cmake_minimum_required(VERSION 3.13)

# include the sdk.cmake file
include(pico_sdk_import.cmake)

# give the project a name (anything you want)
project(DAC C CXX ASM)

# initialize the sdk
pico_sdk_init()

add_executable(DAC)

pico_enable_stdio_usb(DAC 1)
pico_enable_stdio_uart(DAC 0)

# must match with executable name and source file names
target_sources(DAC PRIVATE dac.c)

# must match with executable name
target_link_libraries(DAC PRIVATE pico_stdio pico_stdlib pico_bootsel_via_double_reset)

# must match with executable name
pico_add_extra_outputs(DAC)
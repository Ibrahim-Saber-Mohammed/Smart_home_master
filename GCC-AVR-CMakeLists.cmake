cmake_minimum_required(VERSION 3.27)

set(CMAKE_SYSTEM_NAME GENERIC)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_CROSSCOMPILING ON)

set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C- Compiler" FORCE)
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ Compiler" FORCE)
set(CMAKE_ASM_COMPILER avr-as CACHE STRING "Assembley Compiler" FORCE)
set(CMAKE_AR avr-ar CACHE STRING "ar Compiler" FORCE)
set(CMAKE_OBJCOPY avr-objcopy CACHE STRING "object copy" FORCE)
set(CMAKE_OBJDUMB avr-objdumb CACHE STRING "object dumb" FORCE)
set(CMAKE_SIZE avr-size CACHE STRING "avr-size" FORCE)

set(CPU_PARAMETERS 
    -mmcu=atmega32 
    -DF_CPU=8000000UL
    )

set(COMPILE_FEATURES 
    ${CPU_PARAMETERS}
    -Wall
    -O1 
    -ggdb # Debugging $<$<CONFIG:Debug>:-Og -g3 -ggdb>
    )

set(LINKER_OPTIONS
    ${CPU_PARAMETERS}
    -Wl,--start-group
    -lc
    -lm
    -Wl,--end-group
    )
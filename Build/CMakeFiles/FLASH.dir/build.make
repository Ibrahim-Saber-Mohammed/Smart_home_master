# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = K:\GitHub_Repos\Smart_home_master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = K:\GitHub_Repos\Smart_home_master\Build

# Utility rule file for FLASH.

# Include any custom commands dependencies for this target.
include CMakeFiles/FLASH.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FLASH.dir/progress.make

CMakeFiles/FLASH: SMART_HOME_MASTER.elf
	avr-objcopy -j .text -j .data -O ihex SMART_HOME_MASTER.elf SMART_HOME_MASTER.hex

FLASH: CMakeFiles/FLASH
FLASH: CMakeFiles/FLASH.dir/build.make
.PHONY : FLASH

# Rule to build all files generated by this target.
CMakeFiles/FLASH.dir/build: FLASH
.PHONY : CMakeFiles/FLASH.dir/build

CMakeFiles/FLASH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FLASH.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FLASH.dir/clean

CMakeFiles/FLASH.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" K:\GitHub_Repos\Smart_home_master K:\GitHub_Repos\Smart_home_master K:\GitHub_Repos\Smart_home_master\Build K:\GitHub_Repos\Smart_home_master\Build K:\GitHub_Repos\Smart_home_master\Build\CMakeFiles\FLASH.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FLASH.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nansmaurel/CLionProjects/my_sql

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_sql.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_sql.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_sql.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_sql.dir/flags.make

CMakeFiles/my_sql.dir/main.c.o: CMakeFiles/my_sql.dir/flags.make
CMakeFiles/my_sql.dir/main.c.o: /Users/nansmaurel/CLionProjects/my_sql/main.c
CMakeFiles/my_sql.dir/main.c.o: CMakeFiles/my_sql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_sql.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_sql.dir/main.c.o -MF CMakeFiles/my_sql.dir/main.c.o.d -o CMakeFiles/my_sql.dir/main.c.o -c /Users/nansmaurel/CLionProjects/my_sql/main.c

CMakeFiles/my_sql.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sql.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nansmaurel/CLionProjects/my_sql/main.c > CMakeFiles/my_sql.dir/main.c.i

CMakeFiles/my_sql.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sql.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nansmaurel/CLionProjects/my_sql/main.c -o CMakeFiles/my_sql.dir/main.c.s

CMakeFiles/my_sql.dir/print/flags.c.o: CMakeFiles/my_sql.dir/flags.make
CMakeFiles/my_sql.dir/print/flags.c.o: /Users/nansmaurel/CLionProjects/my_sql/print/flags.c
CMakeFiles/my_sql.dir/print/flags.c.o: CMakeFiles/my_sql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/my_sql.dir/print/flags.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_sql.dir/print/flags.c.o -MF CMakeFiles/my_sql.dir/print/flags.c.o.d -o CMakeFiles/my_sql.dir/print/flags.c.o -c /Users/nansmaurel/CLionProjects/my_sql/print/flags.c

CMakeFiles/my_sql.dir/print/flags.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sql.dir/print/flags.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nansmaurel/CLionProjects/my_sql/print/flags.c > CMakeFiles/my_sql.dir/print/flags.c.i

CMakeFiles/my_sql.dir/print/flags.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sql.dir/print/flags.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nansmaurel/CLionProjects/my_sql/print/flags.c -o CMakeFiles/my_sql.dir/print/flags.c.s

CMakeFiles/my_sql.dir/print/my_printers.c.o: CMakeFiles/my_sql.dir/flags.make
CMakeFiles/my_sql.dir/print/my_printers.c.o: /Users/nansmaurel/CLionProjects/my_sql/print/my_printers.c
CMakeFiles/my_sql.dir/print/my_printers.c.o: CMakeFiles/my_sql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/my_sql.dir/print/my_printers.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_sql.dir/print/my_printers.c.o -MF CMakeFiles/my_sql.dir/print/my_printers.c.o.d -o CMakeFiles/my_sql.dir/print/my_printers.c.o -c /Users/nansmaurel/CLionProjects/my_sql/print/my_printers.c

CMakeFiles/my_sql.dir/print/my_printers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sql.dir/print/my_printers.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nansmaurel/CLionProjects/my_sql/print/my_printers.c > CMakeFiles/my_sql.dir/print/my_printers.c.i

CMakeFiles/my_sql.dir/print/my_printers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sql.dir/print/my_printers.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nansmaurel/CLionProjects/my_sql/print/my_printers.c -o CMakeFiles/my_sql.dir/print/my_printers.c.s

CMakeFiles/my_sql.dir/print/my_printf.c.o: CMakeFiles/my_sql.dir/flags.make
CMakeFiles/my_sql.dir/print/my_printf.c.o: /Users/nansmaurel/CLionProjects/my_sql/print/my_printf.c
CMakeFiles/my_sql.dir/print/my_printf.c.o: CMakeFiles/my_sql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/my_sql.dir/print/my_printf.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_sql.dir/print/my_printf.c.o -MF CMakeFiles/my_sql.dir/print/my_printf.c.o.d -o CMakeFiles/my_sql.dir/print/my_printf.c.o -c /Users/nansmaurel/CLionProjects/my_sql/print/my_printf.c

CMakeFiles/my_sql.dir/print/my_printf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sql.dir/print/my_printf.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nansmaurel/CLionProjects/my_sql/print/my_printf.c > CMakeFiles/my_sql.dir/print/my_printf.c.i

CMakeFiles/my_sql.dir/print/my_printf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sql.dir/print/my_printf.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nansmaurel/CLionProjects/my_sql/print/my_printf.c -o CMakeFiles/my_sql.dir/print/my_printf.c.s

CMakeFiles/my_sql.dir/utils/get_next_line.c.o: CMakeFiles/my_sql.dir/flags.make
CMakeFiles/my_sql.dir/utils/get_next_line.c.o: /Users/nansmaurel/CLionProjects/my_sql/utils/get_next_line.c
CMakeFiles/my_sql.dir/utils/get_next_line.c.o: CMakeFiles/my_sql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/my_sql.dir/utils/get_next_line.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_sql.dir/utils/get_next_line.c.o -MF CMakeFiles/my_sql.dir/utils/get_next_line.c.o.d -o CMakeFiles/my_sql.dir/utils/get_next_line.c.o -c /Users/nansmaurel/CLionProjects/my_sql/utils/get_next_line.c

CMakeFiles/my_sql.dir/utils/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sql.dir/utils/get_next_line.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nansmaurel/CLionProjects/my_sql/utils/get_next_line.c > CMakeFiles/my_sql.dir/utils/get_next_line.c.i

CMakeFiles/my_sql.dir/utils/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sql.dir/utils/get_next_line.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nansmaurel/CLionProjects/my_sql/utils/get_next_line.c -o CMakeFiles/my_sql.dir/utils/get_next_line.c.s

CMakeFiles/my_sql.dir/utils/utils.c.o: CMakeFiles/my_sql.dir/flags.make
CMakeFiles/my_sql.dir/utils/utils.c.o: /Users/nansmaurel/CLionProjects/my_sql/utils/utils.c
CMakeFiles/my_sql.dir/utils/utils.c.o: CMakeFiles/my_sql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/my_sql.dir/utils/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_sql.dir/utils/utils.c.o -MF CMakeFiles/my_sql.dir/utils/utils.c.o.d -o CMakeFiles/my_sql.dir/utils/utils.c.o -c /Users/nansmaurel/CLionProjects/my_sql/utils/utils.c

CMakeFiles/my_sql.dir/utils/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sql.dir/utils/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nansmaurel/CLionProjects/my_sql/utils/utils.c > CMakeFiles/my_sql.dir/utils/utils.c.i

CMakeFiles/my_sql.dir/utils/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sql.dir/utils/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nansmaurel/CLionProjects/my_sql/utils/utils.c -o CMakeFiles/my_sql.dir/utils/utils.c.s

CMakeFiles/my_sql.dir/csv_manager.c.o: CMakeFiles/my_sql.dir/flags.make
CMakeFiles/my_sql.dir/csv_manager.c.o: /Users/nansmaurel/CLionProjects/my_sql/csv_manager.c
CMakeFiles/my_sql.dir/csv_manager.c.o: CMakeFiles/my_sql.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/my_sql.dir/csv_manager.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_sql.dir/csv_manager.c.o -MF CMakeFiles/my_sql.dir/csv_manager.c.o.d -o CMakeFiles/my_sql.dir/csv_manager.c.o -c /Users/nansmaurel/CLionProjects/my_sql/csv_manager.c

CMakeFiles/my_sql.dir/csv_manager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_sql.dir/csv_manager.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nansmaurel/CLionProjects/my_sql/csv_manager.c > CMakeFiles/my_sql.dir/csv_manager.c.i

CMakeFiles/my_sql.dir/csv_manager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_sql.dir/csv_manager.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nansmaurel/CLionProjects/my_sql/csv_manager.c -o CMakeFiles/my_sql.dir/csv_manager.c.s

# Object files for target my_sql
my_sql_OBJECTS = \
"CMakeFiles/my_sql.dir/main.c.o" \
"CMakeFiles/my_sql.dir/print/flags.c.o" \
"CMakeFiles/my_sql.dir/print/my_printers.c.o" \
"CMakeFiles/my_sql.dir/print/my_printf.c.o" \
"CMakeFiles/my_sql.dir/utils/get_next_line.c.o" \
"CMakeFiles/my_sql.dir/utils/utils.c.o" \
"CMakeFiles/my_sql.dir/csv_manager.c.o"

# External object files for target my_sql
my_sql_EXTERNAL_OBJECTS =

my_sql: CMakeFiles/my_sql.dir/main.c.o
my_sql: CMakeFiles/my_sql.dir/print/flags.c.o
my_sql: CMakeFiles/my_sql.dir/print/my_printers.c.o
my_sql: CMakeFiles/my_sql.dir/print/my_printf.c.o
my_sql: CMakeFiles/my_sql.dir/utils/get_next_line.c.o
my_sql: CMakeFiles/my_sql.dir/utils/utils.c.o
my_sql: CMakeFiles/my_sql.dir/csv_manager.c.o
my_sql: CMakeFiles/my_sql.dir/build.make
my_sql: CMakeFiles/my_sql.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable my_sql"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_sql.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_sql.dir/build: my_sql
.PHONY : CMakeFiles/my_sql.dir/build

CMakeFiles/my_sql.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_sql.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_sql.dir/clean

CMakeFiles/my_sql.dir/depend:
	cd /Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nansmaurel/CLionProjects/my_sql /Users/nansmaurel/CLionProjects/my_sql /Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug /Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug /Users/nansmaurel/CLionProjects/my_sql/cmake-build-debug/CMakeFiles/my_sql.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_sql.dir/depend


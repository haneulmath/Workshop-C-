# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build"

# Include any dependencies generated for this target.
include CMakeFiles/22-vortex.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/22-vortex.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/22-vortex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/22-vortex.dir/flags.make

CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o: CMakeFiles/22-vortex.dir/flags.make
CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o: /Users/matheopalazzolo/Documents/IMAC/Prog\ &\ Algo/Workshop/src/22-vortex.cpp
CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o: CMakeFiles/22-vortex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o -MF CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o.d -o CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o -c "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/src/22-vortex.cpp"

CMakeFiles/22-vortex.dir/src/22-vortex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/22-vortex.dir/src/22-vortex.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/src/22-vortex.cpp" > CMakeFiles/22-vortex.dir/src/22-vortex.cpp.i

CMakeFiles/22-vortex.dir/src/22-vortex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/22-vortex.dir/src/22-vortex.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/src/22-vortex.cpp" -o CMakeFiles/22-vortex.dir/src/22-vortex.cpp.s

CMakeFiles/22-vortex.dir/lib/random.cpp.o: CMakeFiles/22-vortex.dir/flags.make
CMakeFiles/22-vortex.dir/lib/random.cpp.o: /Users/matheopalazzolo/Documents/IMAC/Prog\ &\ Algo/Workshop/lib/random.cpp
CMakeFiles/22-vortex.dir/lib/random.cpp.o: CMakeFiles/22-vortex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/22-vortex.dir/lib/random.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/22-vortex.dir/lib/random.cpp.o -MF CMakeFiles/22-vortex.dir/lib/random.cpp.o.d -o CMakeFiles/22-vortex.dir/lib/random.cpp.o -c "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/lib/random.cpp"

CMakeFiles/22-vortex.dir/lib/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/22-vortex.dir/lib/random.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/lib/random.cpp" > CMakeFiles/22-vortex.dir/lib/random.cpp.i

CMakeFiles/22-vortex.dir/lib/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/22-vortex.dir/lib/random.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/lib/random.cpp" -o CMakeFiles/22-vortex.dir/lib/random.cpp.s

# Object files for target 22-vortex
22__vortex_OBJECTS = \
"CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o" \
"CMakeFiles/22-vortex.dir/lib/random.cpp.o"

# External object files for target 22-vortex
22__vortex_EXTERNAL_OBJECTS =

22-vortex: CMakeFiles/22-vortex.dir/src/22-vortex.cpp.o
22-vortex: CMakeFiles/22-vortex.dir/lib/random.cpp.o
22-vortex: CMakeFiles/22-vortex.dir/build.make
22-vortex: lib/sil/libsil.a
22-vortex: lib/sil/lib/img/libimg.a
22-vortex: lib/sil/lib/img/libstb_image.a
22-vortex: CMakeFiles/22-vortex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 22-vortex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/22-vortex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/22-vortex.dir/build: 22-vortex
.PHONY : CMakeFiles/22-vortex.dir/build

CMakeFiles/22-vortex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/22-vortex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/22-vortex.dir/clean

CMakeFiles/22-vortex.dir/depend:
	cd "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles/22-vortex.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/22-vortex.dir/depend

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
include CMakeFiles/03-noir-et-blanc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/03-noir-et-blanc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/03-noir-et-blanc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/03-noir-et-blanc.dir/flags.make

CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o: CMakeFiles/03-noir-et-blanc.dir/flags.make
CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o: /Users/matheopalazzolo/Documents/IMAC/Prog\ &\ Algo/Workshop/src/03-noir-et-blanc.cpp
CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o: CMakeFiles/03-noir-et-blanc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o -MF CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o.d -o CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o -c "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/src/03-noir-et-blanc.cpp"

CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/src/03-noir-et-blanc.cpp" > CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.i

CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/src/03-noir-et-blanc.cpp" -o CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.s

CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o: CMakeFiles/03-noir-et-blanc.dir/flags.make
CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o: /Users/matheopalazzolo/Documents/IMAC/Prog\ &\ Algo/Workshop/lib/random.cpp
CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o: CMakeFiles/03-noir-et-blanc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o -MF CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o.d -o CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o -c "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/lib/random.cpp"

CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/lib/random.cpp" > CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.i

CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/lib/random.cpp" -o CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.s

# Object files for target 03-noir-et-blanc
03__noir__et__blanc_OBJECTS = \
"CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o" \
"CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o"

# External object files for target 03-noir-et-blanc
03__noir__et__blanc_EXTERNAL_OBJECTS =

03-noir-et-blanc: CMakeFiles/03-noir-et-blanc.dir/src/03-noir-et-blanc.cpp.o
03-noir-et-blanc: CMakeFiles/03-noir-et-blanc.dir/lib/random.cpp.o
03-noir-et-blanc: CMakeFiles/03-noir-et-blanc.dir/build.make
03-noir-et-blanc: lib/sil/libsil.a
03-noir-et-blanc: lib/sil/lib/img/libimg.a
03-noir-et-blanc: lib/sil/lib/img/libstb_image.a
03-noir-et-blanc: CMakeFiles/03-noir-et-blanc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 03-noir-et-blanc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/03-noir-et-blanc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/03-noir-et-blanc.dir/build: 03-noir-et-blanc
.PHONY : CMakeFiles/03-noir-et-blanc.dir/build

CMakeFiles/03-noir-et-blanc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/03-noir-et-blanc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/03-noir-et-blanc.dir/clean

CMakeFiles/03-noir-et-blanc.dir/depend:
	cd "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build" "/Users/matheopalazzolo/Documents/IMAC/Prog & Algo/Workshop/build/CMakeFiles/03-noir-et-blanc.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/03-noir-et-blanc.dir/depend


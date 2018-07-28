# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/evggenshch/cmake-3.12.0-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/evggenshch/cmake-3.12.0-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/bin

# Utility rule file for lint.

# Include the progress variables for this target.
include CMakeFiles/lint.dir/progress.make

CMakeFiles/lint: ../tasks/include/game_rt_loop.h
CMakeFiles/lint: ../tasks/include/game_tb_loop.h
CMakeFiles/lint: ../tasks/include/level_system.h
CMakeFiles/lint: ../tasks/include/movement_system.h
CMakeFiles/lint: ../tasks/include/player.h
CMakeFiles/lint: ../tasks/include/position_component.h
CMakeFiles/lint: ../tasks/include/render_system.h
CMakeFiles/lint: ../tasks/include/spawn_system.h
CMakeFiles/lint: ../tasks/include/stats_system.h
CMakeFiles/lint: ../tasks/include/world.h
CMakeFiles/lint: ../tasks/src/game_rt_loop.cpp
CMakeFiles/lint: ../tasks/src/game_tb_loop.cpp
CMakeFiles/lint: ../tasks/src/level_system.cpp
CMakeFiles/lint: ../tasks/src/main.cpp
CMakeFiles/lint: ../tasks/src/movement_system.cpp
CMakeFiles/lint: ../tasks/src/player.cpp
CMakeFiles/lint: ../tasks/src/position_component.cpp
CMakeFiles/lint: ../tasks/src/render_system.cpp
CMakeFiles/lint: ../tasks/src/spawn_system.cpp
CMakeFiles/lint: ../tasks/src/stats_system.cpp
CMakeFiles/lint: ../tasks/src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linting lint"
	/home/evggenshch/cmake-3.12.0-Linux-x86_64/bin/cmake -E chdir /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game /usr/bin/python /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/misc/cpplint/cpplint.py --filter=-whitespace/ending_newline,-build/namespaces,-build/header_guard,-readability/todo,-readability/namespace,-legal/copyright, --counting=detailed --linelength=120 /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/game_rt_loop.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/game_tb_loop.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/level_system.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/movement_system.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/player.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/position_component.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/render_system.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/spawn_system.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/stats_system.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/include/world.h /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/game_rt_loop.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/game_tb_loop.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/level_system.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/main.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/movement_system.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/player.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/position_component.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/render_system.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/spawn_system.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/stats_system.cpp /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/tasks/src/world.cpp

lint: CMakeFiles/lint
lint: CMakeFiles/lint.dir/build.make

.PHONY : lint

# Rule to build all files generated by this target.
CMakeFiles/lint.dir/build: lint

.PHONY : CMakeFiles/lint.dir/build

CMakeFiles/lint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lint.dir/clean

CMakeFiles/lint.dir/depend:
	cd /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/bin /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/bin /home/evggenshch/7bits_SummerSchool/evgenij-scherbakov-game/bin/CMakeFiles/lint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lint.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /Applications/cmake-build/bin/cmake

# The command to remove a file.
RM = /Applications/cmake-build/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ixl/Desktop/Code/Geant4/Lead

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ixl/Desktop/Code/Geant4/Lead/build

# Include any dependencies generated for this target.
include CMakeFiles/lead.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lead.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lead.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lead.dir/flags.make

CMakeFiles/lead.dir/lead.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/lead.cc.o: ../lead.cc
CMakeFiles/lead.dir/lead.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lead.dir/lead.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/lead.cc.o -MF CMakeFiles/lead.dir/lead.cc.o.d -o CMakeFiles/lead.dir/lead.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/lead.cc

CMakeFiles/lead.dir/lead.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/lead.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/lead.cc > CMakeFiles/lead.dir/lead.cc.i

CMakeFiles/lead.dir/lead.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/lead.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/lead.cc -o CMakeFiles/lead.dir/lead.cc.s

CMakeFiles/lead.dir/src/ActionInitialization.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/ActionInitialization.cc.o: ../src/ActionInitialization.cc
CMakeFiles/lead.dir/src/ActionInitialization.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lead.dir/src/ActionInitialization.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/ActionInitialization.cc.o -MF CMakeFiles/lead.dir/src/ActionInitialization.cc.o.d -o CMakeFiles/lead.dir/src/ActionInitialization.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/ActionInitialization.cc

CMakeFiles/lead.dir/src/ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/ActionInitialization.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/ActionInitialization.cc > CMakeFiles/lead.dir/src/ActionInitialization.cc.i

CMakeFiles/lead.dir/src/ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/ActionInitialization.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/ActionInitialization.cc -o CMakeFiles/lead.dir/src/ActionInitialization.cc.s

CMakeFiles/lead.dir/src/DetectorConstruction.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/DetectorConstruction.cc.o: ../src/DetectorConstruction.cc
CMakeFiles/lead.dir/src/DetectorConstruction.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lead.dir/src/DetectorConstruction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/DetectorConstruction.cc.o -MF CMakeFiles/lead.dir/src/DetectorConstruction.cc.o.d -o CMakeFiles/lead.dir/src/DetectorConstruction.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/DetectorConstruction.cc

CMakeFiles/lead.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/DetectorConstruction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/DetectorConstruction.cc > CMakeFiles/lead.dir/src/DetectorConstruction.cc.i

CMakeFiles/lead.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/DetectorConstruction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/DetectorConstruction.cc -o CMakeFiles/lead.dir/src/DetectorConstruction.cc.s

CMakeFiles/lead.dir/src/EventAction.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/EventAction.cc.o: ../src/EventAction.cc
CMakeFiles/lead.dir/src/EventAction.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lead.dir/src/EventAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/EventAction.cc.o -MF CMakeFiles/lead.dir/src/EventAction.cc.o.d -o CMakeFiles/lead.dir/src/EventAction.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/EventAction.cc

CMakeFiles/lead.dir/src/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/EventAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/EventAction.cc > CMakeFiles/lead.dir/src/EventAction.cc.i

CMakeFiles/lead.dir/src/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/EventAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/EventAction.cc -o CMakeFiles/lead.dir/src/EventAction.cc.s

CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o: ../src/PrimaryGeneratorAction.cc
CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o -MF CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o.d -o CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/PrimaryGeneratorAction.cc

CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/PrimaryGeneratorAction.cc > CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.i

CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/PrimaryGeneratorAction.cc -o CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.s

CMakeFiles/lead.dir/src/RunAction.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/RunAction.cc.o: ../src/RunAction.cc
CMakeFiles/lead.dir/src/RunAction.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lead.dir/src/RunAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/RunAction.cc.o -MF CMakeFiles/lead.dir/src/RunAction.cc.o.d -o CMakeFiles/lead.dir/src/RunAction.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/RunAction.cc

CMakeFiles/lead.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/RunAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/RunAction.cc > CMakeFiles/lead.dir/src/RunAction.cc.i

CMakeFiles/lead.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/RunAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/RunAction.cc -o CMakeFiles/lead.dir/src/RunAction.cc.s

CMakeFiles/lead.dir/src/SteppingAction.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/SteppingAction.cc.o: ../src/SteppingAction.cc
CMakeFiles/lead.dir/src/SteppingAction.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lead.dir/src/SteppingAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/SteppingAction.cc.o -MF CMakeFiles/lead.dir/src/SteppingAction.cc.o.d -o CMakeFiles/lead.dir/src/SteppingAction.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/SteppingAction.cc

CMakeFiles/lead.dir/src/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/SteppingAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/SteppingAction.cc > CMakeFiles/lead.dir/src/SteppingAction.cc.i

CMakeFiles/lead.dir/src/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/SteppingAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/SteppingAction.cc -o CMakeFiles/lead.dir/src/SteppingAction.cc.s

CMakeFiles/lead.dir/src/Writer.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/Writer.cc.o: ../src/Writer.cc
CMakeFiles/lead.dir/src/Writer.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lead.dir/src/Writer.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/Writer.cc.o -MF CMakeFiles/lead.dir/src/Writer.cc.o.d -o CMakeFiles/lead.dir/src/Writer.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/Writer.cc

CMakeFiles/lead.dir/src/Writer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/Writer.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/Writer.cc > CMakeFiles/lead.dir/src/Writer.cc.i

CMakeFiles/lead.dir/src/Writer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/Writer.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/Writer.cc -o CMakeFiles/lead.dir/src/Writer.cc.s

CMakeFiles/lead.dir/src/gaussfit.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/gaussfit.cc.o: ../src/gaussfit.cc
CMakeFiles/lead.dir/src/gaussfit.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/lead.dir/src/gaussfit.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/gaussfit.cc.o -MF CMakeFiles/lead.dir/src/gaussfit.cc.o.d -o CMakeFiles/lead.dir/src/gaussfit.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/gaussfit.cc

CMakeFiles/lead.dir/src/gaussfit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/gaussfit.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/gaussfit.cc > CMakeFiles/lead.dir/src/gaussfit.cc.i

CMakeFiles/lead.dir/src/gaussfit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/gaussfit.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/gaussfit.cc -o CMakeFiles/lead.dir/src/gaussfit.cc.s

CMakeFiles/lead.dir/src/materialsmanager.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/materialsmanager.cc.o: ../src/materialsmanager.cc
CMakeFiles/lead.dir/src/materialsmanager.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/lead.dir/src/materialsmanager.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/materialsmanager.cc.o -MF CMakeFiles/lead.dir/src/materialsmanager.cc.o.d -o CMakeFiles/lead.dir/src/materialsmanager.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/materialsmanager.cc

CMakeFiles/lead.dir/src/materialsmanager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/materialsmanager.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/materialsmanager.cc > CMakeFiles/lead.dir/src/materialsmanager.cc.i

CMakeFiles/lead.dir/src/materialsmanager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/materialsmanager.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/materialsmanager.cc -o CMakeFiles/lead.dir/src/materialsmanager.cc.s

CMakeFiles/lead.dir/src/param.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/param.cc.o: ../src/param.cc
CMakeFiles/lead.dir/src/param.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/lead.dir/src/param.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/param.cc.o -MF CMakeFiles/lead.dir/src/param.cc.o.d -o CMakeFiles/lead.dir/src/param.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/param.cc

CMakeFiles/lead.dir/src/param.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/param.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/param.cc > CMakeFiles/lead.dir/src/param.cc.i

CMakeFiles/lead.dir/src/param.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/param.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/param.cc -o CMakeFiles/lead.dir/src/param.cc.s

CMakeFiles/lead.dir/src/physicslist.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/physicslist.cc.o: ../src/physicslist.cc
CMakeFiles/lead.dir/src/physicslist.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/lead.dir/src/physicslist.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/physicslist.cc.o -MF CMakeFiles/lead.dir/src/physicslist.cc.o.d -o CMakeFiles/lead.dir/src/physicslist.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/physicslist.cc

CMakeFiles/lead.dir/src/physicslist.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/physicslist.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/physicslist.cc > CMakeFiles/lead.dir/src/physicslist.cc.i

CMakeFiles/lead.dir/src/physicslist.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/physicslist.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/physicslist.cc -o CMakeFiles/lead.dir/src/physicslist.cc.s

CMakeFiles/lead.dir/src/pixels.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/pixels.cc.o: ../src/pixels.cc
CMakeFiles/lead.dir/src/pixels.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/lead.dir/src/pixels.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/pixels.cc.o -MF CMakeFiles/lead.dir/src/pixels.cc.o.d -o CMakeFiles/lead.dir/src/pixels.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/pixels.cc

CMakeFiles/lead.dir/src/pixels.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/pixels.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/pixels.cc > CMakeFiles/lead.dir/src/pixels.cc.i

CMakeFiles/lead.dir/src/pixels.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/pixels.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/pixels.cc -o CMakeFiles/lead.dir/src/pixels.cc.s

CMakeFiles/lead.dir/src/run.cc.o: CMakeFiles/lead.dir/flags.make
CMakeFiles/lead.dir/src/run.cc.o: ../src/run.cc
CMakeFiles/lead.dir/src/run.cc.o: CMakeFiles/lead.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/lead.dir/src/run.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lead.dir/src/run.cc.o -MF CMakeFiles/lead.dir/src/run.cc.o.d -o CMakeFiles/lead.dir/src/run.cc.o -c /Users/ixl/Desktop/Code/Geant4/Lead/src/run.cc

CMakeFiles/lead.dir/src/run.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lead.dir/src/run.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ixl/Desktop/Code/Geant4/Lead/src/run.cc > CMakeFiles/lead.dir/src/run.cc.i

CMakeFiles/lead.dir/src/run.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lead.dir/src/run.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ixl/Desktop/Code/Geant4/Lead/src/run.cc -o CMakeFiles/lead.dir/src/run.cc.s

# Object files for target lead
lead_OBJECTS = \
"CMakeFiles/lead.dir/lead.cc.o" \
"CMakeFiles/lead.dir/src/ActionInitialization.cc.o" \
"CMakeFiles/lead.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/lead.dir/src/EventAction.cc.o" \
"CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/lead.dir/src/RunAction.cc.o" \
"CMakeFiles/lead.dir/src/SteppingAction.cc.o" \
"CMakeFiles/lead.dir/src/Writer.cc.o" \
"CMakeFiles/lead.dir/src/gaussfit.cc.o" \
"CMakeFiles/lead.dir/src/materialsmanager.cc.o" \
"CMakeFiles/lead.dir/src/param.cc.o" \
"CMakeFiles/lead.dir/src/physicslist.cc.o" \
"CMakeFiles/lead.dir/src/pixels.cc.o" \
"CMakeFiles/lead.dir/src/run.cc.o"

# External object files for target lead
lead_EXTERNAL_OBJECTS =

lead: CMakeFiles/lead.dir/lead.cc.o
lead: CMakeFiles/lead.dir/src/ActionInitialization.cc.o
lead: CMakeFiles/lead.dir/src/DetectorConstruction.cc.o
lead: CMakeFiles/lead.dir/src/EventAction.cc.o
lead: CMakeFiles/lead.dir/src/PrimaryGeneratorAction.cc.o
lead: CMakeFiles/lead.dir/src/RunAction.cc.o
lead: CMakeFiles/lead.dir/src/SteppingAction.cc.o
lead: CMakeFiles/lead.dir/src/Writer.cc.o
lead: CMakeFiles/lead.dir/src/gaussfit.cc.o
lead: CMakeFiles/lead.dir/src/materialsmanager.cc.o
lead: CMakeFiles/lead.dir/src/param.cc.o
lead: CMakeFiles/lead.dir/src/physicslist.cc.o
lead: CMakeFiles/lead.dir/src/pixels.cc.o
lead: CMakeFiles/lead.dir/src/run.cc.o
lead: CMakeFiles/lead.dir/build.make
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4Tree.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4FR.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4GMocren.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4visHepRep.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4RayTracer.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4VRML.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4OpenGL.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4gl2ps.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4vis_management.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4modeling.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4interfaces.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4persistency.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4error_propagation.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4readout.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4physicslists.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4tasking.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4parmodels.dylib
lead: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
lead: /Users/ixl/opt/anaconda3/lib/libQt5OpenGL.5.9.7.dylib
lead: /Users/ixl/opt/anaconda3/lib/libQt5PrintSupport.5.9.7.dylib
lead: /Users/ixl/opt/anaconda3/lib/libQt5Widgets.5.9.7.dylib
lead: /Users/ixl/opt/anaconda3/lib/libQt5Gui.5.9.7.dylib
lead: /Users/ixl/opt/anaconda3/lib/libQt5Core.5.9.7.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4run.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4event.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4tracking.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4processes.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4analysis.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4tools.dylib
lead: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/lib/libexpat.tbd
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4digits_hits.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4track.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4particles.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4geometry.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4materials.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4zlib.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4graphics_reps.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4intercoms.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4global.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4clhep.dylib
lead: /Users/ixl/Documents/Source_Files/geant4/geant4_build/lib/libG4ptl.0.0.2.dylib
lead: CMakeFiles/lead.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable lead"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lead.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lead.dir/build: lead
.PHONY : CMakeFiles/lead.dir/build

CMakeFiles/lead.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lead.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lead.dir/clean

CMakeFiles/lead.dir/depend:
	cd /Users/ixl/Desktop/Code/Geant4/Lead/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ixl/Desktop/Code/Geant4/Lead /Users/ixl/Desktop/Code/Geant4/Lead /Users/ixl/Desktop/Code/Geant4/Lead/build /Users/ixl/Desktop/Code/Geant4/Lead/build /Users/ixl/Desktop/Code/Geant4/Lead/build/CMakeFiles/lead.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lead.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build

# Include any dependencies generated for this target.
include CMakeFiles/central.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/central.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/central.dir/flags.make

CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o: ../ipc-3.8.6/src/comServer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/comServer.c

CMakeFiles/central.dir/ipc-3.8.6/src/comServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/comServer.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/comServer.c > CMakeFiles/central.dir/ipc-3.8.6/src/comServer.i

CMakeFiles/central.dir/ipc-3.8.6/src/comServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/comServer.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/comServer.c -o CMakeFiles/central.dir/ipc-3.8.6/src/comServer.s

CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o: ../ipc-3.8.6/src/dispatch.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/dispatch.c

CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/dispatch.c > CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.i

CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/dispatch.c -o CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.s

CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o: ../ipc-3.8.6/src/msgTap.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/msgTap.c

CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/msgTap.c > CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.i

CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/msgTap.c -o CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.s

CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o: ../ipc-3.8.6/src/recvMsg.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/recvMsg.c

CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/recvMsg.c > CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.i

CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/recvMsg.c -o CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.s

CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/res.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/res.o: ../ipc-3.8.6/src/res.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/res.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/res.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/res.c

CMakeFiles/central.dir/ipc-3.8.6/src/res.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/res.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/res.c > CMakeFiles/central.dir/ipc-3.8.6/src/res.i

CMakeFiles/central.dir/ipc-3.8.6/src/res.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/res.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/res.c -o CMakeFiles/central.dir/ipc-3.8.6/src/res.s

CMakeFiles/central.dir/ipc-3.8.6/src/res.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/res.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/res.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/res.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/res.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/res.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/res.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/res.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/res.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o: ../ipc-3.8.6/src/tcerror.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/tcerror.c

CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/tcerror.c > CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.i

CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/tcerror.c -o CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.s

CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/logging.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/logging.o: ../ipc-3.8.6/src/logging.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/logging.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/logging.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/logging.c

CMakeFiles/central.dir/ipc-3.8.6/src/logging.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/logging.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/logging.c > CMakeFiles/central.dir/ipc-3.8.6/src/logging.i

CMakeFiles/central.dir/ipc-3.8.6/src/logging.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/logging.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/logging.c -o CMakeFiles/central.dir/ipc-3.8.6/src/logging.s

CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/logging.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o: ../ipc-3.8.6/src/globalS.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/globalS.c

CMakeFiles/central.dir/ipc-3.8.6/src/globalS.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/globalS.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/globalS.c > CMakeFiles/central.dir/ipc-3.8.6/src/globalS.i

CMakeFiles/central.dir/ipc-3.8.6/src/globalS.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/globalS.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/globalS.c -o CMakeFiles/central.dir/ipc-3.8.6/src/globalS.s

CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o: ../ipc-3.8.6/src/centralIO.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/centralIO.c

CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/centralIO.c > CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.i

CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/centralIO.c -o CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.s

CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o: ../ipc-3.8.6/src/globalVar.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/globalVar.c

CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/globalVar.c > CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.i

CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/globalVar.c -o CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.s

CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.provides.build

CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o: CMakeFiles/central.dir/flags.make
CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o: ../ipc-3.8.6/src/centralMain.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o   -c /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/centralMain.c

CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/centralMain.c > CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.i

CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/ipc-3.8.6/src/centralMain.c -o CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.s

CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.requires:
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.requires

CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.provides: CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.requires
	$(MAKE) -f CMakeFiles/central.dir/build.make CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.provides.build
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.provides

CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.provides.build: CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o
.PHONY : CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.provides.build

# Object files for target central
central_OBJECTS = \
"CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/res.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/logging.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o" \
"CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o"

# External object files for target central
central_EXTERNAL_OBJECTS =

../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/res.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/logging.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o
../bin/central: CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o
../bin/central: ../lib/libipc.so
../bin/central: CMakeFiles/central.dir/build.make
../bin/central: CMakeFiles/central.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/central"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/central.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/central.dir/build: ../bin/central
.PHONY : CMakeFiles/central.dir/build

CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/comServer.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/dispatch.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/msgTap.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/recvMsg.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/res.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/tcerror.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/logging.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/globalS.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/centralIO.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/globalVar.o.requires
CMakeFiles/central.dir/requires: CMakeFiles/central.dir/ipc-3.8.6/src/centralMain.o.requires
.PHONY : CMakeFiles/central.dir/requires

CMakeFiles/central.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/central.dir/cmake_clean.cmake
.PHONY : CMakeFiles/central.dir/clean

CMakeFiles/central.dir/depend:
	cd /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build /home/carlos/ros_workspace/ipc-bridge/ipc_bridge_stack/ipc/build/CMakeFiles/central.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/central.dir/depend


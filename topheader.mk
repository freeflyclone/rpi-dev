# Defines variables that help all the subdir Makefiles
# know where to find stuff, as well as project level
# build settings.
#
# Note:
#   The way TOPDIR is created here absolutely depends on
#   this file being the first include in ALL subdir
#   Makefiles, regardless of tree depth, and that each
#   subdir Makefile includes this file with a relative
#   path, which means that the deeper in the source tree
#   a Makefile is, the more "../"es are going to be
#   needed.
#-------------------------------------------------------
.PHONY: clean all

# As it's name might suggest, TOPDIR is the
# top-most directory of the madstyletv source code
# tree.  All subdir Makefiles rely on this
TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))

# A user-defined gmake function for building a program.
# It also copies it to the project's "bin" folder
PROGRAM_BUILD =$(LD) -g -o $@ $^ $(LDFLAGS) $(LIBS) ; cp $@ $(TOPDIR)bin

# substitute, 1 at a time, the source files of interest to .o files
# done this way to preserve the order the files are specified in,
# as this can be significant to the linker
FILTERED1 = $(patsubst %.cpp,%.o,$(PROGRAM_SOURCES))
FILTERED2 = $(patsubst %.c,%.o,$(FILTERED1))
FILTERED3 = $(patsubst %.s,%.o,$(FILTERED2))


PROGRAM_OBJS = $(FILTERED3)

ECHO_VARS = @echo PROGRAM_SOURCES: $(PROGRAM_SOURCES) PROGRAM_OBJS: $(PROGRAM_OBJS) 

# Change the tools to allow for cross compilation by setting CROSS_COMPILE
# to a toolchain prefix
CXX = $(CROSS_COMPILE)g++
CC = $(CROSS_COMPILE)gcc
AS = $(CROSS_COMPILE)as
AR = $(CROSS_COMPILE)ar
NM = $(CROSS_COMPILE)nm
LD = $(CROSS_COMPILE)ld
OBJDUMP = $(CROSS_COMPILE)objdump
OBJCOPY = $(CROSS_COMPILE)objcopy
RANLIB = $(CROSS_COMPILE)ranlib
STRIP = $(CROSS_COMPILE)strip


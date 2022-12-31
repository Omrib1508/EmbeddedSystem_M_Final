#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This is the second assessment in the course, it's a makefile to automate the build process
# 
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	 <file>.i    -> generates the intermediate file outputted from preprocessor from the C file, it also generates the dependecy .d file
#        <file>.asm  -> generates the assembly file from the C file
#        <file>.o    -> compiles all the source files and generates the corresponding object file
#        compile-all -> compiles all the src files without linking and generates the corresponding object files
#        build       -> links the object files into one executable file and generates the memory map of the executable 
#        clean 	     -> removes all the generated files whether .i, .o, .d, .map, .s, .out
#  
# Platform Overrides:
# This makefile supports 2 platforms: the host machine, and the MSP432 microcontroller.
# For the MSP432 we define its specific linker file (msp432p401r.lds), the CPU, architecture which are different from the case of "host" platform
#
#------------------------------------------------------------------------------

include sources.mk

#Platform Overrides
TARGET = course1

# General Flags for all platforms
GEN_FLAGS = -Wall\
	    -Werror\
	    -g\
	    -O0\
	    -std=c99

# Architectures Specific Flags
ifeq ($(PLATFORM),MSP432)
	### MPS432 platform
	CPU = cortex-m4
	ARCH = armv7e-m
	
	# Compiler
 	CC = arm-none-eabi-gcc
	
	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	
	# Linker Flags
	LINKER_FILE 	= ../msp432p401r.lds
	LDFLAGS 	= -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
	# Compiler Flags
	CFLAGS = 	$(GEN_FLAGS) \
			-mcpu=$(CPU) \
			-mthumb \
			-march=$(ARCH) \
			-mfloat-abi=hard \
			-mfpu=fpv4-sp-d16\
			--specs=nosys.specs
	CPPFLAGS = 	-DMSP432 $(INCLUDES)

else
	### Host platform
	CPU = x86_64
	ARCH:=$(shell arch)
	
	# Compiler
	CC = gcc
	
	# Compiler flags
	CFLAGS =	 $(GEN_FLAGS)
	CPPFLAGS =	 -DHOST $(INCLUDES)
	
	# Linker
	SIZE = size
endif


ifeq ($(VERBOSE), TRUE)
	CFLAGS += -DVERBOSE
endif


ifeq ($(COURSE1), TRUE)
	CFLAGS += -DCOURSE1
endif


# Perprocesssor Files
PREP:= $(SOURCES:.c=.i)
# Dependancy Files
DEPS:= $(SOURCES:.c=.d)
# Assembly Files
ASMS:= $(SOURCES:.c=.asm)
# Object Files
OBJS:= $(SOURCES:.c=.o)
# maps Files
MAPS:= $(SOURCES:.c=.map)
# Output Files
OUTS:= $(SOURCES:.c=.out)

.PHONY: compile-all build clean

# Compile all object files and link to executalbe
build: $(TARGET).out

$(TARGET).out: 	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
		$(SIZE) $@

# Generate perproccesor output files
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate assemly files and executable
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate object files and executalbe
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate dependancy fukes for each source file
%.d: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# Compile all object files, do not link them
compile-all: $(OBJS)

# Remove all compile objects, preprocessed outputs, assembly files and exectuable files.
clean:
	@echo Removing all built files
	rm -f *.out *.map *.o *.asm *.i


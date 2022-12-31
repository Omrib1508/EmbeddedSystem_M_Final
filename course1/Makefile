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
	CPPFLAGS = 	-M -MF test.d
	DEFINEFLAG =	-DMSP432

else
	### Host platform
	CPU = x86_64
	ARCH:=$(shell arch)
	
	# Compiler
	CC = gcc
	
	# Compiler flags
	CFLAGS =	$(GEN_FLAGS)
	CPPFLAGS = 	-M -MF test2.d
	DEFINEFLAG =	-DHOST
	# Linker
	SIZE = size
	LDFLAGS =	-Wl, -Map=$(TARGET).map
endif


ifeq ($(VERBOSE), TRUE)
	CFLAGS += -DVERBOSE
endif


ifeq ($(COURSE1), TRUE)
	CFLAGS += -DCOURSE1
endif


# Perprocesssor Files
PREP:= $(SOURCES:.c=.i)
# Assembly Files
ASMS:= $(SOURCES:.c=.asm)
# Object Files
OBJS:= $(SOURCES:.c=.o)
# maps Files
MAPS:= $(SOURCES:.c=.map)
# Output Files
OUTS:= $(SOURCES:.c=.out)

#------------------------------------------------------------------------------#
# #Target: <file>.i
# # Prerequisites: the .c file
# # Output: the .d as well as .i files
#------------------------------------------------------------------------------#
%.i : %.c
	$(CC) $(CPPFLAGs) $(DEFINEFLAG) $<
	$(CC) $(DEFINEFLAG) -E -o $@ $<
#$(CC) $(CPPFLAGs) -E -o $@ $< 
### -E: Stop after the preprocessing stage;
### do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output. 

#------------------------------------------------------------------------------#
# # Target: <file>.asm
# # Prerequisites: the .c file
# # Output: the .asm file whether from the .c file or the object file
#------------------------------------------------------------------------------#

%.asm : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -S $<
	objdump $(OBJS) -D
### -S: Stop after the stage of compilation proper; do not assemble.
###The output is in the form of an assembler code file for each non-assembler input file specified. 

#------------------------------------------------------------------------------#
# # Target: <file>.o
# # Prerequisites: the .c file
# # Output: the .o file corresponding to the provided .c file
#------------------------------------------------------------------------------#
%.o : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $<

#------------------------------------------------------------------------------#
# # Target: compile-all
# # Prerequisites: the source files
# # Output: all source files are compiled but without linking and their corresponding .o files are generated
#-------------------------------------------------------------------------------#
.PHONY: compile-all
compile-all: $(SOURCES)
#$(OBJS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $(SOURCES) -lm

#--------------------------------------------------------------------------------#
# # Target: build
# # Prerequisites: the main.out file
# # Output: the final executable file after linking and a brief report regarding the application size
#--------------------------------------------------------------------------------#
.PHONY: build
build: $(OUTS)
#main.out
$(OUTS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(LDFLAGS) -o course1.out $^ -lm
	size -Atd course1.out

#---------------------------------------------------------------------------------#
# # Target: clean
# # Prerequisites: None
# # Output: all generated file are removed and the directory is cleaned for a new build
#---------------------------------------------------------------------------------#
.PHONY: clean
clean:
#rm -f $(OBJS) main.out $(ASMS) $(PPS) $(MAPS)
	rm -f *.i *.d *.map *.s *.out *.o

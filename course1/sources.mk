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

ifeq ($(PLATFORM), MSP432)
	# Add your Source files to this variable
	SOURCES =	/src/*.c
	 	
	# Add your include paths to this variable
	INCLUDES = 	include/CMSIS\
			include/commom\
			include/msp432

else
	# Add your Source files to this variable
	SOURCES =       src/main.c\
			src/memory.c\
			src/data.c\
			src/stats.c\
			src/course1.c
			
	# Add your include paths to this variable
	INCLUDES =     include/common/
endif

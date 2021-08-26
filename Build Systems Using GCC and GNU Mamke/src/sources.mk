
HOSTSOURCES = main.c memory.c
MSP432SOURCES = main.c memory.c	interrupts_msp432p401r_gcc.c startup_msp432p401r_gcc.c system_msp432p401r.c

# Add your include paths to this variable
HOSTINCLUDES = -I../include/common
MSP432INCLUDES = -I../include/common -I../include/msp432 -I../include/CMSIS

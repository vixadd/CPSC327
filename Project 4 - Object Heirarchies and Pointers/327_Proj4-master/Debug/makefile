################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: 327_Proj4

dependents:
	-cd /home/keith/eclipse-workspace/327_Proj4_Lib/Debug && $(MAKE) all

# Tool invocations
327_Proj4: $(OBJS) $(USER_OBJS) /home/keith/eclipse-workspace/327_Proj4_Lib/Debug/lib327_Proj4_Lib.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/keith/eclipse-workspace/327_Proj4_Lib/Debug" -L"/home/keith/eclipse-workspace/327_Proj4_Lib" -o "327_Proj4" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) 327_Proj4
	-@echo ' '

.PHONY: all clean dependents
/home/keith/eclipse-workspace/327_Proj4_Lib/Debug/lib327_Proj4_Lib.a:

-include ../makefile.targets

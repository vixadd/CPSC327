################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Functions.cpp \
../ST_American_DonutEnthusiest.cpp \
../Smalltalk.cpp \
../Smalltalk_American.cpp \
../Smalltalk_Brit.cpp \
../Watch.cpp 

OBJS += \
./Functions.o \
./ST_American_DonutEnthusiest.o \
./Smalltalk.o \
./Smalltalk_American.o \
./Smalltalk_Brit.o \
./Watch.o 

CPP_DEPS += \
./Functions.d \
./ST_American_DonutEnthusiest.d \
./Smalltalk.d \
./Smalltalk_American.d \
./Smalltalk_Brit.d \
./Watch.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



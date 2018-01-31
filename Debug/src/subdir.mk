################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/kmbdQueues_test.cpp \
../src/kmbd_testEverything.cpp 

OBJS += \
./src/kmbdQueues_test.o \
./src/kmbd_testEverything.o 

CPP_DEPS += \
./src/kmbdQueues_test.d \
./src/kmbd_testEverything.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



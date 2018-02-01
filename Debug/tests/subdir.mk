################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/kmbdQueues_test.cpp \
../tests/kmbd_testEverything.cpp 

OBJS += \
./tests/kmbdQueues_test.o \
./tests/kmbd_testEverything.o 

CPP_DEPS += \
./tests/kmbdQueues_test.d \
./tests/kmbd_testEverything.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/home/ricky/projects/kmbd/includes -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



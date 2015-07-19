################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FollowLight.cpp 

LINK_OBJ += \
./FollowLight.cpp.o 

CPP_DEPS += \
./FollowLight.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
FollowLight.cpp.o: ../FollowLight.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/apps/arduino-1.5.5-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"C:\apps\arduino-1.5.5-r2\hardware\arduino\avr\cores\arduino" -I"C:\apps\arduino-1.5.5-r2\hardware\arduino\avr\variants\standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '



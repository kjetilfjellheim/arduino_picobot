################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AllLEDS.cpp 

LINK_OBJ += \
./AllLEDS.cpp.o 

CPP_DEPS += \
./AllLEDS.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
AllLEDS.cpp.o: ../AllLEDS.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\apps\Arduino164\hardware\tools\avr\bin\/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=164 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\apps\Arduino164\hardware\arduino\avr\cores\arduino" -I"C:\apps\Arduino164\hardware\arduino\avr\variants\standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '



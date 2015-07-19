################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
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
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
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
AR += \
D:/code/githubrepos/arduino/MoveAlongLine/Release/arduino.ar \

ELF += \
MoveAlongLine.elf \

EEP += \
MoveAlongLine.eep \

FLASH_IMAGE += \
MoveAlongLine.hex \


# All Target
all: MoveAlongLine

# Tool invocations
MoveAlongLine: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:/apps/arduino-1.5.5-r2/hardware/tools/avr/bin/avr-size" -A "D:/code/githubrepos/arduino/MoveAlongLine/Release/MoveAlongLine.elf"
	@echo 'Finished building target: $@'
	@echo ' '

D:/code/githubrepos/arduino/MoveAlongLine/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:/apps/arduino-1.5.5-r2/hardware/tools/avr/bin/avr-ar" rcs "D:/code/githubrepos/arduino/MoveAlongLine/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

MoveAlongLine.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:/apps/arduino-1.5.5-r2/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "D:/code/githubrepos/arduino/MoveAlongLine/Release/MoveAlongLine.elf"   $(LINK_OBJ) $(AR)  "D:/code/githubrepos/arduino/MoveAlongLine/Release/arduino.ar" "-LD:/code/githubrepos/arduino/MoveAlongLine/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

MoveAlongLine.eep: $(ELF)
	@echo 'Create eeprom image'
	"C:/apps/arduino-1.5.5-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "D:/code/githubrepos/arduino/MoveAlongLine/Release/MoveAlongLine.elf" "D:/code/githubrepos/arduino/MoveAlongLine/Release/MoveAlongLine.eep"
	@echo 'Finished building: $@'
	@echo ' '

MoveAlongLine.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"C:/apps/arduino-1.5.5-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "D:/code/githubrepos/arduino/MoveAlongLine/Release/MoveAlongLine.elf" "D:/code/githubrepos/arduino/MoveAlongLine/Release/MoveAlongLine.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) MoveAlongLine
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
